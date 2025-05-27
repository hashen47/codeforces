import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int rounds = Integer.parseInt(scanner.nextLine());

		for (int z = 0; z < rounds; z++) {
			int length = Integer.parseInt(scanner.nextLine());

			int zeroCount = 0;
			int oneCount = 0;
			String digits = scanner.nextLine();

			for (int i = 0; i < length; i++) {
				if (digits.charAt(i) == '0') {
					zeroCount++;
				} else {
					oneCount++;
				}
			}

			System.out.println(zeroCount + oneCount * (length-1));
		}

		scanner.close();
	}
}	
