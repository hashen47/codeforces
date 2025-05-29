import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int z = 0; z < rounds; z++) {
			int n = Integer.parseInt(scanner.nextLine());

			String[] parts = scanner.nextLine().split(" ");
			if (parts.length == 1) {
				System.out.println(parts[0]);
				continue;
			}

			boolean isPair = false;
			int last = 0;

			for (String s: parts) {
				int k = Integer.parseInt(s);
				if (isPair) {
					last += k -1;
				} else {
					last = k;
				}
				isPair = true;
			}

			System.out.println(last);
		}

		scanner.close();
	}
}
