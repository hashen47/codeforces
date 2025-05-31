import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.HashSet;


/**
 * this solution is write,
 * but not efficient
 * recursive solution is not good for this kind of problems
 * we have to find a pattern
 */
public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int z = 0; z < rounds; z++) {
			int size = Integer.parseInt(scanner.nextLine());

			int total = 0;
			HashSet<Integer> values = new HashSet<>();
			for (int i = 1; i <= size; i++) {
				HashSet<Integer> set = new HashSet<>();
				set.add(i);
				List<Integer> arr = Main.getSums(2, size, set);

				for (int val: arr) {
					val += i-1;
					if (! values.contains(val)) {
						total++;
						values.add(val);
					}
				}
			}

			System.out.println(values);
			System.out.println(total);
		}

		scanner.close();
	}

	public static List<Integer> getSums(int n, int maxN, HashSet<Integer> set) {
		if (n > maxN) {
			return new ArrayList<>();
		}

		List<Integer> newArr = new ArrayList<>();
		for (int i = 1; i <= maxN; i++) {
			if (set.contains(i)) {
				continue;
			}

			set.add(i);
			List<Integer> arr = getSums(n+1, maxN, set);
			set.remove(i);

			int val = i-n; 
			if (val < 0) {
				val *= -1;
			}

			for (var k: arr) {
				newArr.add(k + val);
			}

			if (arr.size() == 0) {
				newArr.add(val);
			}	
		}

		return newArr;
	}
}
