import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int[] dwarf = new int[9];
    static int[] select =new int[7];
    static boolean[] visited = new boolean[9];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 9; i++) {
            dwarf[i] = Integer.parseInt(br.readLine());
        }

        comb(0, 0);

        br.close();
    }

    private static void comb(int depth, int start) {
        if (depth == 7) {
            int sum = Arrays.stream(select).sum();
            if (sum == 100) {
                for (int i = 0; i < 7; i++) {
                    System.out.println(select[i]);
                }
                return;
            } else return;
        }
        for (int i = start; i < 9; i++) {
            if (!visited[i]) {
                visited[i] = true;
                select[depth] = dwarf[i];
                comb(depth + 1, i);
                visited[i] = false;
            }
        }
    }
}
