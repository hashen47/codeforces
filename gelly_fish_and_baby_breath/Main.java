import java.util.Scanner;

public class Main {
	public static final int MOD = 998244353;
	public static final int MAX = 100005;

	public static void main(String[] args) {
		long[] pw = new long[Main.MAX];
		pw[0] = 1;
		for (int i = 1; i < Main.MAX; i++) {
			pw[i] = (pw[i-1] * 2) % Main.MOD;
		}

		Scanner scanner = new Scanner(System.in);
		int rounds = Integer.parseInt(scanner.nextLine());

		for (int z = 0; z < rounds; z++) {
			int length = Integer.parseInt(scanner.nextLine());
			int[] p_array = new int[length];
			int[] q_array = new int[length];

			int x = 0;
			for (String s: scanner.nextLine().split(" ")) {
				p_array[x] = Integer.parseInt(s);
				x++;
			}

			x = 0;
			for (String s: scanner.nextLine().split(" ")) {
				q_array[x] = Integer.parseInt(s);
				x++;
			}

			x = 0;
			int y = 0;
			for (int i = 0; i < length; i++) {
				if (p_array[i] > p_array[x]) {
					x = i;
				}
				
				if (q_array[i] > q_array[y]) {
					y = i;
				}

				if (p_array[x] > q_array[y] || p_array[x] == q_array[y] && q_array[i-x] > p_array[i-y]) {
					System.out.printf("%d ", (pw[p_array[x]] + pw[q_array[i-x]]) % Main.MOD);
				} else {
					System.out.printf("%d ", (pw[q_array[y]] + pw[p_array[i-y]]) % Main.MOD);
				}
			}

			System.out.println("");
		}

		scanner.close();
	}

	public static long generate_pow(long base, long p) {
		long answer = 1;
		base %= MOD;

		while (p > 0) {
			if (p % 2 == 1) answer = (answer * base) % MOD;
			base = (base * base) % MOD;
			p /= 2;
		}

		return answer;
	}
}
