import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int z = 0; z < rounds; z++) {
			int n = Integer.parseInt(scanner.nextLine());
			if (n % 2 == 0) {
				System.out.println("-1");
				continue;
			}

			if (n % 3 != 2) {
				System.out.printf("%d ", n);
				System.out.printf("%d ", 2);
				System.out.printf("%d ", 1);

				for (int i = 3; i < n; i++) {
					System.out.printf("%d ", i);
				}

				System.out.println("");
				continue;
			}

			System.out.printf("%d ", 1);
			System.out.printf("%d ", n);
			for (int i = 2; i < n; i++) {
				System.out.printf("%d ", i);
			}
			System.out.println("");
		}

		scanner.close();
	}
}
