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

public class kids_gk_ok_slowest {
    public static final int MAX_N = 50;
    public static final int MAX_Z = MAX_N * (MAX_N + 1);
    static Scanner in;
    static PrintWriter out;

    void run() {
        int gg = in.nextInt();
        int gb = in.nextInt();
        int bg = in.nextInt();
        int bb = in.nextInt();

        int bestG = MAX_Z + 1;
        int bestB = MAX_Z + 1;
        for (int g = 1; g <= MAX_Z; g++) {
            for (int b = 1; b <= MAX_Z; b++) {
                if (g > gg && g >= bg && b > bb && b >= gb && g * gg % 2 == 0 && b * bb % 2 == 0 && g * gb == b * bg && bestG + bestB > g + b) {
                    bestG = g;
                    bestB = b;
                }
            }
        }

        out.println(bestG + " " + bestB);
        same(bestG, gg, 1);
        same(bestB, bb, bestG + 1);

        int z = 0;
        for (int i = 0; i < bestG; i++) {
            for (int j = 0; j < gb; j++) {
                out.println((i + 1) + " " + (z + bestG + 1));
                z = (z + 1) % bestB;
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

        new kids_gk_ok_slowest().run();

        in.close();
        out.close();
    }
}

