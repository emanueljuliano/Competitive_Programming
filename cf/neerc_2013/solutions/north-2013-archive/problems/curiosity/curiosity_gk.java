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
/* Solution                                                       */
/*                                                                */
/* Author                Georgiy Korneev                          */
/******************************************************************/

import java.io.*;
import java.util.*;

public class curiosity_gk {
    static Scanner in;
    static PrintWriter out;

    static long P = 1000003;

    class HString {
        long[] hashes;
        long[] ps;
        int l;
        String s;

        HString(String s) {
            this.s = s;
            l = s.length();
            hashes = new long[l + 1];            
            ps = new long[l + 1];
            ps[0] = 1;
            for (int i = 1; i < l + 1; i++) {
                hashes[i] = hashes[i - 1] * P + s.charAt(i - 1);
                ps[i] = ps[i - 1] * P;
            }
        }

        long hash(int off, int len) {
            return hashes[off + len] - hashes[off] * ps[len];
        }
    }

    void run() {
        HString s1 = new HString(in.nextLine());
        HString s2 = new HString(in.nextLine());

        int[] next = new int[s1.l];
        int[] first = new int[s1.l];
        int[] cs = new int[s1.l];
        int[] last = new int[s1.l];

        for (int l1 = 1; l1 <= s1.l; l1++) {
            Map<Long, Integer> z = new HashMap<Long, Integer>();
            for (int i = 0; i <= s1.l - l1; i++) {
                Integer p = z.put(s1.hash(i, l1), i);
                if (p != null) {
                    int f = first[p];
                    first[i] = f;
                    if (i - last[f] >= l1) {
                        next[last[f]] = i;
                        last[f] = i;
                        cs[f]++;
                    }
                } else {
                    first[i] = i;
                    last[i] = i;
                    cs[i] = 1;
                }
                next[i] = s1.l;
            }

            for (int i = 0; i <= Math.min(s1.l - l1, s2.l); i++) {
                boolean ok = first[i] == i && s1.hash(0, i) == s2.hash(0, i);
                if (ok && Math.abs(s2.l - s1.l) % cs[i] == 0) {
                    int l2 = l1 + (s2.l - s1.l) / cs[i];
                    if (l2 < 0) break;

                    long h2 = s2.hash(i, l2);

                    int i1 = i;
                    int i2 = i;
                    while (i1 < s1.l) {
                        int d = next[i1] - i1 - l1;
                        ok &= h2 == s2.hash(i2, l2) && s1.hash(i1 + l1, d) == s2.hash(i2 + l2, d);
                        i1 += l1 + d;
                        i2 += l2 + d;
                    }

                    if (ok) {
                        out.println("s/" + s1.s.substring(i, i + l1) + "/" + s2.s.substring(i, i + l2) + "/g");
                        return;
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        in = new Scanner(new File("curiosity.in"));
        out = new PrintWriter("curiosity.out");

        new curiosity_gk().run();

        in.close();
        out.close();
    }
}

