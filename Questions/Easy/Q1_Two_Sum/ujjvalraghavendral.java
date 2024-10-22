import java.util.*;

class Main {
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> numMap = new HashMap<>();
        int size = nums.length;

        for (int i = 0; i < size; i++) {
            int pairNum = target - nums[i];
            if (numMap.containsKey(pairNum)) {
                return new int[] { numMap.get(pairNum), i };
            }
            numMap.put(nums[i], i);
        }
        return new int[] { -1, -1 }; // If no solution is found
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the size of the array
        System.out.print("Enter the number of elements in the array: ");
        int n = scanner.nextInt();

        // Read the elements of the array
        int[] nums = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }

        // Read the target value
        System.out.print("Enter the target value: ");
        int target = scanner.nextInt();

        // Create an instance of Main and call the twoSum method
        Main mainInstance = new Main();
        int[] result = mainInstance.twoSum(nums, target);

        // Output the result
        if (result[0] != -1) {
            System.out.println("Indices of the two numbers that add up to " + target + ": " +
                    result[0] + ", " + result[1]);
        } else {
            System.out.println("No two numbers add up to the target.");
        }

        // Close the scanner
        scanner.close();
    }
}
