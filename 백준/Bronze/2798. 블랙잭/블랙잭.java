import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static int[] cards;
    static boolean[] visited;
    static int[] select = new int[3];
    static int max = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine(), " ");
        cards = new int[N];
        visited = new boolean[N];
        for (int i = 0; i < N; i++) {
            cards[i] = Integer.parseInt(st.nextToken());
        }

        blackJack(0, 0);
        System.out.println(max);

        br.close();
    }

    private static void blackJack(int depth, int start) { // 조합
        if (depth == 3) {
            int sum = 0;
//            for (int i = 0; i < 3; i++) {
//                sum += select[i];
//            }
            sum = Arrays.stream(select).sum();

            if (sum > M) return;

            max = Math.max(max, sum);
            return;
        }
        for (int i = start; i < N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                select[depth] = cards[i];
                blackJack(depth + 1, i);
                visited[i] = false;
            }
        }
    }
}
