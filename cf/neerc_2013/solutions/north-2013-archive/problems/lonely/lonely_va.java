/******************************************************************/
/* ACM ICPC 2013-2014, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 3, 2013                                */
/******************************************************************/
/* Problem L. Lonely Mountain                                     */
/*                                                                */
/* Original idea         Georgiy Korneev                          */
/* Problem statement     Georgiy Korneev                          */
/* Test set              Georgiy Korneev                          */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Vitaly Aksenov                           */
/******************************************************************/

import java.io.*;
import java.util.*;

public class lonely_va implements Runnable {
	public static void main(String[] args) {
		new Thread(new lonely_va()).run();
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

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public class Projection {
		int my;
		double l, dl;
		ArrayList<Event> events;

		public class Event implements Comparable<Event> {
			int hh, ll;
			double dll;

			public Event(int h, int l, double dl) {
				this.hh = h;
				this.ll = l;
				this.dll = dl;
			}

			public void add() {
				l += ll;
				dl += dll;
			}

			public int compareTo(Event e) {
				return e.hh - hh;
			}
		}

		public void read() throws IOException {
			int n = nextInt();
			int[] x = new int[n];
			int[] y = new int[n];
			events = new ArrayList<Event>();

			for (int i = 0; i < n; i++) {
				x[i] = nextInt();
				y[i] = nextInt();
				my = Math.max(my, y[i]);
			}

			for (int i = 0; i < n - 1; i++) {
				if (y[i] == y[i + 1]) {
					events.add(new Event(y[i], x[i + 1] - x[i], 0));
				} else {
					double dv = Math.abs(1. * (x[i + 1] - x[i])
							/ (y[i + 1] - y[i]));
					events.add(new Event(Math.max(y[i], y[i + 1]), 0, dv));
					events.add(new Event(Math.min(y[i], y[i + 1]), 0, -dv));
				}
			}
		}
	}

	public void solve() throws IOException {
		Projection px = new Projection();
		Projection py = new Projection();

		px.read();
		py.read();

		if (px.my != py.my) {
			out.println("Invalid plan");
			return;
		}

		ArrayList<Projection.Event> events = new ArrayList<Projection.Event>();
		events.addAll(px.events);
		events.addAll(py.events);

		Collections.sort(events);

		double ans = 0;
		double lh = px.my;
		for (Projection.Event e : events) {
			double dh = lh - e.hh;
			double cx = px.dl * dh;
			double cy = py.dl * dh;
			double add = dh
					* (px.l * py.l + (px.l * cy + py.l * cx) / 2 + cx * cy / 3);
			ans += add;
			px.l += px.dl * dh;
			py.l += py.dl * dh;
			lh = e.hh;
			e.add();
		}

		out.println(ans);
	}

	public void run() {
		try {
			br = new BufferedReader(new FileReader("lonely.in"));
			out = new PrintWriter("lonely.out");

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}

