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

		 /* PROC :init: */
	case 3: // STATE 1 - dekker3.pml:30 - [turn = 0] (0:0:1 - 1)
		IfNotBlocked
		reached[1][1] = 1;
		(trpt+1)->bup.oval = ((int)now.turn);
		now.turn = 0;
#ifdef VAR_RANGES
		logval("turn", ((int)now.turn));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 4: // STATE 2 - dekker3.pml:32 - [i = 0] (0:9:2 - 1)
		IfNotBlocked
		reached[1][2] = 1;
		(trpt+1)->bup.ovals = grab_ints(2);
		(trpt+1)->bup.ovals[0] = ((int)((P1 *)this)->i);
		((P1 *)this)->i = 0;
#ifdef VAR_RANGES
		logval(":init::i", ((int)((P1 *)this)->i));
#endif
		;
		/* merge: i = 0(9, 3, 9) */
		reached[1][3] = 1;
		(trpt+1)->bup.ovals[1] = ((int)((P1 *)this)->i);
		((P1 *)this)->i = 0;
#ifdef VAR_RANGES
		logval(":init::i", ((int)((P1 *)this)->i));
#endif
		;
		/* merge: .(goto)(0, 10, 9) */
		reached[1][10] = 1;
		;
		_m = 3; goto P999; /* 2 */
	case 5: // STATE 4 - dekker3.pml:32 - [((i<=2))] (0:0:0 - 1)
		IfNotBlocked
		reached[1][4] = 1;
		if (!((((int)((P1 *)this)->i)<=2)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 6: // STATE 5 - dekker3.pml:33 - [flags[i] = 0] (0:0:1 - 1)
		IfNotBlocked
		reached[1][5] = 1;
		(trpt+1)->bup.oval = ((int)now.flags[ Index(((int)((P1 *)this)->i), 3) ]);
		now.flags[ Index(((P1 *)this)->i, 3) ] = 0;
#ifdef VAR_RANGES
		logval("flags[:init::i]", ((int)now.flags[ Index(((int)((P1 *)this)->i), 3) ]));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 7: // STATE 6 - dekker3.pml:32 - [i = (i+1)] (0:0:1 - 1)
		IfNotBlocked
		reached[1][6] = 1;
		(trpt+1)->bup.oval = ((int)((P1 *)this)->i);
		((P1 *)this)->i = (((int)((P1 *)this)->i)+1);
#ifdef VAR_RANGES
		logval(":init::i", ((int)((P1 *)this)->i));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 8: // STATE 12 - dekker3.pml:36 - [i = 0] (0:0:1 - 1)
		IfNotBlocked
		reached[1][12] = 1;
		(trpt+1)->bup.oval = ((int)((P1 *)this)->i);
		((P1 *)this)->i = 0;
#ifdef VAR_RANGES
		logval(":init::i", ((int)((P1 *)this)->i));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 9: // STATE 13 - dekker3.pml:36 - [((i<=2))] (0:0:0 - 1)
		IfNotBlocked
		reached[1][13] = 1;
		if (!((((int)((P1 *)this)->i)<=2)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 10: // STATE 14 - dekker3.pml:37 - [(run P())] (0:0:0 - 1)
		IfNotBlocked
		reached[1][14] = 1;
		if (!(addproc(II, 1, 0)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 11: // STATE 15 - dekker3.pml:36 - [i = (i+1)] (0:0:1 - 1)
		IfNotBlocked
		reached[1][15] = 1;
		(trpt+1)->bup.oval = ((int)((P1 *)this)->i);
		((P1 *)this)->i = (((int)((P1 *)this)->i)+1);
#ifdef VAR_RANGES
		logval(":init::i", ((int)((P1 *)this)->i));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 12: // STATE 22 - dekker3.pml:40 - [-end-] (0:0:0 - 1)
		IfNotBlocked
		reached[1][22] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC P */
	case 13: // STATE 1 - dekker3.pml:8 - [((myId==0))] (8:0:2 - 1)
		IfNotBlocked
		reached[0][1] = 1;
		if (!((((int)((P0 *)this)->myId)==0)))
			continue;
		/* merge: left = 2(8, 2, 8) */
		reached[0][2] = 1;
		(trpt+1)->bup.ovals = grab_ints(2);
		(trpt+1)->bup.ovals[0] = ((int)((P0 *)this)->left);
		((P0 *)this)->left = 2;
#ifdef VAR_RANGES
		logval("P:left", ((int)((P0 *)this)->left));
#endif
		;
		/* merge: .(goto)(8, 6, 8) */
		reached[0][6] = 1;
		;
		/* merge: right = ((myId+1)%3)(8, 7, 8) */
		reached[0][7] = 1;
		(trpt+1)->bup.ovals[1] = ((int)((P0 *)this)->right);
		((P0 *)this)->right = ((((int)((P0 *)this)->myId)+1)%3);
#ifdef VAR_RANGES
		logval("P:right", ((int)((P0 *)this)->right));
#endif
		;
		_m = 3; goto P999; /* 3 */
	case 14: // STATE 4 - dekker3.pml:11 - [left = (myId-1)] (0:8:2 - 1)
		IfNotBlocked
		reached[0][4] = 1;
		(trpt+1)->bup.ovals = grab_ints(2);
		(trpt+1)->bup.ovals[0] = ((int)((P0 *)this)->left);
		((P0 *)this)->left = (((int)((P0 *)this)->myId)-1);
#ifdef VAR_RANGES
		logval("P:left", ((int)((P0 *)this)->left));
#endif
		;
		/* merge: .(goto)(8, 6, 8) */
		reached[0][6] = 1;
		;
		/* merge: right = ((myId+1)%3)(8, 7, 8) */
		reached[0][7] = 1;
		(trpt+1)->bup.ovals[1] = ((int)((P0 *)this)->right);
		((P0 *)this)->right = ((((int)((P0 *)this)->myId)+1)%3);
#ifdef VAR_RANGES
		logval("P:right", ((int)((P0 *)this)->right));
#endif
		;
		_m = 3; goto P999; /* 2 */
	case 15: // STATE 7 - dekker3.pml:14 - [right = ((myId+1)%3)] (0:8:1 - 3)
		IfNotBlocked
		reached[0][7] = 1;
		(trpt+1)->bup.oval = ((int)((P0 *)this)->right);
		((P0 *)this)->right = ((((int)((P0 *)this)->myId)+1)%3);
#ifdef VAR_RANGES
		logval("P:right", ((int)((P0 *)this)->right));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 16: // STATE 8 - dekker3.pml:14 - [flags[(_pid-1)] = 1] (0:0:1 - 1)
		IfNotBlocked
		reached[0][8] = 1;
		(trpt+1)->bup.oval = ((int)now.flags[ Index((((int)((P0 *)this)->_pid)-1), 3) ]);
		now.flags[ Index((((P0 *)this)->_pid-1), 3) ] = 1;
#ifdef VAR_RANGES
		logval("flags[(_pid-1)]", ((int)now.flags[ Index((((int)((P0 *)this)->_pid)-1), 3) ]));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 17: // STATE 9 - dekker3.pml:16 - [(((flags[left]==1)||(flags[right]==1)))] (0:0:0 - 1)
		IfNotBlocked
		reached[0][9] = 1;
		if (!(((((int)now.flags[ Index(((int)((P0 *)this)->left), 3) ])==1)||(((int)now.flags[ Index(((int)((P0 *)this)->right), 3) ])==1))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 18: // STATE 10 - dekker3.pml:17 - [((turn==left))] (0:0:0 - 1)
		IfNotBlocked
		reached[0][10] = 1;
		if (!((((int)now.turn)==((int)((P0 *)this)->left))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 19: // STATE 11 - dekker3.pml:18 - [flags[(_pid-1)] = 0] (0:0:1 - 1)
		IfNotBlocked
		reached[0][11] = 1;
		(trpt+1)->bup.oval = ((int)now.flags[ Index((((int)((P0 *)this)->_pid)-1), 3) ]);
		now.flags[ Index((((P0 *)this)->_pid-1), 3) ] = 0;
#ifdef VAR_RANGES
		logval("flags[(_pid-1)]", ((int)now.flags[ Index((((int)((P0 *)this)->_pid)-1), 3) ]));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 20: // STATE 13 - dekker3.pml:21 - [((turn!=myId))] (0:0:0 - 1)
		IfNotBlocked
		reached[0][13] = 1;
		if (!((((int)now.turn)!=((int)((P0 *)this)->myId))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 21: // STATE 16 - dekker3.pml:24 - [flags[(_pid-1)] = 1] (0:0:1 - 1)
		IfNotBlocked
		reached[0][16] = 1;
		(trpt+1)->bup.oval = ((int)now.flags[ Index((((int)((P0 *)this)->_pid)-1), 3) ]);
		now.flags[ Index((((P0 *)this)->_pid-1), 3) ] = 1;
#ifdef VAR_RANGES
		logval("flags[(_pid-1)]", ((int)now.flags[ Index((((int)((P0 *)this)->_pid)-1), 3) ]));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 22: // STATE 23 - dekker3.pml:27 - [-end-] (0:0:0 - 1)
		IfNotBlocked
		reached[0][23] = 1;
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

