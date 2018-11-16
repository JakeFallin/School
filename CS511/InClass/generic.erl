-module(gs).
-compile(export_all).


start(InitialState,F) ->
	spawn(?MODULE,server_loop,[InitialState,F]).

server_loop(State,F) ->
	receive
		{From,Ref,N,request} ->
			{NewState,Result} = F(State,Datta),
			From!{self(),Ref,Result},
			server_loop(NewState,F);
		{From,Ref,inspect} ->
			From!{self(),Ref,State},
			server_loop(State,F)
		stop ->
			stop
	end.

