import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int z = 0; z < rounds; z++) {
			String[] parts = scanner.nextLine().split(" ");

			int length = Integer.parseInt(parts[0]);
			int k = Integer.parseInt(parts[1]);
			int goodPairCount = 0;

			String s = scanner.nextLine();
			int zeroCount = 0;
			int oneCount = 0;
			for (int i = 0; i < length; i++) {
				if (s.charAt(i) == '0') {
					zeroCount++;
				}

				if (s.charAt(i) == '1') {
					oneCount++;
				}
			}
			
			if (
				((zeroCount/2) + (oneCount/2)) == k
			) {
				System.out.println("YES");
				continue;
			}

			if (
				((zeroCount/2) + (oneCount/2)) > k
			) {
				int a = (zeroCount/2);
				int b = (oneCount/2);

				boolean isPossible = false;
				while (a > 0 && b > 0) {
					a--;
					b--;
					if (a < 0 || b < 0) {
						break;
					}
					
					if (a + b == k) {
						System.out.println("YES");
						isPossible = true;
						break;
					}
				}

				if (!isPossible) {
					System.out.println("NO");
				}

				continue;
			}

			System.out.println("NO");
		}

		scanner.close();
	}
}
