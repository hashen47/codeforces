import java.util.Scanner;

public class Main {
	public static int gcd(int n1, int n2) {
		if (n1 == 0 || n2 == 0) {
			return -1;
		}

		if (n1 % n2 == 0) {
			return n2;
		}

		if (n2 % n1 == 0) {
			return n1;
		}

		int max = n2;
		int min = n1;
		if (n1 > n2) {
			max = n1;
			min = n2;
		}

		while (true) {
			int remainder = max/min;

			if (remainder == 0) {
				return min;
			}

			max = min;
			min = remainder;
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int rounds = Integer.parseInt(scanner.nextLine());

		for (int z = 0; z < rounds; z++) {
			int length = Integer.parseInt(scanner.nextLine());
			int[] arr = new int[length];

			int x = 0;
			for (String s: scanner.nextLine().split(" ")) {
				arr[x] = Integer.parseInt(s);
				x++;
			}

			for (int i = 0; i < length; i++) {
				for (int j = 0; j < length; j++) {
					if (j == 
				}
			}
			System.out.println(length);
			System.out.println(arr);
		}
		
		scanner.close();
	}
}
