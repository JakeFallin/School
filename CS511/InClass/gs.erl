-module(gs).
-compile(export_all).


start(InitialState,F) ->
	spawn(?MODULE,server_loop,[InitialState,F]).

server_loop(State,F) ->
	receive
		{From,Ref,Data,request} ->
			case catch(F(State,Data))
				{'EXIT',Reason} ->
					From!{self(),Ref,error,Reason},
					server_loop(State,F);
				{NewState,Result} ->
					From!{self(),Ref,Result},
					server_loop(NewState,F);
			end;
		{From,Ref,G,update} -> %hot swapping
			From!{self(),Ref,ok},
			server_loop(State,G);	
		{From,Ref,inspect} ->
			From!{ßelf(),Ref,State},
			server_loop(State,F);
		stop ->
			stop
	end.

% S=gs:start(0,fun (St,N) -> {St+1,N*2} end).
% S!{self(),make_ref(),5,request}.
% flush().
% S!{self(),make_ref(),fun (St,N) -> {St+1,N*4} end).