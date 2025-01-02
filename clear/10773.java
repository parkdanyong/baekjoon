import java.util.Scanner;
import java.util.Stack;


public class Main {
    public static void main(String argv[]) {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> stack = new Stack<>();


        int count = sc.nextInt();
        int money;
        for (int i = 0; i < count; i++) {
            money = sc.nextInt();
            if (money == 0) stack.pop();
            else stack.push(money);
        }


        int sum = 0;
        while (!stack.empty()) {
            sum += stack.pop();
        }


        System.out.println(sum);
        sc.close();
    }
}
