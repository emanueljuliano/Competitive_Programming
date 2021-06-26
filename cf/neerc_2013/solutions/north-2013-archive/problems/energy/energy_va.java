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
/* Author                Vitaly Aksenov                           */
/******************************************************************/

import java.io.*;
import java.sql.Array;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.*;

public class energy_va {
    public static void main(String[] args) {
        new energy_va().run();
    }

    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public void solve() throws IOException {
        int n = nextInt();
        char[] c = nextToken().toCharArray();

        long ans = 0;
        int[] s = new int[3];
        int total = 0;
        for (int i = 0; i < c.length; i++) {
            int x = c[i] - '0';
            if (total + x <= n) {
                s[x]++;
                total += x;
            } else {
                if (x == 1 && s[2] > 0) {
                    s[2]--;
                    s[1]++;
                    total--;
                }
            }
            ans += s[1] + s[2];
        }
        out.println(ans);
    }

    public void run() {
        try {
            br = new BufferedReader(new FileReader("energy.in"));
            out = new PrintWriter("energy.out");

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}

