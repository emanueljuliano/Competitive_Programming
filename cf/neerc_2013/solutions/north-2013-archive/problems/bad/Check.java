/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem B. Ballot Analyzing Device                             */
/*                                                                */
/* Original idea         Jury                                     */
/* Problem statement     Andrew Stankevich                        */
/* Test set              Andrew Stankevich                        */
/******************************************************************/
/* Checker                                                        */
/*                                                                */
/* Author                Andrew Stankevich                        */
/******************************************************************/

import ru.ifmo.testlib.Checker;
import ru.ifmo.testlib.InStream;
import ru.ifmo.testlib.Outcome;
import static ru.ifmo.testlib.Outcome.Type.*;

public class Check implements Checker {
    public Outcome test(InStream inf, InStream ouf, InStream ans) {
        int n = inf.nextInt();
        for (int i = 0; i < n + 1; i++) {
            String ja = ans.nextLine();
            String pa = ouf.nextLine();
            if (!ja.equals(pa)) {
                return new Outcome(WA, "Line " + (i + 1) + ", expected: " + ja + ", found: " + pa);
            }
        }
        return new Outcome(OK, "");
    }
}

