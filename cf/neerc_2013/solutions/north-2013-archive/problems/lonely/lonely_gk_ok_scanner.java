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
/* Author                Georgiy Korneev                          */
/******************************************************************/

import java.io.*;
import java.util.*;

public class lonely_gk_ok_scanner {
    static Scanner in;
    static PrintWriter out;

    double max(double[] a) {
        double max = Double.MIN_VALUE;
        for (double v : a) {
            max = Math.max(max, v);
        }
        return max;
    }

    class Proj {
        int n;
        double[] c;
        double[] z;

        double v;
        double dv;

        List<Event> events = new ArrayList<Event>();

        Proj(Scanner in) {
            n = in.nextInt();
            c = new double[n];
            z = new double[n];
            for (int i = 0; i < n; i++) {
                c[i] = in.nextInt();
                z[i] = in.nextInt();
            }
            v = c[n - 1] - c[0];
            dv = 0;

            for (int i = 1; i < n; i++) {
                double dh = z[i] - z[i - 1];
                if (dh != 0) {
                    double ddc = (c[i] - c[i - 1]) / Math.abs(dh);
                    events.add(new Event(z[i - 1], 0, -ddc * Math.signum(dh)));
                    events.add(new Event(z[i], 0, ddc * Math.signum(dh)));
                } else {
                    events.add(new Event(z[i], c[i - 1] - c[i], 0));
                }
            }
            //System.out.println();
        }

        class Event implements Comparable<Event> {
            double h;
            double dc;
            double ddc;

            Event(double h, double dc, double ddc) {
                this.h = h;
                this.dc = dc;
                this.ddc = ddc;
                //System.out.println(h + " " + dc + " " + ddc);
            }

            public int compareTo(Event that) {
                return Double.compare(this.h, that.h);
            }

            void apply() {
                v += dc;
                dv += ddc;
            }
        }
    }

    void run() {
        Proj px = new Proj(in);
        Proj py = new Proj(in);

        if (max(px.z) != max(py.z)) {
            out.println("Invalid plan");
            return;
        }
        
        List<Proj.Event> events = new ArrayList<Proj.Event>();
        events.addAll(px.events);
        events.addAll(py.events);
        Collections.sort(events);

        double h = 0;
        double v = 0;
        for (Proj.Event event : events) {
            double dh = event.h - h;
            //System.out.println(" - " + h + "  " + px.v + " " + px.dv + "   " + py.v + " " + py.dv);
            double dv = dh * (px.v * py.v + dh * ((px.dv * py.v + px.v * py.dv) / 2 + dh * px.dv * py.dv / 3));
//            if (Math.abs(dv) > 1e-3) {
//                System.out.println(dv);
//            }
            v += dh * (px.v * py.v + dh * ((px.dv * py.v + px.v * py.dv) / 2 + dh * px.dv * py.dv / 3));
            h = event.h;
            px.v += px.dv * dh;
            py.v += py.dv * dh;
            event.apply();
//            System.out.println(" + " + h + "  " + px.v + " " + px.dv + "   " + py.v + " " + py.dv);
        }
        //System.out.println(v);
        out.println(v);
    }

    public static void main(String[] args) throws Exception {
        in = new Scanner(new File("lonely.in"));
        out = new PrintWriter("lonely.out");

        new lonely_gk_ok_scanner().run();

        in.close();
        out.close();
    }
}

