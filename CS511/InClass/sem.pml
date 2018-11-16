
byte sem = 0;
byte mutex = 1;
byte man = 0;
byte woman = 0;


inline acquire(sem) {
	skip;
	atomic {
		sem>0;
		sem--
	}
}

inline release(sem) {
	sem++
}

active [20] proctype Man() {
	acquire(mutex);
	acquire(sem);
	acquire(sem);
	man++;
	release(mutex);
}

active [20] proctype Woman() {
	release(sem);
	woman++;
}