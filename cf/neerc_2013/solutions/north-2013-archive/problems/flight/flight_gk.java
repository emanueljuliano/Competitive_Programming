/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem F. Flight Boarding Optimization                        */
/*                                                                */
/* Original idea         Pavel Mavrin                             */
/* Problem statement     Pavel Mavrin                             */
/* Test set              Pavel Mavrin                             */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Georgiy Korneev                          */
/******************************************************************/

import java.io.*;
import java.util.*;

public class flight_gk {
    static Scanner in;
    static PrintWriter out;

    void run() {
        int n = in.nextInt();
        int s = in.nextInt();
        int k = in.nextInt();

        List<List<Integer>> lq = new ArrayList<List<Integer>>(s);
        for (int i = 0; i < s; i++) {
            lq.add(new ArrayList<Integer>());
        }

        int[] q = new int[n];
        for (int i = 0; i < n; i++) {
            q[i] = in.nextInt() - 1;
            lq.get(q[i]).add(i);
        }

        int[] pcost = new int[s];
        int[][] cost = new int[n][s + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= s; j++) {
                cost[i][j] = cost[i][j - 1] + pcost[j - 1];
            }
            pcost[q[i]]++; 
        }

        int[][] scost = new int[s][s + 1];
        for (int i = 0; i < s; i++) {
            for (int j = i + 1; j <= s; j++) {
                scost[i][j] = scost[i][j - 1];
                for (int v : lq.get(j - 1)) {
                    scost[i][j] += cost[v][j - 1] - cost[v][i];
                }
            }
        }

        int[][] f = new int[k][s];
        for (int i = 0; i < s; i++) {
            f[0][i] = scost[0][i + 1];
        }
        for (int z = 1; z < k; z++) {
            for (int i = 0; i < s; i++) {
                f[z][i] = f[z - 1][i];
                for (int j = 0; j < i; j++) {
                    f[z][i] = Math.min(f[z][i], f[z - 1][j] + scost[j + 1][i + 1]);
                }
            }
        }
        out.println(f[k - 1][s - 1]);
    }

    public static void main(String[] args) throws Exception {
        in = new Scanner(new File("flight.in"));
        out = new PrintWriter("flight.out");

        new flight_gk().run();

        in.close();
        out.close();
    }
}

