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
/* Tests                                                          */
/*                                                                */
/* Author                Egor Kulikov                             */
/******************************************************************/

import java.io.*;
import java.util.*;

public class Tests {
    static final String alphabet;
    static final Random random = new Random(1235234523);
    static {
        StringBuilder sb = new StringBuilder("_");
        for (char x = 'a'; x <= 'z'; ++x) sb.append(x);
        for (char x = 'A'; x <= 'Z'; ++x) sb.append(x);
        for (char x = '0'; x <= '9'; ++x) sb.append(x);
        alphabet = sb.toString();
    }
    static int nTests = 0;
    static final File root = new File("tests");
    static void rmrf(File f) {
        if (f.isDirectory()) {
            for (File ch : f.listFiles()) {
                rmrf(ch);
            }
        }
        f.delete();
    }
    static void write(String...titles) throws IOException {
        try (PrintWriter out = new PrintWriter(String.format("%s/%02d", root.getName(), ++nTests))) {
            System.out.println("Writing test " + nTests);
            out.println(titles.length);
            for (String title : titles)
                out.println(title);
        }
    }
    static String randomString(int length, int alphabetSize) {
        alphabetSize = Math.min(alphabetSize, alphabet.length());
        StringBuilder rv = new StringBuilder();
        for (int i = 0; i < length; ++i) {
            rv.append(alphabet.charAt(random.nextInt(alphabetSize)));
        }
        return rv.toString();
    }
    
    static String[] allBut(char but) {
        List<String> result = new ArrayList<String>();
        for (char c = 'A'; c <= 'Z'; c++) {
            if (c != but)
                result.add(Character.toString(c));
        }
        Collections.shuffle(result, random);
        return result.toArray(new String[result.size()]);
    }
    
    static String[] random() {
        String[] result = new String[100];
        for (int i = 0; i < result.length; i++)
            result[i] = ((char) ('A' + random.nextInt(26))) + randomString(29, Integer.MAX_VALUE);
        return result;
    }

    public static void main(String[] args) throws IOException {
        write(
                "Arrangement_of_Contest",
                "Ballot_Analyzing_Device",
                "Correcting_Curiosity",
                "Dwarf_Tower",
                "Energy_Tycoon",
                "Flight_Boarding_Optimization",
                "Garage",
                "Heavy_Chain_Clusterization",
                "Intellectual_Property",
                "J",
                "Kids_in_a_Friendly_Class",
                "Lonely_Mountain"
        );
        write("Snow_White_and_the_7_Dwarfs", "A_Problem", "Another_Problem");
        write("Good_Problem", "Better_Problem");

        for (char c = 'A'; c <= 'Z' + 1; c++)
            write(allBut(c));
            
        for (int i = 0; i < 10; i++)
            write(random());
    }
}

