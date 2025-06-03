import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int z = 0; z < rounds; z++) {
			String line = scanner.nextLine();
			for (int i = 0; i < line.length(); i++) {
				if (i == line.length()-2) {
					System.out.println("i");
					break;
				}
				System.out.print(line.charAt(i));
			}
		}

		scanner.close();
	}
}
