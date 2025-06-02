import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int z = 0; z < rounds; z++) {
			String s = scanner.nextLine();

			boolean isPossible = false;
			for (int i = 0; i < s.length()-1; i++) {
				if (s.charAt(i) == s.charAt(i+1)) {
					isPossible = true;
					break;
				}
			}

			if (isPossible) {
				System.out.println(1);
				continue;
			}
			System.out.println(s.length());
		}

		scanner.close();
	}
}
