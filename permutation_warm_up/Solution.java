import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int z = 0; z < rounds; z++) {
			int size = Integer.parseInt(scanner.nextLine());

			int max = 0;
			int j = 1;
			for (int i = size; i > 0; i--) {
				int val = i-j;
				if (val < 0) {
					val *= -1;
				}
				max += val;
				j++;
			}

			System.out.println(max/2 + 1);
		}

		scanner.close();
	}
}
