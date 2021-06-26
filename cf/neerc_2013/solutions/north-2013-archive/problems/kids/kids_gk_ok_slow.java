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
/* Solution                                                       */
/*                                                                */
/* Author                Georgiy Korneev                          */
/******************************************************************/

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class kids_gk_ok_slow {
    public static final int MAX_N = 100;
    public static final int MAX_Z = MAX_N * (MAX_N + 1);
    static Scanner in;
    static PrintWriter out;

    void run() {
        int gg = in.nextInt();
        int gb = in.nextInt();
        int bg = in.nextInt();
        int bb = in.nextInt();

        int dg = gg % 2 + 1;
        int db = bb % 2 + 1;
        int sg = Math.max(gg + 1, bg);
        if (sg % dg != 0) {
            sg++;
        }
        int sb = Math.max(bb + 1, gb);
        if (sb % db != 0) {
            sb++;
        }

        for (int g = sg; g <= MAX_Z; g += dg) {
            for (int b = sb; b <= MAX_Z; b += db) {
                if (g * gb == b * bg) {
                    out.println(g + " " + b);
                    same(g, gg, 1);
                    same(b, bb, g + 1);

                    int z = 0;
                    for (int i = 0; i < g; i++) {
                        for (int j = 0; j < gb; j++) {
                            out.println((i + 1) + " " + (z + g + 1));
                            z = (z + 1) % b;
                        }
                    }
                    return;
                }
            }
        }

    }

    private void same(int n, int friends, int first) {
        for (int i = 0; i < friends / 2; i++) {
            for (int j = 0; j < n; j++) {
                out.println((j + first) + " " + ((j + i + 1) % n + first));
            }
        }
        if (friends % 2 == 1) {
            for (int i = 0; i < n / 2; i++) {
                out.println((i + first) + " " + (i + n / 2 + first));
            }
        }
    }

    public static void main(String[] args) throws Exception {
        in = new Scanner(new File("kids.in"));
        out = new PrintWriter("kids.out");

        new kids_gk_ok_slow().run();

        in.close();
        out.close();
    }
}

