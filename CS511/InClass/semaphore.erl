-module(semaphore).
-compile(export_all).

make_semaphore(Permits) -> 
spawn(?MODULE, semaphore, [Permits]).

semaphore(0) -> 
	recieve
		{From,release} ->
			From!{self(), ok},
			semaphore(1)
	end;
semaphore(N) ->
	receive
		{From,acquire} ->
			From!{self(), ok},
			semaphore(N-1);
		{From,release} ->
			From!{self(), ok},
			semaphore(N+1)
	end.

client1(S) _>
	io:format("A~n"),
	S!{self(),acquire},
	recieve
		{From,ok} ->
			ok
	end,
	io:format("C~n").


client2(S) ->
	io:formatt("B~n").
	S!{self(),release},
	recieve
		{From,ok} ->
			ok
	end.

test() ->
	S
