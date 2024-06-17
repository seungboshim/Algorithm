import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static ArrayList<Integer> switches = new ArrayList<>();

    static void maleSwitch(int N) { // N은 1부터 시작
        for (int i = N; i <= switches.size(); i+=N) {
            int temp = switches.get(i - 1);
            if (temp == 0) {
                switches.set(i - 1, 1);
            } else switches.set(i - 1, 0);
        }
    }

    // 0 1 1 1 0 1 0 1
    static void femaleSwitch(int N) { // N = 3
        int center = N - 1;
        int leftIdx = center - 1;
        int rightIdx = center + 1;

        int centerVal = switches.get(center);
        if (centerVal == 0) {
            switches.set(center, 1);
        } else switches.set(center, 0);

        while (leftIdx >= 0 && rightIdx < switches.size()
                && switches.get(leftIdx).equals(switches.get(rightIdx))) {
            int temp = switches.get(leftIdx);
            if (temp == 0) {
                switches.set(leftIdx, 1);
                switches.set(rightIdx, 1);
            } else {
                switches.set(leftIdx, 0);
                switches.set(rightIdx, 0);
            }
            leftIdx--;
            rightIdx++;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        String switchesStr = br.readLine();
        StringTokenizer switchesSt = new StringTokenizer(switchesStr, " ");
        for (int i = 0; i < N; i++) {
            switches.add(Integer.parseInt(switchesSt.nextToken()));
        }

        int K = Integer.parseInt(br.readLine());
        for (int i = 0; i < K; i++) {
            String studentsStr = br.readLine();
            StringTokenizer studentsSt = new StringTokenizer(studentsStr, " ");

            int gender = Integer.parseInt(studentsSt.nextToken());
            int index = Integer.parseInt(studentsSt.nextToken());

            if (gender == 1) { // 남학생
                maleSwitch(index);
            } else if (gender == 2) { // 여학생
                femaleSwitch(index);
            }
        }

        for (int i = 0; i < N; i++) {
            System.out.print(switches.get(i));
            if (i < N - 1) {
                System.out.print(" ");
            }
            if ((i + 1) % 20 == 0) {
                System.out.println();
            }
        }
    }
}