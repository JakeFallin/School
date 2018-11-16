-module(bar)
-compile(export_all)

start(W,M) ->
	S=spawn(?MODULE,server,[0,0]),
	[spawn(?MODULE,woman,[S]) || _ <- lists:seq(1,W)],
	[spawn(?module,man[S]) || _ <- lists:seq(1,M)],
	[spawn(?MODULE,itGotLate,[1000,S])].

woman(S) ->
	S!{self(), woman}.

man(S) ->
	Ref=make_ref(),
	S!{self(),Ref,man},
	receive
			{S,Ref,ok} ->
				ok
	end.

itGotLate(Time,S) ->
	timer:sleep(Time),
	R=make_ref(),
	S!{self(), R, ok}.


answer_pending_men_requests() ->
	receive
		{From,Ref,man} ->
			From!{self(),Ref,ok}
			answer_pending_men_requests();
	after 0 ->
		ok

server(Women,false) ->
	receive
			{_From,woman} ->
				server(Women+1,false);
			{From,Ref,man} when Women>1 ->
				From!{self(),Ref,ok},
					server(Women-2,false);
			{From,Ref,itGotLate} ->
				From!{self(),Ref,ok},
				answer_pending_men_requests(),
				server(true)
	end.

server(true) ->
	receive
			{_From,woman} ->
				server(true);
			{From,Ref,man} -> 
				From!{self(),Ref,ok},
					server(true)
	end.