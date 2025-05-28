import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int z = 0; z < rounds; z++) {
			String[] parts = scanner.nextLine().split(" "); 
			int n = Integer.parseInt(parts[0]);
			int x = Integer.parseInt(parts[1]);

			int total = 0;
			for (String s: scanner.nextLine().split(" ")) {
				total += Integer.parseInt(s);
			}

			if (total % n != 0) {
				System.out.println("NO");
				continue;
			}

			if (total / n != x) {
				System.out.println("NO");
				continue;
			}

			System.out.println("YES");
		}

		scanner.close();
	}
}
