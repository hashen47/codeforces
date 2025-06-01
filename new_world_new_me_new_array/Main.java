import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int z = 0; z < rounds; z++) {
			String[] parts = scanner.nextLine().split(" ");
			int n = Integer.parseInt(parts[0]);
			int k = Integer.parseInt(parts[1]);
			int p = Integer.parseInt(parts[2]);

			if (k == 0) {
				System.out.println(0);
				continue;
			}

			if (k < 0) {
				k *= -1;
			}

			int needCount = k / p;
			if (k % p != 0) {
				needCount++;
			}

			if (needCount > n) {
				System.out.println(-1);
				continue;
			}

			System.out.println(needCount);
		}

		scanner.close();
	}
}
