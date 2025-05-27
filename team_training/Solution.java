import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.io.IOException;

public class Solution {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);

        int rounds = Integer.parseInt(scanner.nextLine());

        for (int i = 0; i < rounds; i++) {
            String[] line1 = scanner.nextLine().split(" ");
            int strength = Integer.parseInt(line1[1]);

            int teamCount = 0;
            List<Integer> smallNumbers = new ArrayList<>();

            String[] line2 = scanner.nextLine().split(" ");
            for (String str : line2) {
                int n = Integer.parseInt(str);
                if (n < strength) {
                    smallNumbers.add(n);
                    continue;
                }
                teamCount++;
            }

            Collections.sort(smallNumbers);

            int count = 0;
            int remainingCount = smallNumbers.size();
            for (int j = smallNumbers.size() - 1; j >= 0; j--) {
                int n = smallNumbers.get(j);
                if ((long) n * remainingCount < strength) {
                    remainingCount--;
                    continue;
                }

                count++;

                if ((long) n * count >= strength) {
                    teamCount++;
                    remainingCount -= count;
                    count = 0;
                }
            }

            System.out.println(teamCount);
        }

        scanner.close();
    }
}
