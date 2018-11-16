byte turn = 0;
bool flags[3];

proctype P() {
	byte myId = _pid-1;
	byte left = 0;
	if
	:: myId == 0 ->
		left = 2;
	:: else ->
		left = myId - 1;
	fi;
	byte right = (myId+1)%3;
	flags[_pid-1] = true;
	do
		:: flags[left] == true || flags[right] == true ->
			:: turn == left ->
				flags[_pid-1] = false;
			:: else ->
			do 
				:: turn != myId ->
					break;
				:: else ->
					flags[_pid-1] = true;
			od;
	od
}

init {
	turn = 0;
	byte i;
	for(i:0..2) {
		flags[i] = false;
	}
	atomic {
		for(i:0..2) {
			run P();
		}
	}
}