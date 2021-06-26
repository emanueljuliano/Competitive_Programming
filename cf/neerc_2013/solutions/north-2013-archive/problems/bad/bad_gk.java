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
/* Solution                                                       */
/*                                                                */
/* Author                Georgiy Korneev                          */
/******************************************************************/

import java.io.*;
import java.util.*;

public class bad_gk {
    static Scanner in;
    static PrintWriter out;

    class Candidate implements Comparable<Candidate> {
        final String name;
        int votes;

        public Candidate(Scanner in) {
            name = in.next();
        }

        @Override
        public int compareTo(Candidate that) {
            return that.votes - this.votes;
        }
    }

    void run() {
        int n = in.nextInt();
        int m = in.nextInt();

        List<Candidate> candidates = new ArrayList<>();
        for (int i = 0; i  < n; i++) {
            candidates.add(new Candidate(in));
        }

        int invalid = 0;
        for (int i = 0; i  < m; i++) {
            char[] vote = in.next().toCharArray();
            int c = 0;
            for (int j = 0; j < n; j++) {
                if (vote[j] == 'X') {
                    c++;
                }
            }
            if (c == 1) {
                for (int j = 0; j < n; j++) {
                    if (vote[j] == 'X') {
                        candidates.get(j).votes++;
                    }
                }
            } else {
                invalid++;
            }
        }

        Collections.sort(candidates);
        for (Candidate candidate : candidates) {
            out.format("%s %.2f%%\n", candidate.name, 100.0 * candidate.votes / m);
        }
        out.format("%s %.2f%%\n", "Invalid", 100.0 * invalid / m);
    }

    public static void main(String[] args) throws Exception {
        in = new Scanner(new File("bad.in"));
        out = new PrintWriter("bad.out");
        Locale.setDefault(Locale.US);

        new bad_gk().run();

        in.close();
        out.close();
    }
}

