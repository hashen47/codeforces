import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int rounds = Integer.parseInt(scanner.nextLine());

		for (int z = 0; z < rounds; z++) {
			int n = Integer.parseInt(scanner.nextLine());

			int total = 0;

			if (n < 15) {
				for (int i = 0; i <= n; i++)
					if (i % 5 == i % 3) total++;
				System.out.println(total);
				continue;
			}

			total += 3;

			int q = n / 15;
			total += q * 3;
			int remainder = n % 15;

			if (remainder == 0) total -= 2;
			if (remainder == 1) total--;

			for (int i = (q * 15) + 3; i <= (q * 15) + remainder; i++)
				if (i % 3 == i % 5) total++;

			System.out.println(total);
		}

		scanner.close();
	}
}
