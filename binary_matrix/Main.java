import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int z = 0; z < rounds; z++) {
			String[] parts = scanner.nextLine().split(" "); 
			
			int n = Integer.parseInt(parts[0]);
			int m = Integer.parseInt(parts[1]);

			int[][] matrix = new int[n][m]; 
			for (int i = 0; i < n; i++) {
				int[] row = new int[m];

				String line = scanner.nextLine();
				for(int j = 0; j < line.length(); j++) {
					row[j] = Integer.parseInt(String.valueOf(line.charAt(j)));
				}
			}

			boolean isGood = true;
			int val = -1;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m-1; j++) {
					if (isVal == -1) {
						val = matrix[i][j] ^ matrix[i][j+1];
					} else {
						int temp = matrix[i][j] ^ matrix[i][j+1];
						if (temp != val) {
							isGood = false;
							break;
						}
					}
				}

				if (! isGood) {
					break;
				}
			}

			if (isGood) {
				System.out.println("0");
				return;
			}

			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n-1; j++) {
					if (isVal == -1) {
						val = matrix[j][i] ^ matrix[j+1][i];
					} else {
						int temp = matrix[j][i] ^ matrix[j+1][i];
						if (temp != val) {
							isGood = false;
							break;
						}
					}
				}

				if (! isGood) {
					break;
				}
			}

			if (isGood) {
				System.out.println("0");
				continue;
			}


		}

		scanner.close();
	}

	public static boolean isOK(int y, int x, int rows, int cols, int[][] arr) {
		if (y >= rows || x >= cols) {
			return true;
		}

		// check the row
		boolean isGood = true;
		int val = -1;
		for (int i = 0; i < x-1; i++) {
			if (val != -1) {
				int temp = arr[y][i];
				if (temp != val) {
					isGood = false;
					break;
				}
			} else {
				val = arr[y][i];
			}

			if (! isGood) {
				break;
			}
		}

		if (!isGood) {
			if (arr[y][x] == 1) {
				boolean ok = isOK(arr)
			}
		}

		// check the col
		val = -1;
		for (int i = 0; i < x-1; i++) {
			if (val != -1) {
				int temp = arr[y][x];
				if (temp != val) {
					return false;
				}
			} else {
				val = arr[y][x];
			}
		}
	}
}
