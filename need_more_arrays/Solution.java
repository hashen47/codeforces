import java.util.Scanner;

/**
 * this is the correct answer to the question
 * you don't even have to go to the recursive one
 * Main.java one is not needed
 */
public class Solution {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int z = 0; z < rounds; z++) {
			int length = Integer.parseInt(scanner.nextLine());

			int[] arr = new int[length];
			int k = 0;
			for (String s: scanner.nextLine().split(" ")) {
				arr[k] = Integer.parseInt(s);
				k++;
			}

			if (length == 1) {
				System.out.println(1);
				continue;
			}

			int arrayCount = 1;
			int i = 0;
			while (i < arr.length-1) {
				k = i+1;
				while (true) {
					if (k >= arr.length) {
						i = k;
						break;
					}
					if (arr[i] + 1 < arr[k]) {
						arrayCount++;
						i = k;
						break;
					}
					k++;
				}
			}

			System.out.println(arrayCount);
		}

		scanner.close();
	}
}
