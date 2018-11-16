
-module(timer).
-compile(export_all).

start() ->
	L = spawn(?MODULE,client,[]) || _ <-lists:seq(1,10)],
	spawn(?MODULE,timer,[100,L]).

	time