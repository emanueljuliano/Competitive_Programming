/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem K. Kids in a Friendly Class                            */
/*                                                                */
/* Original idea         Mikhail Dvorkin                          */
/* Problem statement     Mikhail Dvorkin                          */
/* Test set              Mikhail Dvorkin                          */
/******************************************************************/
/* Checker                                                        */
/*                                                                */
/* Author                Mikhail Dvorkin                          */
/******************************************************************/

import java.util.*;

import ru.ifmo.testlib.Checker;
import ru.ifmo.testlib.InStream;
import ru.ifmo.testlib.Outcome;
import static ru.ifmo.testlib.Outcome.Type.*;

public class Check implements Checker {
    @Override
    public Outcome test(InStream inf, InStream ouf, InStream ans) {
        int a = inf.nextInt();
        int b = inf.nextInt();
        int c = inf.nextInt();
        int d = inf.nextInt();
        int ansSize = ans.nextInt() + ans.nextInt();
        int m = ouf.nextInt();
        int n = ouf.nextInt();
        int size = m + n;
        List<Pair> pairs = new ArrayList<Pair>();
        while (!ouf.seekEoF()) {
            pairs.add(new Pair(ouf.nextInt(), ouf.nextInt()));
        }
        if (size <= 0) {
            return new Outcome(WA, "Too few kids: " + size + "; won't even check the graph");
        }
        if (size > 1e7 && size > ansSize) {
            // Won't even check - don't want to allocate large arrays
            return new Outcome(WA, "Too many kids: " + size + "; won't even check the graph");
        }
        int[] girls = new int[size + 1];
        int[] boys = new int[size + 1];
        Set<Pair> pairSet = new HashSet<Pair>();
        for (Pair pair : pairs) {
            if (pair.min < 1) {
                return new Outcome(WA, "Invalid kid number: " + pair.min);
            }
            if (pair.max > size) {
                return new Outcome(WA, "Invalid kid number: " + pair.max);
            }
            if (pair.min == pair.max) {
                return new Outcome(WA, "Can't be friends with oneself: " + pair.min + " " + pair.max);
            }
            if (pairSet.contains(pair)) {
                return new Outcome(WA, "Pair of friends appears twice: " + pair.min + " " + pair.max);
            }
            pairSet.add(pair);
            if (pair.min <= m) {
                girls[pair.max]++;
            } else {
                boys[pair.max]++;
            }
            if (pair.max <= m) {
                girls[pair.min]++;
            } else {
                boys[pair.min]++;
            }
        }
        for (int i = 1; i <= size; i++) {
            int needGirls, needBoys;
            if (i <= m) {
                needGirls = a;
                needBoys = b;
            } else {
                needGirls = c;
                needBoys = d;
            }
            if (girls[i] != needGirls) {
                return new Outcome(WA, "Kid #" + i + " has wrong number of girlfriends: " + girls[i] + " != " + needGirls);
            }
            if (boys[i] != needBoys) {
                return new Outcome(WA, "Kid #" + i + " has wrong number of boyfriends: " + boys[i] + " != " + needBoys);
            }
        }
        if (size > ansSize) {
            return new Outcome(WA, "Too many kids: " + size + " > " + ansSize);
        }
        if (size < ansSize) {
            return new Outcome(FAIL, "Better than jury's: " + size + " < " + ansSize);
        }
        return new Outcome(OK, "Correct class of size " + size);
    }
    
    class Pair {
        int min, max;

        public Pair(int a, int b) {
            this.min = Math.min(a, b);
            this.max = Math.max(a, b);
        }
        
        @Override
        public boolean equals(Object obj) {
            Pair that = (Pair) obj;
            return min == that.min && max == that.max;
        }
        
        @Override
        public int hashCode() {
            return 32777 * min + max;
        }
    }
}

