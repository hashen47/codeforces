import java.util.Scanner;

public class Main {
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

			int height = 0;
			boolean isPossible = true;
			j = 0;
			for (int k = 0; k < length; k++) {
				if (controls[k] == -1) {
					if (obstacles[j] > height) {
						if (obstacles[j] - height == 1) {
							height++;
							controls[k] = 1;
						} else {
							isPossible = false;
							break;
						}
					} else {
						if (obstacles[j] == height) {
							if (obstacles[j+1] > height) {
								if (j+3 <= obstacles.length-1) {
									if (obstacles[j+3] >= height+1) {
										controls[k] = 1;
										height++;
									} else {
										controls[k] = 0;
									}
								} else {
									controls[k] = 0;
								}
							} else if (obstacles[j+1] == height) {
								controls[k] = 0;
							} else {
								isPossible = false;
								break;
							}	
						} else {
							if (obstacles[j+1] > height) {
								if (j+3 <= obstacles.length-1) {
									if (obstacles[j+3] >= height+1) {
										controls[k] = 1;
										height++;
									} else {
										controls[k] = 0;
									}
								} else {
									controls[k] = 0;
								}
							} else if (obstacles[j+1] == height) {
								controls[k] = 0;
							} else {
								isPossible = false;
								break;
							}
						}
					}
				} else {
					if (controls[k] == 1) {
						height++;
					}

					if (obstacles[j] > height) {
						isPossible = false;
						break;
					} else {
						if (obstacles[j+1] < height) {
							isPossible = false;
							break;
						}
					}
				}

				if (!isPossible) {
					break;
				}

				j += 2;
			}

			if (isPossible) {
				for (Integer n: controls) {
					System.out.printf("%d ", n);
				}
				System.out.println();
				continue;
			}

			System.out.println(-1);
		}

		scanner.close();
	}
}
