-module(interp).
-export([scanAndParse/1,runFile/1,runStr/1]).
-include("types.hrl").
-author("Jake Fallin").

loop(InFile,Acc) ->
    case io:request(InFile,{get_until,prompt,lexer,token,[1]}) of
        {ok,Token,_EndLine} ->
            loop(InFile,Acc ++ [Token]);
        {error,token} ->
            exit(scanning_error);
        {eof,_} ->
            Acc
    end.

scanAndParse(FileName) ->
    {ok, InFile} = file:open(FileName, [read]),
    Acc = loop(InFile,[]),
    file:close(InFile),
    {Result, AST} = parser:parse(Acc),
    case Result of 
	ok -> AST;
	_ -> io:format("Parse error~n")
    end.


-spec runFile(string()) -> valType().
runFile(FileName) ->
    valueOf(scanAndParse(FileName),env:new()).

scanAndParseString(String) ->
    {_ResultL, TKs, _L} = lexer:string(String),
    parser:parse(TKs).

-spec runStr(string()) -> valType().
runStr(String) ->
    {Result, AST} = scanAndParseString(String),
    case Result  of 
    	ok -> valueOf(AST,env:new());
    	_ -> io:format("Parse error~n")
    end.


-spec numVal2Num(numValType()) -> integer().
numVal2Num({num, N}) ->
    N.

-spec boolVal2Bool(boolValType()) -> boolean().
boolVal2Bool({bool, B}) ->
    B.

-spec valueOf(expType(),envType()) -> valType().
valueOf(Exp,Env) ->
    case Exp of

        {num, Num} -> 
            {num, Num};

        {bool, Bool} ->
            {bool, Bool};

        {numExp, {num, _, Value}} ->
            {num, Value};

        {idExp, {id, 1, Value}} ->
            env:lookup(Env, Value);

        {diffExp, Left, Right} ->  
            {num, numVal2Num(valueOf(Left, Env)) - numVal2Num(valueOf(Right, Env))};

        {plusExp, Left, Right} ->
            {num, numVal2Num(valueOf(Left, Env)) + numVal2Num(valueOf(Right, Env))};

        {isZeroExp, Number} ->
            N = numVal2Num(valueOf(Number, Env)),
                if
                    N == 0 ->
                        {bool, true};
                    true ->
                        {bool, false}
                end;

        {ifThenElseExp, Index, True, False} ->
            N = boolVal2Bool(valueOf(Index, Env)),
                if
                    N == true ->
                        valueOf(True, Env);
                    true ->
                        valueOf(False, Env)
                end;

        {letExp, {ID, 1, A}, B, C} ->
            N = env:add(Env, A, valueOf(B, Env)),
            valueOf(C, N);

        {procExp, {ID, 1, A}, B} ->
            {proc, A, B, Env};

        {appExp, ID, A} ->
            {_, ValueID, ValueExp, ValueEnv} = valueOf(ID, Env),
            B = valueOf(A, Env),
            valueOf({letExp,{id, 1, ValueID}, B, ValueExp}, ValueEnv)

    end.    



