import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int i = 0; i < rounds; i++) {
			String[] parts = scanner.nextLine().split(" ");
			int wordLen = Integer.parseInt(parts[0]);
			int turns = Integer.parseInt(parts[1]);
			String word = scanner.nextLine();
			boolean isWordPalindrome = true;
			boolean isPossible = false;
			boolean isAllEqual = true;

			if (wordLen == 1) {
				System.out.println("NO");
				continue;
			}

			for (int j = 0; j < wordLen-1; j++) {
				if (word.charAt(j) != word.charAt(j+1)) {
					isAllEqual = false;
					break;
				}
			}

			if (isAllEqual) {
				System.out.println("NO");
				continue;
			}

			String revString = "";
			for (int j = word.length()-1; j >= 0; j--) {
				revString += word.charAt(j);
			}

			for (int j = 0; j < word.length(); j++) {
				char ch1 = word.charAt(j);
				char ch2 = revString.charAt(j);

				if (ch1 == ch2) {
					continue;
				}

				if (ch1 < ch2) {
					isPossible = true;
				}

				break;
			}

			if (isPossible) {
				System.out.println("YES");
				continue;
			}

			if (turns == 0) {
				System.out.println("NO");
				continue;
			}

			// check whether palindrome
			for (int j = 0; j < word.length(); j++) {
				if (j >= word.length()-1-j) {
					break;
				}

				if (word.charAt(j) != word.charAt(word.length()-1-j)) {
					isWordPalindrome = false;
					break;
				}
			}

			if (isWordPalindrome) {
				System.out.println("YES");
				continue;
			}

			isPossible = false;
			for (int j = 0; j < word.length(); j++) {
				char ch1 = word.charAt(j);
				char ch2 = revString.charAt(j);

				if (ch1 == ch2) {
					continue;
				}

				isPossible = true;
				break;
			}

			if (isPossible) {
				System.out.println("YES");
				continue;
			}

			System.out.println("NO");
		}

		scanner.close();
	}
}
