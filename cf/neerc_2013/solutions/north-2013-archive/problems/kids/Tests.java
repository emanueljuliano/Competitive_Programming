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
/* Tests                                                          */
/*                                                                */
/* Author                Mikhail Dvorkin                          */
/******************************************************************/

import java.io.*;
import java.util.*;

public class Tests {
	static final int MAX = 50;
	
	private static File dir = new File("tests");
	private int curTest = 1;
	private static boolean verbose = true;

	private String testName;
	private PrintWriter out;

	public void run() {
		t(1, 2, 1, 2);
		t(1, 1, 1, 1);
		t(1, 1, 1, 2);
		t(1, 1, 1, 3);
		t(1, 1, 2, 2);
		t(5, 5, 6, 6);
		t(2, 3, 9, 1);
		t(13, 10, 15, 11);
		t(20, 24, 16, 1);
		t(1, 1, 45, 32);
		t(3, 48, 46, 5);
		t(40, 20, 30, 2);
		t(3, 35, 45, 2);
		t(3, 24, 46, 5);
		t(31, 49, 6, 25);
		t(4, 42, 6, 7);
		t(5, 8, 6, MAX - 7);
		t(5, 6, 8, MAX - 7);
		t(MAX, 1, MAX, MAX);
		t(MAX, MAX, 1, MAX);
		t(MAX, 1, 1, MAX);
		t(MAX / 7, MAX, MAX - 4, MAX / 2);
		t(MAX, 6, 6, MAX - 4);
		t(MAX, MAX, MAX, MAX);
		t(MAX, MAX, MAX - 1, MAX);
		t(MAX, MAX / 2, MAX, MAX);
		t(MAX / 3, MAX / 2, MAX - 1, MAX / 4);
	}

	private void t(int a, int b, int c, int d) {
		open();
		out.println(a + " " + b + " " + c + " " + d);
		close();
	}

	private void open() {
		try {
			testName = "" + curTest / 10 + curTest % 10;
			out = new PrintWriter(new File(dir, testName));
			if (verbose) { 
				System.out.print("Generating " + testName + "...");
			}
		} catch (IOException e) {
			throw new RuntimeException("Unable to open " + testName + " for writing", e);
		}
	}

	private void close() {
		out.close();
		if (verbose) {
			System.out.println(" done.");
		}
		curTest++;
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		dir.mkdirs();
		new Tests().run();
	}
}

