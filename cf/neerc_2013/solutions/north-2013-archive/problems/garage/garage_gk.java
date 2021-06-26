/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem G. Garage                                              */
/*                                                                */
/* Original idea         Georgiy Korneev                          */
/* Problem statement     Oleg Davydov                             */
/* Test set              Oleg Davydov                             */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Georgiy Korneev                          */
/******************************************************************/

import java.io.*;
import java.util.*;

public class garage_gk {
    static Scanner in;
    static PrintWriter out;

    void run() {
        int ah = in.nextInt();
        int aw = in.nextInt();

        int gh = in.nextInt();
        int gw = in.nextInt();

        out.println(((aw / gw + 1) / 2) * ((ah / gh + 1) / 2));
    }

    public static void main(String[] args) throws Exception {
        in = new Scanner(new File("garage.in"));
        out = new PrintWriter("garage.out");

        new garage_gk().run();

        in.close();
        out.close();
    }
}

