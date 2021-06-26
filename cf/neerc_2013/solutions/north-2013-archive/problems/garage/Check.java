/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem G. Garage                                              */
/*                                                                */
/* Original idea         Georgiy Korneev                          */
/* Problem statement     Oleg Davydov                             */
/* Test set              Oleg Davydov                             */
/******************************************************************/
/* Checker                                                        */
/*                                                                */
/* Author                Oleg Davydov                             */
/******************************************************************/

import ru.ifmo.testlib.Checker;
import ru.ifmo.testlib.InStream;
import ru.ifmo.testlib.Outcome;
import static ru.ifmo.testlib.Outcome.Type.*;

public class Check implements Checker {
    public Outcome outcome(Outcome.Type type, final String format, final Object... args) {
        return new Outcome(type, String.format(format, args));
    }

    public Outcome test(InStream inf, InStream ouf, InStream ans) {
        long ja = ans.nextLong();
        long pa = ouf.nextLong();

        if (ja != pa) {
            return outcome(WA, "Expected %d, found %d", ja, pa);
        }
        return outcome(OK, "%d", ja);
    }
}

