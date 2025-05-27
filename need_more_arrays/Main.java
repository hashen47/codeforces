import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Main {
	public static int getMax(int i, int j, int[] arr, Map<String, Integer> m) {
		if (i > arr.length-1 || j > arr.length-1) {
			return 0;
		}

		String key = Integer.toString(i) + "," + Integer.toString(j);
		Integer val = m.get(key);
		if (val != null) {
			return val;
		}

		if (arr[j] - arr[i] > 1) {
			int v = getMax(j, j+1, arr, m) + 1;
			m.put(key, v);
			return v;
		}

		int a = getMax(i, j+1, arr, m);
		int b = getMax(j, j+1, arr, m);


		if (a > b) {
			m.put(Integer.toString(i) + "," + Integer.toString(j), a);
			return a;
		}
		m.put(Integer.toString(i) + "," + Integer.toString(j), b);
		return b;
	}

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

			Map<String, Integer> m = new HashMap<>();
			int max = 0;
			for (int i = length-1; i > 0; i--) {
				int val = getMax(i-1, i, arr, m);
				if (val > max) {
					max = val;
				}
			}

			System.out.println(max + 1);
		}

		scanner.close();
	}
}
