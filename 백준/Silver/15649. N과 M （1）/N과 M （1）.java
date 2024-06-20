import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int N;
    static int M;
    static int[] numbers;
    static int[] ans;
    static boolean[] selected;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt(); // 1~N 범위
        M = sc.nextInt(); // 뽑을 수

        numbers = new int[N];
        ans = new int[M];
        selected = new boolean[N];
        for (int i = 0; i < N; i++) {
            numbers[i] = i + 1;
        }

        permutation(0);

        sc.close();
    }

    public static void permutation(int depth) {
        if (depth == M) {
            for (int i = 0; i < M; i++) {
                System.out.print(ans[i] + " ");
            }
            System.out.println();
            return;
        }

        for (int i = 0; i < N; i++) {
            if (!selected[i]) {
                selected[i] = true;
                ans[depth] = numbers[i];
                permutation(depth + 1);
                selected[i] = false;
            }
        }
    }
}
