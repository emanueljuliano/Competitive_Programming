/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem L. Lonely Mountain                                     */
/*                                                                */
/* Original idea         Georgiy Korneev                          */
/* Problem statement     Georgiy Korneev                          */
/* Test set              Georgiy Korneev                          */
/******************************************************************/
/* Checker                                                        */
/*                                                                */
/* Author                Georgiy Korneev                          */
/******************************************************************/

import ru.ifmo.testlib.Checker;
import ru.ifmo.testlib.InStream;
import ru.ifmo.testlib.Outcome;
import static ru.ifmo.testlib.Outcome.Type.*;

public class Check implements Checker {
    public Outcome outcome(Outcome.Type type, final String format, final Object... args) {
        return new Outcome(type, String.format(format, args));
    }

    Double readResult(InStream in) {
        String r = in.nextLine().trim();
        if (r.equals("Invalid plan")) {
            return null;
        }
        in.reset();
        return in.nextDouble();
    }

    static final double PRECISION = 2e-6;

    public Outcome test(InStream inf, InStream ouf, InStream ans) {
        Double pa = readResult(ouf);
        Double ja = readResult(ans);

        if (ja == null) {
            if (pa == null) {
                return outcome(OK, "Invalid plan");
            } else {
                return outcome(WA, "Volume=%.10f instead of invalid plan", pa);
            }
        } else {
            if (pa == null) {
                return outcome(WA, "Invalid plan instead of volume=%.10f", ja);
            } else {
                double error = Math.abs(ja - pa);
                if (error < PRECISION || error / ja < PRECISION) {
                    return outcome(OK, "Volume=%.10f", pa);
                } else {
                    return outcome(WA, "Expected %.10f, found %.10f", ja, pa);
                }
            }
        }
    }
}

