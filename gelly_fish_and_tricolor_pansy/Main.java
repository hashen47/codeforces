import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		int min = 0;
		for (int z = 0; z < rounds; z++) {
			String[] inputs = scanner.nextLine().split(" ");
			int gelly = Integer.parseInt(inputs[0]);
			int flower = Integer.parseInt(inputs[1]);
			int gelly_night = Integer.parseInt(inputs[2]);
			int flower_night = Integer.parseInt(inputs[3]);

			int gelly_min = gelly <= gelly_night ? gelly : gelly_night; 
			int flower_min = flower <= flower_night ? flower : flower_night; 

			if (gelly_min >= flower_min) {
				System.out.println("Gellyfish");
				continue;
			}

			System.out.println("Flower");
		}

		scanner.close();
	}
}
