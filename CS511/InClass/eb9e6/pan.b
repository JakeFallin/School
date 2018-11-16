	switch (t->back) {
	default: Uerror("bad return move");
	case  0: goto R999; /* nothing to undo */

		 /* PROC :init: */

	case 3: // STATE 1
		;
		now.turn = trpt->bup.oval;
		;
		goto R999;

	case 4: // STATE 3
		;
		((P1 *)this)->i = trpt->bup.ovals[1];
		((P1 *)this)->i = trpt->bup.ovals[0];
		;
		ungrab_ints(trpt->bup.ovals, 2);
		goto R999;
;
		;
		
	case 6: // STATE 5
		;
		now.flags[ Index(((P1 *)this)->i, 3) ] = trpt->bup.oval;
		;
		goto R999;

	case 7: // STATE 6
		;
		((P1 *)this)->i = trpt->bup.oval;
		;
		goto R999;

	case 8: // STATE 12
		;
		((P1 *)this)->i = trpt->bup.oval;
		;
		goto R999;
;
		;
		
	case 10: // STATE 14
		;
		;
		delproc(0, now._nr_pr-1);
		;
		goto R999;

	case 11: // STATE 15
		;
		((P1 *)this)->i = trpt->bup.oval;
		;
		goto R999;

	case 12: // STATE 22
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC P */

	case 13: // STATE 7
		;
		((P0 *)this)->right = trpt->bup.ovals[1];
		((P0 *)this)->left = trpt->bup.ovals[0];
		;
		ungrab_ints(trpt->bup.ovals, 2);
		goto R999;

	case 14: // STATE 7
		;
		((P0 *)this)->right = trpt->bup.ovals[1];
		((P0 *)this)->left = trpt->bup.ovals[0];
		;
		ungrab_ints(trpt->bup.ovals, 2);
		goto R999;

	case 15: // STATE 7
		;
		((P0 *)this)->right = trpt->bup.oval;
		;
		goto R999;

	case 16: // STATE 8
		;
		now.flags[ Index((((P0 *)this)->_pid-1), 3) ] = trpt->bup.oval;
		;
		goto R999;
;
		;
		;
		;
		
	case 19: // STATE 11
		;
		now.flags[ Index((((P0 *)this)->_pid-1), 3) ] = trpt->bup.oval;
		;
		goto R999;
;
		;
		
	case 21: // STATE 16
		;
		now.flags[ Index((((P0 *)this)->_pid-1), 3) ] = trpt->bup.oval;
		;
		goto R999;

	case 22: // STATE 23
		;
		p_restor(II);
		;
		;
		goto R999;
	}

