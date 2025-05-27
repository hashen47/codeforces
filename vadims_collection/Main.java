import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int rounds = Integer.parseInt(scanner.nextLine());
		for (int z = 0; z < rounds; z++) {
			int[] arr = new int[10];

			String phoneNumber = scanner.nextLine();
			for (int i = 0; i < phoneNumber.length(); i++) {
				arr[i] = Integer.parseInt(String.valueOf(phoneNumber.charAt(i)));
				// System.out.println(phoneNumber.charAt(i));
			}

			for (int i = 1; i < arr.length-1; i++) {
				boolean isSelected = false;
				int choiceI = i;
				int min = 10-i-1;

				for (int j = i+1; j < arr.length; j++) {
					if (arr[j] >= min) {
						if (arr[choiceI] > arr[j]) {
							// System.out.printf("choice: %d, j: %d\n", arr[choiceI], arr[j]);
							choiceI = j;
							isSelected = true;
						}
					}
				}

				if (isSelected) {
					// System.out.printf("choice: %d, i: %d\n", arr[choiceI], arr[i]);
					int temp = arr[i];
					arr[i] = arr[choiceI]; 
					arr[choiceI] = temp;
				}
			}

			for (int i = 0; i < arr.length; i++) {
				System.out.printf("%d", arr[i]);
			}
			System.out.println("");
		}

		scanner.close();
	}
}
