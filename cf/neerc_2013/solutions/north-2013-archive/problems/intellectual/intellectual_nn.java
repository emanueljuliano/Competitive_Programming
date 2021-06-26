/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem I. Intellectual Property                               */
/*                                                                */
/* Original idea         Mikhail Dvorkin                          */
/* Problem statement     Yury Petrov                              */
/*                       Georgiy Korneev                          */
/* Test set              Georgiy Korneev                          */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Niyaz Nigmatullin                        */
/******************************************************************/

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created with IntelliJ IDEA.
 * User: Niyaz Nigmatullin
 * Date: 10/24/13
 * Time: 3:41 PM
 */
public class intellectual_nn {

    static final int SUBFIELD_SIZE = 3;
    static final int FIELD_SIZE = SUBFIELD_SIZE * SUBFIELD_SIZE;
    static final int P = 239017;

    static Comparator<State> comparatorNoID = new Comparator<State>() {
        @Override
        public int compare(State o1, State o2) {
            return Long.compare(o1.field, o2.field);
        }
    };
    static Comparator<State> comparator = new Comparator<State>() {
        @Override
        public int compare(State o1, State o2) {
            int c = comparatorNoID.compare(o1, o2);
            if (c != 0) return c;
            return Integer.compare(o1.id, o2.id);
        }
    };

    static void solve() throws IOException {
        int n = nextInt();
        int[][] goodPermutations = new int[6 * 6 * 6 * 6][];
        int[] currentPermutation = new int[FIELD_SIZE];
        for (int i = 0; i < currentPermutation.length; i++) {
            currentPermutation[i] = i;
        }
        int countGoodPermutations = 0;
        do {
            if (checkPermutation(currentPermutation)) {
                goodPermutations[countGoodPermutations++] = currentPermutation.clone();
            }
        } while (nextPermutation(currentPermutation));
        if (countGoodPermutations != goodPermutations.length) {
            throw new AssertionError();
        }
        int[][][] fields = new int[n][][];
        for (int imageID = 0; imageID < n; imageID++) {
            int[][] a = new int[FIELD_SIZE][FIELD_SIZE];
            for (int i = 0; i < FIELD_SIZE; i++) {
                char[] c = next().toCharArray();
                for (int j = 0; j < FIELD_SIZE; j++) {
                    a[i][j] = c[j] == '.' ? -1 : c[j] - '1';
                }
            }
            fields[imageID] = a;
        }
        List<State> firstStep = new ArrayList<>();
        List<State> secondStep = new ArrayList<>();
        for (int imageID = 0; imageID < n; imageID++) {
            {
                int[][] a = fields[imageID];
                int[][] b = new int[FIELD_SIZE][FIELD_SIZE];
                for (int[] p : goodPermutations) {
                    for (int i = 0; i < FIELD_SIZE; i++) {
                        for (int j = 0; j < FIELD_SIZE; j++) {
                            b[i][j] = a[p[i]][j];
                        }
                    }
                    int[] mapping = normalize(b);
                    State state = new State(p, mapping, b, false, imageID);
                    firstStep.add(state);
                }
            }
            {
                int[][] a = fields[imageID];
                int[][] b = new int[FIELD_SIZE][FIELD_SIZE];
                for (int flip = 0; flip < 2; flip++) {
                    for (int[] p : goodPermutations) {
                        for (int i = 0; i < FIELD_SIZE; i++) {
                            for (int j = 0; j < FIELD_SIZE; j++) {
                                b[i][j] = a[i][p[j]];
                            }
                        }
                        int[] mapping = normalize(b);
                        State state = new State(p, mapping, b, flip == 1, imageID);
                        secondStep.add(state);
                    }
                    a = flip(a);
                }
            }
        }
        Collections.sort(firstStep, comparator);
        Collections.sort(secondStep, comparator);
        List<String>[][] answer = new List[n][n];
        int[] f1 = new int[n];
        int[] f2 = new int[n];
        for (int i1 = 0, j1 = 0, i2 = i1, j2 = j1; i1 < firstStep.size() && j1 < secondStep.size(); ) {
            while (i2 < firstStep.size() && firstStep.get(i1).equals(firstStep.get(i2))) ++i2;
            while (j2 < secondStep.size() && secondStep.get(j1).equals(secondStep.get(j2))) ++j2;
            int c = comparatorNoID.compare(firstStep.get(i1), secondStep.get(j1));
            if (c < 0) {
                i1 = i2;
            } else if (c > 0) {
                j1 = j2;
            } else {
                int cnt1 = 0;
                int cnt2 = 0;
                f1[cnt1++] = i1++;
                f2[cnt2++] = j1++;
                while (i1 < i2) {
                    if (firstStep.get(i1).id != firstStep.get(i1 - 1).id) {
                        f1[cnt1++] = i1;
                    }
                    ++i1;
                }
                while (j1 < j2) {
                    if (secondStep.get(j1).id != secondStep.get(j1 - 1).id) {
                        f2[cnt2++] = j1;
                    }
                    ++j1;
                }
                for (int i = 0; i < cnt1; i++) {
                    for (int j = 0; j < cnt2; j++) {
                        State state1 = firstStep.get(f1[i]);
                        State state2 = secondStep.get(f2[j]);
                        if (state1.id >= state2.id || answer[state1.id][state2.id] != null) {
                            continue;
                        }
                        answer[state1.id][state2.id] = printTheAnswer(state1, state2);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (answer[i][j] == null) out.println("No");
                else {
                    out.println("Yes");
                    out.println(answer[i][j].size());
                    for (String e : answer[i][j]) {
                        out.println(e);
                    }
                }
            }
        }
    }

    private static List<String> printTheAnswer(State state, State state2) {
        List<String> answer = getAnswer(state.rowPermutation);
        List<String> answer2 = getAnswer(state2.rowPermutation);
        Collections.reverse(answer2);
        for (String e : answer2) {
            e = e.replace('r', 'c').replace('R', 'C');
            answer.add(e);
        }
        if (state2.flip) {
            answer.add("F");
        }
        int[] mapping1 = state.numberPermutation.clone();
        int[] mapping2 = inversePermutation(state2.numberPermutation);
        for (int i = 0; i < FIELD_SIZE; i++) {
            mapping1[i] = mapping2[mapping1[i]];
        }
        int[] currentMapping = new int[FIELD_SIZE];
        for (int i = 0; i < FIELD_SIZE; i++) {
            currentMapping[i] = i;
        }
        for (int i = 0; i < FIELD_SIZE; i++) {
            if (currentMapping[i] == mapping1[i]) continue;
            for (int j = i + 1; j < FIELD_SIZE; j++) {
                if (currentMapping[j] == mapping1[i]) {
                    answer.add("D " + (currentMapping[i] + 1) + " " + (currentMapping[j] + 1));
                    int t = currentMapping[i];
                    currentMapping[i] = currentMapping[j];
                    currentMapping[j] = t;
                }
            }
        }
        return answer;
    }

    static int[] inversePermutation(int[] p) {
        int[] ret = new int[p.length];
        for (int i = 0; i < ret.length; i++) {
            ret[p[i]] = i;
        }
        return ret;
    }

    static List<String> getAnswer(int[] rowPermutation) {
        int[] pm = new int[FIELD_SIZE];
        List<String> ret = new ArrayList<>();
        for (int i = 0; i < FIELD_SIZE; i++) pm[i] = i;
        for (int i = 0; i < FIELD_SIZE; i += SUBFIELD_SIZE) {
            if (pm[i] / SUBFIELD_SIZE != rowPermutation[i] / SUBFIELD_SIZE) {
                for (int j = i + SUBFIELD_SIZE; j < FIELD_SIZE; j += SUBFIELD_SIZE) {
                    if (pm[j] / SUBFIELD_SIZE == rowPermutation[i] / SUBFIELD_SIZE) {
                        ret.add("R " + (i / 3 + 1) + " " + (j / 3 + 1));
                        for (int k = 0; k < 3; k++) {
                            int t = pm[i + k];
                            pm[i + k] = pm[j + k];
                            pm[j + k] = t;
                        }
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < FIELD_SIZE; i++) {
            if (pm[i] != rowPermutation[i]) {
                for (int j = i + 1; j < FIELD_SIZE; j++) {
                    if (pm[j] == rowPermutation[i]) {
                        ret.add("r " + (i + 1) + " " + (j + 1));
                        int t = pm[i];
                        pm[i] = pm[j];
                        pm[j] = t;
                        break;
                    }
                }
            }
        }
        return ret;
    }

    static int[][] flip(int[][] a) {
        int[][] ret = new int[FIELD_SIZE][FIELD_SIZE];
        for (int i = 0; i < FIELD_SIZE; i++) {
            for (int j = 0; j < FIELD_SIZE; j++) {
                ret[i][j] = a[j][i];
            }
        }
        return ret;
    }

    static class State {
        int[] rowPermutation;
        int[] numberPermutation;
        long field;
        boolean flip;
        int id;

        State(int[] rowPermutation, int[] numberPermutation, int[][] field, boolean flip, int id) {
            this.rowPermutation = rowPermutation.clone();
            this.numberPermutation = numberPermutation.clone();
            for (int i = 0; i < FIELD_SIZE; i++) {
                for (int j = 0; j < FIELD_SIZE; j++) {
                    this.field = this.field * P + field[i][j];
                }
            }
            this.flip = flip;
            this.id = id;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            State state = (State) o;

            return field == state.field;
        }

        @Override
        public int hashCode() {
            return (int) ((field >>> 32) ^ field);
        }

    }

    private static boolean checkPermutation(int[] curP) {
        for (int i = 0; i < FIELD_SIZE; i += SUBFIELD_SIZE) {
            for (int j = 0; j < SUBFIELD_SIZE; j++) {
                if (curP[i + j] / SUBFIELD_SIZE != curP[i] / SUBFIELD_SIZE) {
                    return false;
                }
            }
        }
        return true;
    }

    static int[] normalize(int[][] a) {
        int[] mapping = new int[FIELD_SIZE];
        Arrays.fill(mapping, -1);
        int alreadyMappedTo = 0;
        for (int i = 0; i < FIELD_SIZE; i++) {
            for (int j = 0; j < FIELD_SIZE; j++) {
                int x = a[i][j];
                if (x < 0) continue;
                if (mapping[x] < 0) {
                    mapping[x] = alreadyMappedTo++;
                }
                a[i][j] = mapping[x];
            }
        }
        for (int i = 0; i < FIELD_SIZE; i++) {
            if (mapping[i] < 0) {
                mapping[i] = alreadyMappedTo++;
            }
        }
        return mapping;
    }

    static boolean nextPermutation(int[] a) {
        for (int i = a.length - 2; i >= 0; i--) {
            if (a[i] < a[i + 1]) {
                int cur = i + 1;
                for (int j = i + 2; j < a.length; j++) {
                    if (a[j] > a[i] && a[j] < a[cur]) {
                        cur = j;
                    }
                }
                {
                    int t = a[cur];
                    a[cur] = a[i];
                    a[i] = t;
                }
                for (int j = i + 1, k = a.length - 1; j < k; j++, k--) {
                    int t = a[j];
                    a[j] = a[k];
                    a[k] = t;
                }
                return true;
            }
        }
        return false;
    }

    static StringTokenizer tokenizer;
    static BufferedReader reader;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        reader = new BufferedReader(new FileReader("intellectual.in"));
        out = new PrintWriter("intellectual.out");
        solve();
        out.close();
        reader.close();
    }

    static String next() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line = reader.readLine();
            if (line == null) {
                return null;
            }
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

}

