/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem E. Energy Tycoon                                       */
/*                                                                */
/* Original idea         Vitaly Aksenov                           */
/* Problem statement     Vitaly Aksenov                           */
/* Test set              Vitaly Aksenov                           */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Georgiy Korneev                          */
/******************************************************************/

import java.io.*;
import java.util.*;

public class energy_gk {
    static Scanner in;
    static PrintWriter out;

    void run() {
        int n = in.nextInt();
        long total = 0;
        int ones = 0;
        int twos = 0;
        for (char c : in.next().toCharArray()) {
            if (c == '1') {
                if (twos * 2 + ones < n) {
                    ones++;
                } else if (twos > 0) {
                    twos--;
                    ones++;
                }
            } else {
                if (twos * 2 + ones + 2 <= n) {
                    twos++;
                }
            }
            total += ones + twos;
        }
        out.println(total);
    }

    public static void main(String[] args) throws Exception {
        in = new Scanner(new File("energy.in"));
        out = new PrintWriter("energy.out");

        new energy_gk().run();

        in.close();
        out.close();
    }
}

