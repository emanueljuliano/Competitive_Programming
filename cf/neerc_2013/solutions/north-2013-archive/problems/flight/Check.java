/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem F. Flight Boarding Optimization                        */
/*                                                                */
/* Original idea         Pavel Mavrin                             */
/* Problem statement     Pavel Mavrin                             */
/* Test set              Pavel Mavrin                             */
/******************************************************************/
/* Checker                                                        */
/*                                                                */
/* Author                Pavel Mavrin                             */
/******************************************************************/

import java.util.*;

import ru.ifmo.testlib.Checker;
import ru.ifmo.testlib.InStream;
import ru.ifmo.testlib.Outcome;
import static ru.ifmo.testlib.Outcome.Type.*;

public class Check implements Checker {
	@Override
	public Outcome test(InStream inf, InStream ouf, InStream ans) {
		int pa = ouf.nextInt();
		int ja = ans.nextInt();

		if (pa != ja) {
			return new Outcome(WA, "Wrong answer: " + pa + ", expected " + ja);
		}
		return new Outcome(OK, "");
	}
}

