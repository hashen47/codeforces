import java.util.Scanner;
import java.util.Map;
import java.util.List;
import java.util.HashMap;
import java.util.ArrayList;

public class Solution {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int rounds = Integer.parseInt(scanner.nextLine());
		for (int z = 0; z < rounds; z++) {
			int length = Integer.parseInt(scanner.nextLine());

			boolean isAllSame = true;
			int[] arr = new int[length];
			String[] parts = scanner.nextLine().split(" ");
			for (int j = 0; j < length; j++) {
				if (j != length-1) {
					if (parts[j] != parts[j+1]) {
						isAllSame = false;
					}
				}
				arr[j] = Integer.parseInt(parts[j]);
			}

			if (isAllSame) {
				System.out.println("NO");
				continue;
			}

			if (length == 2) {
				System.out.println("1 2\n");
				continue;
			}

			int first_gcd = -1;
			int second_gcd = -1;
			List<Integer> listOne = new ArrayList<>();
			List<Integer> listTwo = new ArrayList<>();
			boolean isPossible = true;
			for (int i = 0; i < length-1; i++) {
				for (int j = i+1; j < length; j++) {
					int gcd = Solution.get_gcd(arr[i], arr[j]); 
					if (first_gcd == -1) {
						first_gcd = gcd;
						listOne.add(i);
						listOne.add(j);
					} else if (second_gcd == -1) {
						second_gcd = gcd;
						listTwo.add(i);
						listTwo.add(j);
					} else if (gcd == first_gcd) {
						listOne.add(i);
						listOne.add(j);
					} else if (gcd == second_gcd) {
						listTwo.add(i);
						listTwo.add(j);
					} else {
						isPossbile = false; 
					}
				}

				if (isPossible) {
					break;
				}
			}

			if (!isPossible) {
				System.out.println("No");
				continue;
			}

			if (listOne.size() < listTwo.size()) {

			}
		}

		scanner.close();
	}

	public static int get_gcd(int a, int b) {
		if (a == b) {
			return a;
		}

		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}

		while (true) {
			int remainder = b % a;
			if (remainder == 0) {
				return a;
			}
			b = a;
			a = remainder;
		}
	}
}
