import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();

        int[] arr = new int[N];
        int[] sum = new int[N];
        int init = sc.nextInt();
        arr[0] = init;
        sum[0] = init;

        for (int i = 1; i < N; i++) {
            arr[i] = sc.nextInt();
            sum[i] = arr[i] + sum[i-1];
        }

        for (int i = 0; i < M; i++) {
            int minIdx = sc.nextInt();
            int maxIdx = sc.nextInt();
            System.out.println(sum[maxIdx-1] - sum[minIdx-1] + arr[minIdx-1]);
        }

        sc.close();
    }
}
