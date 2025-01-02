import java.util.Scanner;
import java.util.Stack;


public class Main {
    public static void main(String argv[]) {
        Scanner sc = new Scanner(System.in);
        Stack<Character> stack = new Stack<>();


        int count = sc.nextInt();
        String inputData;

        for (int i = 0; i < count; i++) {
            inputData = sc.next();
            if (isVPS(stack, inputData)) System.out.println("YES");
            else System.out.println("NO");
            clear(stack);
        }


    }


    public static void clear(Stack<Character> stack) {
        while (!stack.empty()) {
            stack.pop();
        }
    }


    public static boolean isVPS(Stack<Character> stack, String data) {
        char c;
        for (int i = 0; i < data.length(); i++) {
            c = data.charAt(i);

            // 여는 괄호 -> push
            if (c == '(') stack.push(c); 
            
            /*
                이후 닫는 닫는 괄호
                stack이 비어 있거나, stack의 top == ')' -> false
             */
            else if (stack.empty() || stack.pop() != '(') return false;
        }

        if (stack.empty()) return true;
        else return false;
    }
}
