-module(watcher).
-compile(export_all).
-author("Jacob Fallin & Timothy Barrett").

init() ->
	{ok, [WNum]} = io:fread("Input amount of sensors: ", "~d"),
	setup(WNum, 0).
	
setup(WNum, MNum) ->
    if WNum < 10 ->
		spawn(watcher, watcher_init, [WNum, MNum]);
	true ->
	    spawn(watcher, watcher_init, [10, MNum]),
    	setup(WNum-10, MNum+10)
   	end.

watcher_init(WNum, MNum)->
    PID = spawn_sensors(WNum, MNum, []),
    io:fwrite("~nWatcher Starting: ~p", [PID]),
    watcher_loop(self(), PID).

spawn_sensors(0, _, PID) ->
    PID;
spawn_sensors(NumSensors, MNum, PID) ->
    {Pid, _} = spawn_monitor(sensor, mysensor, [self(), MNum]),
    spawn_sensors(NumSensors-1, MNum+1, PID ++ [{MNum, Pid}]).

watcher_loop(ID, PID) ->
    receive
        {SID, "anomalous_reading"} ->
            io:fwrite("Sensor ~p died, reason: anomalous_reading~n", [SID]),
            {P, _} = spawn_monitor(sensor, mysensor, [self(), SID]),
            NewPID = lists:keyreplace(SID, 1, PID, {SID, P}),
            io:fwrite("replacing sensor ~p with replacement sensor: ~p~n", [SID, NewPID]);
        {SID, Measurement} ->
            io:fwrite("Sensor ~p reported measurement: ~p~n",[SID, Measurement]),
            NewPID = PID
    end,
    watcher_loop(ID, NewPID).