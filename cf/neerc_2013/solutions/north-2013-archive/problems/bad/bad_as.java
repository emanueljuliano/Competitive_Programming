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
/* Author                Andrew Stankevich                        */
/******************************************************************/

import java.util.*;
import java.io.*;

public class bad_as {
    FastScanner in;
    PrintWriter out;

    class Party implements Comparable<Party> {
        int index;
        String name;
        int votes;

        Party(int index, String name) {
            this.index = index;
            this.name = name;
        }

        public int compareTo(Party o) {
            return votes != o.votes ? o.votes - votes : index - o.index;
        }
    }

    public void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        Party[] p = new Party[n];
        for (int i = 0; i < n; i++) {
            p[i] = new Party(i, in.next());
        }
        int invalid = 0;
        for (int i = 0; i < m; i++) {
            String t = in.next();
            int cnt = 0;
            int pos = 0;
            for (int j = 0; j < n; j++) {
                if (t.charAt(j) == 'X') {
                    cnt++;
                    pos = j;
                }
            }
            if (cnt == 1) {
                p[pos].votes++;
            } else {
                invalid++;
            }
        }
        Arrays.sort(p);
        for (int i = 0; i < n; i++) {
            out.printf("%s %.2f%%\n", p[i].name, p[i].votes * 100.0 / m);
        }
        out.printf("Invalid %.2f%%\n", invalid * 100.0 / m);
    }

    public void run() {
        try {
            in = new FastScanner(new File("bad.in"));
            out = new PrintWriter(new File("bad.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        Locale.setDefault(Locale.US);
        new bad_as().run();
    }
}

