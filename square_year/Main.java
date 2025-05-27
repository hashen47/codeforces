import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int z = 0; z < rounds; z++) {
			int n = Integer.parseInt(scanner.nextLine());

			int v = (int)Math.sqrt(n);
			if (v * v != n) {
				System.out.println("-1");
				continue;
			}

			System.out.printf("%d %d\n", v, 0);
		}

		scanner.close();
	}
}
