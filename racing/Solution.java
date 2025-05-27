import java.util.Scanner;


public class Solution {
	static class Data {
		public int[] controls;
		public boolean can;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int i = 0; i < rounds; i++) {
			int length = Integer.parseInt(scanner.nextLine());
			int[] controls = new int[length];
			int[] obstacles = new int[2 * length];

			int j = 0;
			for (String s: scanner.nextLine().split(" ")) {
				controls[j] = Integer.parseInt(s);
				j++;
			}

			j = 0;
			for (int k = 0; k < length; k++) {
				for (String s: scanner.nextLine().split(" ")) {
					obstacles[j] = Integer.parseInt(s);
					j++;
				}
			}

			Data answer = Solution.canWin(controls.clone(), obstacles, 0, 0, 0);
			if (answer.can) {
				for (Integer n: answer.controls) {
					System.out.printf("%d ", n);
				}
				System.out.println();
				continue;
			}
			System.out.println(-1);
		}

		scanner.close();
	}

	public static Data canWin(int[] controls, int[] obstacles, int k, int height, int j) {
		if (k >= controls.length) {
			var d = new Data();
			d.can = true;
			d.controls = controls;
			return d;
		}

		if (controls[k] != -1) {
			height += controls[k]; 
			if (obstacles[j] <= height && height <= obstacles[j+1]) {
				return Solution.canWin(controls, obstacles, k+1, height, j+2);
			}
			var d = new Data();
			d.can = false;
			return d;
		}

		if (obstacles[j] > height) {
			if (obstacles[j] - height == 1) {
				controls[k] = 1;
				var one =  Solution.canWin(controls, obstacles, k+1, height+1, j+2);
				if (one.can) {
					return one;
				} else {
					controls[k] = 0;
				}
			}
			var d = new Data();
			d.can = false;
			return d;
		} else if (obstacles[j] == height) {
			if (obstacles[j+1] > height) {
				controls[k] = 1;
				var two = Solution.canWin(controls, obstacles, k+1, height+1, j+2);
				if (two.can) {
					return two;
				}
				
				controls[k] = 0;
				var one = Solution.canWin(controls, obstacles, k+1, height, j+2);
				if (one.can) {
					return one;
				}

				controls[k] = -1;
				var d = new Data();
				d.can = false;
				return d;
			} else if (obstacles[j] == height) {
				controls[k] = 0;
				return Solution.canWin(controls, obstacles, k+1, height, j+2);
			}

			var d = new Data();
			d.can = false;
			return d;
		} else {
			if (obstacles[j+1] > height) {
				if (j+3 <= obstacles.length-1) {
					if (obstacles[j+3] >= height+1) {
						controls[k] = 1;
						var one = Solution.canWin(controls, obstacles, k+1, height+1, j+2);
						if (one.can) {
							return one;
						}

						controls[k] = 0;
						var two = Solution.canWin(controls, obstacles, k+1, height, j+2);
						if (two.can) {
							return two;
						}
					}
				}
				controls[k] = 0;
				return Solution.canWin(controls, obstacles, k+1, height, j+2);
			} else if (obstacles[j+1] == height) {
				controls[k] = 0;
				return Solution.canWin(controls, obstacles, k+1, height, j+2);
			}

			var d = new Data();
			d.can = false;
			return d;
		}
	}
}
