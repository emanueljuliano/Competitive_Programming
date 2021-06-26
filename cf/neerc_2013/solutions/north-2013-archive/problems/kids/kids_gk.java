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

public class kids_gk {
    static Scanner in;
    static PrintWriter out;

    void run() {
        int gg = in.nextInt();
        int gb = in.nextInt();
        int bg = in.nextInt();
        int bb = in.nextInt();

        int gcd = gcd(gb, bg);
        int dg = bg / gcd;
        int db = gb / gcd;

        int q = Math.max(
                (Math.max(gg + 1, bg) + dg - 1) / dg,
                (Math.max(bb + 1, gb) + db - 1) / db
        );
        if ((dg * gg % 2 != 0 || db * bb % 2 != 0) && q % 2 != 0) {
            q++;
        }

        int g = dg * q;
        int b = db * q;

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
    }

    private int gcd(int a, int b) {
        return a == 0 ? b : gcd(b % a, a);
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

        new kids_gk().run();

        in.close();
        out.close();
    }
}

