import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
    static Scanner cin = new Scanner(new BufferedInputStream(System.in));
    static BigInteger[][] f = new BigInteger[151][151];
    static boolean[][] vis = new boolean[151][151];

    static BigInteger DP(int n, int d) {
        if (vis[n][d])
            return f[n][d];

        vis[n][d] = true;
        if (n <= 1 || d <= 1)
            return f[n][d] = BigInteger.ONE;

        f[n][d] = BigInteger.ZERO;
        for (int i = 0; i < n; i++) {
            f[n][d] = f[n][d].add(DP(i,d-1).multiply(DP(n-i-1, d)));
        }
        return f[n][d];
    }

    public static void main(String[] args) {
        for (int i = 0; i < 151; ++i)
            for (int j = 0; j < 151; ++j)
                vis[i][j] = false;


        while (cin.hasNext()) {
             int n = cin.nextInt(), d = cin.nextInt();
             int pairs = n / 2;

             System.out.println(DP(pairs, d).subtract(DP(pairs, d - 1)));
        }
    }
}
