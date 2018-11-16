	switch (t->back) {
	default: Uerror("bad return move");
	case  0: goto R999; /* nothing to undo */

		 /* PROC Woman */

	case 3: // STATE 1
		;
		now.sem = trpt->bup.oval;
		;
		goto R999;

	case 4: // STATE 3
		;
		woman = trpt->bup.oval;
		;
		goto R999;

	case 5: // STATE 4
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC Man */

	case 6: // STATE 2
		;
		now.mutex = trpt->bup.oval;
		;
		goto R999;

	case 7: // STATE 6
		;
		now.sem = trpt->bup.oval;
		;
		goto R999;

	case 8: // STATE 10
		;
		now.sem = trpt->bup.oval;
		;
		goto R999;

	case 9: // STATE 13
		;
		man = trpt->bup.oval;
		;
		goto R999;

	case 10: // STATE 14
		;
		now.mutex = trpt->bup.oval;
		;
		goto R999;

	case 11: // STATE 16
		;
		p_restor(II);
		;
		;
		goto R999;
	}

