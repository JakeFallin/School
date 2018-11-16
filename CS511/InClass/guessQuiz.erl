-module( gg ).
- compile ( export_all ).


%i hate erlang

start () ->
	spawn( fun server /0).

server () ->
	{From, Ref, start} ->
		N = rand:uniform(10),
		Pid = spawn(From+1, server, [0]),
		Pid!{self(), N},
		receive
			{Pid, N} ->
				Pid!{client, N};
		end.


client ( S ) ->
	N =rand:uniform(10)
	S!{N, self()},
	receive
		{test, Res} ->
			if
				Res == N ->
					io:format("gotIt");
					exit()
				true ->
					io:format("tryAgain")
					S!{rand:uniform(10), self()};
			end;
	end.

exit() ->

