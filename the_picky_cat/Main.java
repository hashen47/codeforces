import java.util.Scanner;
import java.util.Arrays;

public class Main {
	public static boolean isPossible(int[] arr) {
		int median = arr[0];

		Arrays.sort(arr);

		if (arr[arr.length/2] == median) {
			System.out.println("YES");
			return true;
		}

		int index = -1;
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] == median) {
				index = i;
				break;
			}
		}

		if (index < arr.length/2) {
			if (median >= 0) {
				System.out.println("YES");
				return true;
			}

			int positiveCount = 0;
			for (int j = index+1; j < arr.length; j++) {
				if (arr[j] * -1 < median) {
					positiveCount++;
				}
			}	

			if (positiveCount >= (arr.length/2)-index) {
				System.out.println("YES");
				return true;
			}
		} else {
			if (median <= 0) {
				System.out.println("YES");
				return true;
			}

			int negativeCount = 0;
			for (int j = 0; j < index; j++) {
				if (arr[j] * -1 > median) {
					negativeCount++;
				}
			}	

			if (negativeCount >= index-(arr.length/2)) {
				System.out.println("YES");
				return true;
			}
		}

		return false;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int i = 0; i < rounds; i++) {
			int length = Integer.parseInt(scanner.nextLine());

			int[] arr = new int[length];
			int index = 0;
			String[] numbers = scanner.nextLine().split(" ");
			for (String s: numbers) {
				arr[index] = Integer.parseInt(s);
				index++;
			}

			if (!isPossible(arr.clone())) {
				int[] copyArr = arr.clone();
				copyArr[0] *= -1;
				if (!isPossible(copyArr)) {
					System.out.println("NO");
				}
			}
		}

		scanner.close();
	}
}
