/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem C. Correcting Curiosity                                */
/*                                                                */
/* Original idea         Yury Petrov                              */
/* Problem statement     Maxim Buzdalov                           */
/* Test set              Maxim Buzdalov                           */
/******************************************************************/
/* Checker                                                        */
/*                                                                */
/* Author                Maxim Buzdalov                           */
/******************************************************************/

import ru.ifmo.testlib.Checker;
import ru.ifmo.testlib.InStream;
import ru.ifmo.testlib.Outcome;
import static ru.ifmo.testlib.Outcome.Type.*;

public class Check implements Checker {
    private static final String PUNCT = " ,;:-";
    private Outcome outcome(Outcome.Type type, final String format, final Object... args) {
        return new Outcome(type, String.format(format, args));
    }

    private boolean checkCharacters(String s) {
        for (int i = 0, l = s.length(); i < l; ++i) {
            char c = s.charAt(i);
            if (!('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' || PUNCT.indexOf(c) >= 0)) {
                return false;
            }
        }
        return true;
    }

    private String[] parse(String query) {
        if (query == null || query.isEmpty()) {
            return new String[] {"Query is null or empty", null};
        }
        if (!query.startsWith("s/") || !query.endsWith("/g")) {
            return new String[] {"Query does not start with s/ or does not end with /g", null};
        }
        query = query.substring(2, query.length() - 2);
        int slash = query.indexOf('/');
        if (slash == -1 || slash != query.lastIndexOf('/')) {
            return new String[] {"Query contains other than 3 slashes", null};
        }
        String first = query.substring(0, slash);
        String second = query.substring(slash + 1);
        if (!checkCharacters(first) || !checkCharacters(second)) {
            return new String[] {"Query contains invalid characters", null};
        }
        return new String[] {first, second};
    }

    private String prepare(String s) {
        if (s.length() <= 50) {
            return s;
        } else {
            return s.substring(0, 24) + ".." + s.substring(s.length() - 24);
        }
    }

    public Outcome test(InStream inf, InStream ouf, InStream ans) {
        String oldv = inf.nextLine();
        String newv = inf.nextLine();
        if (!checkCharacters(oldv) || !checkCharacters(newv)) {
            return outcome(FAIL, "Input data contain invalid characters");
        }

        String cont = ouf.nextLine();
        String[] contParsed = parse(cont);
        if (contParsed[1] == null) {
            return outcome(PE, "Output is formatted the wrong way: %s (%s)", contParsed[0], prepare(cont));
        }

        String jury = ans.nextLine();
        String[] juryParsed = parse(jury);
        if (juryParsed[1] == null) {
            return outcome(FAIL, "Jury output is formatted the wrong way: %s (%s)", juryParsed[0], prepare(jury));
        }

        String juryNew = oldv.replace(juryParsed[0], juryParsed[1]);
        if (!juryNew.equals(newv)) {
            return outcome(FAIL, "Jury's answer makes wrong string: expected (%s) found (%s)", newv, juryNew);
        }

        String contNew = oldv.replace(contParsed[0], contParsed[1]);
        if (!contNew.equals(newv)) {
            return outcome(WA, "Contestant's answer makes wrong string: expected (%s) found (%s)", newv, contNew);
        }

        if (cont.length() > jury.length()) {
            return outcome(WA, "Contestant's answer is not optimal: %d instead of %d", cont.length(), jury.length());
        }

        if (cont.length() < jury.length()) {
            return outcome(FAIL, "Jury's answer is not optimal: %d, contestant's answer is %d", jury.length(), cont.length());
        }

        return outcome(OK, "Answer length: %d", jury.length());
    }
}

