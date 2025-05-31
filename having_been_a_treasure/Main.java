import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		long rounds = Long.parseLong(scanner.nextLine());
		for (long z = 0; z < rounds; z++) {
			long length = Long.parseLong(scanner.nextLine());

			long longBarCount = 0;
			long shortBarCount = 0;

			String line = scanner.nextLine();
			for (long i = 0; i < line.length(); i++) {
				if (line.charAt((int)i) == '-') {
					shortBarCount++;
				} else {
					longBarCount++;
				}
			}

			if (shortBarCount < 2 || longBarCount == 0) {
				System.out.println(0);
				continue;
			}


			long max = 0;
			if (shortBarCount == 2) {
				max = 1; 
			} else {
				long k = 1;
				while (true) {
					long val = (shortBarCount-k) * k;
					if (val == 0) {
						break;
					}
					if (val > max) {
						max = val;
					}
					k++;
				}
			}

			System.out.println(max * longBarCount);
			continue;
		}

		scanner.close();
	}
}
