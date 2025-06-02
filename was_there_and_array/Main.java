import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int z = 0; z < rounds; z++) {
			int length = Integer.parseInt(scanner.nextLine());
			int[] arr = new int[length];

			String[] parts = scanner.nextLine().split(" ");
			for (int i = 0; i < length-2; i++) {
				arr[i] = Integer.parseInt(parts[i]);
			}	

			boolean isPossible = true;
			for (int i = 0; i < length; i++) {
				if (arr[i] == 0) {
					if (i == 0 || i == length-1) continue;
					if (arr[i-1] == 1 && arr[i+1] == 1) {
						isPossible = false;
						break;
					}
				}
			}

			if (isPossible) {
				System.out.println("YES");
				continue;
			}
			System.out.println("NO");
		}

		scanner.close();
	}
}
