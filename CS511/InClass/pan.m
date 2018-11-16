#define rand	pan_rand
#define pthread_equal(a,b)	((a)==(b))
#if defined(HAS_CODE) && defined(VERBOSE)
	#ifdef BFS_PAR
		bfs_printf("Pr: %d Tr: %d\n", II, t->forw);
	#else
		cpu_printf("Pr: %d Tr: %d\n", II, t->forw);
	#endif
#endif
	switch (t->forw) {
	default: Uerror("bad forward move");
	case 0:	/* if without executable clauses */
		continue;
	case 1: /* generic 'goto' or 'skip' */
		IfNotBlocked
		_m = 3; goto P999;
	case 2: /* generic 'else' */
		IfNotBlocked
		if (trpt->o_pm&1) continue;
		_m = 3; goto P999;

		 /* PROC Woman */
	case 3: // STATE 1 - sem.pml:16 - [sem = (sem+1)] (0:0:1 - 1)
		IfNotBlocked
		reached[1][1] = 1;
		(trpt+1)->bup.oval = ((int)now.sem);
		now.sem = (((int)now.sem)+1);
#ifdef VAR_RANGES
		logval("sem", ((int)now.sem));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 4: // STATE 3 - sem.pml:29 - [woman = (woman+1)] (0:0:1 - 1)
		IfNotBlocked
		reached[1][3] = 1;
		(trpt+1)->bup.oval = ((int)woman);
		woman = (((int)woman)+1);
#ifdef VAR_RANGES
		logval("woman", ((int)woman));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 5: // STATE 4 - sem.pml:30 - [-end-] (0:0:0 - 1)
		IfNotBlocked
		reached[1][4] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC Man */
	case 6: // STATE 1 - sem.pml:10 - [((mutex>0))] (8:0:1 - 1)
		IfNotBlocked
		reached[0][1] = 1;
		if (!((((int)now.mutex)>0)))
			continue;
		/* merge: mutex = (mutex-1)(0, 2, 8) */
		reached[0][2] = 1;
		(trpt+1)->bup.oval = ((int)now.mutex);
		now.mutex = (((int)now.mutex)-1);
#ifdef VAR_RANGES
		logval("mutex", ((int)now.mutex));
#endif
		;
		_m = 3; goto P999; /* 1 */
	case 7: // STATE 5 - sem.pml:10 - [((sem>0))] (12:0:1 - 1)
		IfNotBlocked
		reached[0][5] = 1;
		if (!((((int)now.sem)>0)))
			continue;
		/* merge: sem = (sem-1)(0, 6, 12) */
		reached[0][6] = 1;
		(trpt+1)->bup.oval = ((int)now.sem);
		now.sem = (((int)now.sem)-1);
#ifdef VAR_RANGES
		logval("sem", ((int)now.sem));
#endif
		;
		_m = 3; goto P999; /* 1 */
	case 8: // STATE 9 - sem.pml:10 - [((sem>0))] (13:0:1 - 1)
		IfNotBlocked
		reached[0][9] = 1;
		if (!((((int)now.sem)>0)))
			continue;
		/* merge: sem = (sem-1)(0, 10, 13) */
		reached[0][10] = 1;
		(trpt+1)->bup.oval = ((int)now.sem);
		now.sem = (((int)now.sem)-1);
#ifdef VAR_RANGES
		logval("sem", ((int)now.sem));
#endif
		;
		_m = 3; goto P999; /* 1 */
	case 9: // STATE 13 - sem.pml:23 - [man = (man+1)] (0:0:1 - 1)
		IfNotBlocked
		reached[0][13] = 1;
		(trpt+1)->bup.oval = ((int)man);
		man = (((int)man)+1);
#ifdef VAR_RANGES
		logval("man", ((int)man));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 10: // STATE 14 - sem.pml:16 - [mutex = (mutex+1)] (0:0:1 - 1)
		IfNotBlocked
		reached[0][14] = 1;
		(trpt+1)->bup.oval = ((int)now.mutex);
		now.mutex = (((int)now.mutex)+1);
#ifdef VAR_RANGES
		logval("mutex", ((int)now.mutex));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 11: // STATE 16 - sem.pml:25 - [-end-] (0:0:0 - 1)
		IfNotBlocked
		reached[0][16] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */
	case  _T5:	/* np_ */
		if (!((!(trpt->o_pm&4) && !(trpt->tau&128))))
			continue;
		/* else fall through */
	case  _T2:	/* true */
		_m = 3; goto P999;
#undef rand
	}

