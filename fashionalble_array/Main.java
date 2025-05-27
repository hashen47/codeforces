import java.util.Scanner;
import java.util.Arrays;


public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int rounds = Integer.parseInt(scanner.nextLine());

		for (int i = 0; i < rounds; i++) {
			int length = Integer.parseInt(scanner.nextLine());
			int[] arr = new int[length];

			int I = 0;
			for (String s: scanner.nextLine().split(" ")) {
				arr[I] = Integer.parseInt(s);
				I++;
			}

			Arrays.sort(arr);

			int min = length+1;
			for (int j = 0; j < length; j++) {
				int turns = j;
				for (int k = length-1; k >= j; k--) {
					// System.out.printf("j: %d, k: %d\n", j, k);
					if ((arr[j] + arr[k]) % 2 == 0) {
						if (min > turns) {
							min = turns;
							turns = 0;
							break;
						}
					}
					turns++;
				}
			}
			System.out.println(min);
		}
		
		scanner.close();
	}
}
