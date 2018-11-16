
bool wantP = false;
bool wantQ = false;

active proctype P() {

	do
		:: wantP = true;
		!wantQ!;
		//CS
		wantP = false;
	od		
}

active proctype Q() {

	do
		:: wantQ = true;
		!wantP;
		//CS
		wantQ = false
	od
}