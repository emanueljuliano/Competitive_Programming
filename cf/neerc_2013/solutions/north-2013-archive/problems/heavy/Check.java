/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem H. Heavy Chain Clusterization                          */
/*                                                                */
/* Original idea         Yury Petrov                              */
/* Problem statement     Sergey Poromov                           */
/*                       Mikhail Dvorkin                          */
/* Test set              Sergey Poromov                           */
/******************************************************************/
/* Checker                                                        */
/*                                                                */
/* Author                Sergey Poromov                           */
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
        int n = inf.nextInt();
        int k = inf.nextInt();
        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = inf.nextToken();
        }

        int jg = ans.nextInt();
        int pg = ouf.nextInt();
        if (pg < 0 || pg > n) {
            return outcome(WA, "Invalid number of clusters: %d", pg);
        }
        if (jg < pg) {
            return outcome(WA, "Expected %d clusters, found %d", jg, pg);
        }

        int[][] groups = new int[pg][];

        boolean[] used = new boolean[n];

        for (int i = 0; i < pg; i++) {
            int sg = ouf.nextInt();
            if (sg <= 0 || sg > n) {
                return outcome(WA, "Invalid number of antibodies %d, in cluster %d", sg, i + 1);
            }
            groups[i] = new int[sg];
            for (int j = 0; j < sg; j++) {
                int t = ouf.nextInt() - 1;
                if (t < 0 || t >= n) {
                    return outcome(WA, "Invalid number of antibody: %d", t + 1);
                }
                if (used[t]) {
                    return outcome(WA, "Antibody number %d used twice", t + 1);
                }
                used[t] = true;
                groups[i][j] = t;
            }
        }

        for (int i = 0; i < pg; i++) {
            boolean start = true;
            boolean end = true;
            String first = s[groups[i][0]];
            String fbegin = first.substring(0, k);
            String fend = first.substring(first.length() - k);
            for (int j = 1; j < groups[i].length; j++) {
                String ss = s[groups[i][j]];
                String sbegin = ss.substring(0, k);
                String send = ss.substring(ss.length() - k);
                start &= fbegin.equals(sbegin);
                end &= fend.equals(send);
            }
            if (!start && !end) {
                return outcome(WA, "Antibodies in cluster %d are not similar", i + 1);
            }
        }

        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                return outcome(WA, "Heavy chain %d is not used", i + 1);
            }
        }

        if (jg > pg) {
            return outcome(FAIL, "Expected %d clusters, found %d", jg, pg);
        }

        return outcome(OK, "%d", jg);
    }
}

