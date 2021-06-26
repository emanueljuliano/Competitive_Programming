/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem A. Arrangement of Contest                              */
/*                                                                */
/* Original idea         Egor Kulikov                             */
/* Problem statement     Egor Kulikov                             */
/* Test set              Egor Kulikov                             */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Georgiy Korneev                          */
/******************************************************************/

import java.io.*;
import java.util.*;

public class arrange_gk {
    static Scanner in;
    static PrintWriter out;

    void run() {
        int n = in.nextInt();
        boolean[] found = new boolean[27];
        for (int i = 0; i  < n; i++) {
            found[in.next().charAt(0) - 'A'] = true;
        }
        for (int i = 0; i < found.length; i++) {
            if (!found[i]) {
                out.println(i);
                break;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        in = new Scanner(new File("arrange.in"));
        out = new PrintWriter("arrange.out");

        new arrange_gk().run();

        in.close();
        out.close();
    }
}

