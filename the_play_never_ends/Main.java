import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int z = 0; z < rounds; z++) {
			int k = Integer.parseInt(scanner.nextLine());

			if (k % 3 == 1) {
				System.out.println("YES");
				continue;
			}

			System.out.println("NO");
		}

		scanner.close();
	}
}
