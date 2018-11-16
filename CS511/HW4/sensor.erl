-module(sensor).
-compile(export_all).
-author("Jacob Fallin & Timothy Barrett").

mysensor(WID, SID) ->
	Measurement = rand:uniform(11),
	Sleep_time = rand:uniform(10000),
	if Measurement == 11 ->
		WID!{SID, "anomalous_reading"},
		exit({anomalous_reading});
		true ->
			WID!{SID, Measurement}
	end,
	timer:sleep(Sleep_time),
	mysensor(WID,SID).
	
