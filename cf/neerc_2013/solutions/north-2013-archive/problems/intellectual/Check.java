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
/* Checker                                                        */
/*                                                                */
/* Author                Georgiy Korneev                          */
/******************************************************************/

import ru.ifmo.testlib.Checker;
import ru.ifmo.testlib.InStream;
import ru.ifmo.testlib.Outcome;

import static ru.ifmo.testlib.Outcome.Type.*;

public class Check implements Checker {
    private Outcome outcome(Outcome.Type type, final String format, final Object... args) {
        return new Outcome(type, String.format(format, args));
    }

    public Outcome test(InStream inf, InStream ouf, InStream ans) {
        int n = inf.nextInt();
        char[][][] sudokus = new char[n][9][];
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < 9; i++) {
                sudokus[k][i] = inf.nextToken().toCharArray();
            }
        }

        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                String region = String.format("Puzzles %d and %d", i + 1, j + 1);
                boolean ja = readAnswer(region, sudokus[i], sudokus[j], ans, FAIL);
                boolean pa = readAnswer(region, sudokus[i], sudokus[j], ouf, WA);
                if (ja && !pa) {
                    return outcome(WA, "%s: Solution exists, but not found", region);
                } else if (!ja && pa) {
                    return outcome(FAIL, "%s: Solution exists, but not found by jury", region);
                }
                if (ja) {
                    c++;
                }
            }
        }

        return outcome(OK, "%d of %d", c, n * (n - 1) / 2);
    }

    private boolean readAnswer(String region, char[][] a, char[][] b, InStream ouf, Outcome.Type type) {
        String answer = ouf.nextToken();
        if (answer.equals("No")) {
            return false;
        }
        if (!answer.equals("Yes")) {
            throw outcome(type, "%s: Yes or No expected, '%s' found", region, answer);
        }

        char[][] t =  new char[9][9];
        for (int i = 0; i < 9; i++) {
            t[i] = a[i].clone();
        }

        int n = ouf.nextInt();
        if (n < 0 || 1000 < n) {
            throw outcome(type, "%s: Invalid number of actions %d", region, n);
        }
        for (int k = 0; k < n; k++) {
            String action = ouf.nextToken();
            if ("F".equals(action)) {
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < i; j++) {
                        char q = t[i][j];
                        t[i][j] = t[j][i];
                        t[j][i] = q;
                    }
                }
                continue;
            }
            int x = ouf.nextInt();
            int y = ouf.nextInt();
            switch (action) {
                case "D":
                    checkBounds(x, y, 9, type, k, "digit", region);
                    for (int i = 0; i < 9; i++) {
                        for (int j = 0; j < 9; j++) {
                            if (t[i][j] == '0' + x) {
                                t[i][j] = (char) ('0' + y);
                            } else if (t[i][j] == '0' + y) {
                                t[i][j] = (char) ('0' + x);
                            }
                        }
                    }
                    break;
                case "R":
                    checkBounds(x, y, 3, type, k, "row triple", region);
                    for (int i = 1; i <= 3; i++) {
                        for (int j = 0; j < 9; j++) {
                            char q = t[x * 3 - i][j];
                            t[x * 3 - i][j] = t[y * 3 - i][j];
                            t[y * 3 - i][j] = q;
                        }
                    }
                    break;
                case "r":
                    checkBounds(x, y, 9, type, k, "row", region);
                    if ((x - 1) / 3 != (y - 1) / 3) {
                        throw outcome(type, "%s, action %d: Rows %d and %d belongs to different triples", region, k + 1, x, y);
                    }
                    for (int j = 0; j < 9; j++) {
                        char q = t[x - 1][j];
                        t[x - 1][j] = t[y - 1][j];
                        t[y - 1][j] = q;
                    }
                    break;
                case "C":
                    checkBounds(x, y, 3, type, k, "column triple", region);
                    for (int i = 1; i <= 3; i++) {
                        for (int j = 0; j < 9; j++) {
                            char q = t[j][x * 3 - i];
                            t[j][x * 3 - i] = t[j][y * 3 - i];
                            t[j][y * 3 - i] = q;
                        }
                    }
                    break;
                case "c":
                    checkBounds(x, y, 9, type, k, "column", region);
                    if ((x - 1) / 3 != (y - 1) / 3) {
                        throw outcome(type, "%s, action %d: Columns %d and %d belongs to different triples", region, k + 1, x, y);
                    }
                    for (int j = 0; j < 9; j++) {
                        char q = t[j][x - 1];
                        t[j][x - 1] = t[j][y - 1];
                        t[j][y - 1] = q;
                    }
                    break;
                default:
                    throw outcome(type, "%s, action %d: Unknown action %s", region, k + 1, action);
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (t[i][j] != b[i][j]) {
                    throw outcome(type, "%s, cell (%d, %d): expected '%c', found '%c'", region, i + 1, j + 1, b[i][j], t[i][j]);
                }
            }
        }

        return true;
    }

    private void checkBounds(int x, int y, int max, Outcome.Type type, int k, String object, String region) {
        if (x < 1 || max < x) {
            throw outcome(type, "%s, action %d: Invalid %s %d", region, k + 1, object, x);
        }
        if (y < 1 || max < y) {
            throw outcome(type, "%s, action %d: Invalid %s %d", region, k + 1, object, y);
        }
    }
}

