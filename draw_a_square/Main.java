import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int z = 0; z < rounds; z++) {
			// left, right, down, up
			int[] dims = new int[4];

			int j = 0;
			for (String s: scanner.nextLine().split(" ")) {
				dims[j] = Integer.parseInt(s);
				j++;
			}

			boolean isPossible = true;
			for (int i = 0; i < dims.length-1; i++) {
				if (dims[i] != dims[i+1]) {
					isPossible = false;
					break;
				}
			}

			if (!isPossible) {
				System.out.println("NO");
				continue;
			}

			System.out.println("YES");
		}

		scanner.close();
	}
}
