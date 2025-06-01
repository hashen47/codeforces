import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		String[] parts = scanner.nextLine().split(" ");
		int n = Integer.parseInt(parts[0]);
		int k = Integer.parseInt(parts[1]);

		for (int i = 0; i < k; i++) {
			if (n % 10 != 0) {
				n--;
			} else {
				n /= 10;
			}
		}

		System.out.println(n);
	}
}
