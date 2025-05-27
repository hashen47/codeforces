import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int rounds = Integer.parseInt(sc.nextLine());
		for (int i = 0; i < rounds; i++) {
			String s = sc.nextLine();

			if (s.length() == 2) {
				System.out.println("NO");
				continue;
			}

			int openBracketCount = 0;
			var stack = new Stack<Integer>();
			boolean isCompleted = false;
			boolean isPossible = false;

			for (int j = 0; j < s.length(); j++) {
				if (s.charAt(j) == '(') {
					if (isCompleted) {
						isPossible = true;
						break;
					}
					stack.push(j);
					openBracketCount++;
				} else {
					openBracketCount--;
					if (openBracketCount == 0) {
						isCompleted = true;
					}
					stack.pop();
				}
			}

			if (isPossible) {
				System.out.println("YES");
				continue;
			}
			System.out.println("NO");
		}

		sc.close();
	}
}
