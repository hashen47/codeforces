import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int z = 0; z < rounds; z++) {
			String[] parts = scanner.nextLine().split(" ");
			int n = Integer.parseInt(parts[0]);
			int k = Integer.parseInt(parts[1]);

			/*
			int count = 0;
			while (true) {
				if (n <= 0) break;

				if (n % 2 == 0) {
					if (k % 2 == 0) {
						n -= k;
					} else {
						n -= k-1;
					}
					count++;
				} else {
					if (k % 2 == 0) {
						n -= k-1;
					} else {
						n -= k;
					}
					count++;
				}
			}
			System.out.println(count);
			*/

			int count = 0;
			
			if (n % 2 == 0) {
				if (k % 2 == 0) {
					count += n / k;
					if (n % k != 0) {
						count++;
					}
				} else {
					count += n / (k-1);
					if (n % (k-1) != 0) {
						count++;
					}
				}
			} else {
				if (k % 2 != 0) {
					count++;
					n -= k;
				}

				count += n / (k-1);
				if (n % (k-1) != 0) {
					count++;
				}
			}

			System.out.println(count);
		}

		scanner.close();
	}
}
