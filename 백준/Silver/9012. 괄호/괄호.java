import java.io.FileInputStream;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    static Stack<Character> stack = new Stack<>();

    static void CheckString(String str) {
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '(') { // '('
                stack.push(str.charAt(i));
            } else if (str.charAt(i) == ')') { // ')'
                if (!stack.isEmpty() && stack.peek() == '(') {
                    stack.pop();
                } else {
                    stack.push(str.charAt(i));
                }
            }
        }

        if (!stack.isEmpty()) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
        }

        stack.clear();
    }

    public static void main(String[] args) throws Exception {
//        System.setIn(new FileInputStream("input.txt"));
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        while (T-- > 0) {
            String s = sc.next();
            CheckString(s);
        }
        sc.close();
    }
}
