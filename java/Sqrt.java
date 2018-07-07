public class Sqrt{
    public static void main(String []args){
       long ts1 = System.nanoTime();
       double x = 0.0;
       for (int i = 0; i < 100; i++) {
           for (int k = 1; k < 501; k++) {
               x = sqrt((double)k);
           }
       }
       long ts2 = System.nanoTime();
       long wtime = (ts2 - ts1) / 1000 ;
       System.out.printf("used: %d us\n", wtime);
       System.out.printf("result: %f\n", x);
    }
    
    public static double abs(double x) {
        if (x < 0) return -x;
        return x;
    }


    public static double sqrt(double x) {
        if (x == 0.0) return 0.0;
        double z = 1.0;
        for (int i = 0; i < (int)x; i++) {
            if (abs(z * z - x) < 1e-7) break;
            z -= (z * z - x) / (2.0 * x);
        }
        return z;
    }
}