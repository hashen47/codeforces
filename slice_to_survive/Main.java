import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int rounds = Integer.parseInt(scanner.nextLine());

		for (int i = 0; i < rounds; i++) {
			var parts = scanner.nextLine().split(" ");
			long rows = Long.parseLong(parts[0]);
			long cols = Long.parseLong(parts[1]);
			long y = Long.parseLong(parts[2]);
			long x = Long.parseLong(parts[3]);
			y--;
			x--;

			long turns = 0;
			long leftArea;
			long rightArea;
			long topArea;
			long bottomArea;
			long max;

			while (true) {
				if (rows == 1 && cols == 1) {
					break;
				}

				leftArea = x * rows;
				rightArea = (cols-1-x) * rows;
				topArea = y * cols;
				bottomArea = (rows-1-y) * cols;
				max = leftArea;

				// System.out.printf("rows: %d, cols: %d, x: %d, y: %d\n", rows, cols, x, y);

				if (rightArea > max) {
					max = rightArea; 
				}	

				if (topArea > max) {
					max = topArea; 
				}	

				if (bottomArea > max) {
					max = bottomArea; 
				}	

				if (max == leftArea) {
					cols -= x; 
					x = 0;
				} else if (rightArea == max) {
					cols = x+1;
				} else if (topArea == max) {
					rows -= y; 
					y = 0;
				} else if (bottomArea == max) {
					rows = y+1;
				}

				y = rows/2;
				x = cols/2;

				turns++;
			}

			System.out.println(turns);
		}

		scanner.close();
	}
}
