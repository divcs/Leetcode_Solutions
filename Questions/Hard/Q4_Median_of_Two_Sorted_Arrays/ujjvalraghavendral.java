import java.util.*;

class Solution {
    // Time Complexity: O(log(min(n1, n2)))
    // Space Complexity: O(1)
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;

        // Ensure nums1 is the smaller array
        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0, high = n1;
        int left = (n1 + n2 + 1) / 2;
        int n = n1 + n2;

        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = left - mid1;
            int l1 = Integer.MIN_VALUE, l2 = Integer.MIN_VALUE;
            int r1 = Integer.MAX_VALUE, r2 = Integer.MAX_VALUE;

            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];

            // Check if we have partitioned correctly
            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1) {
                    return Math.max(l1, l2); // Odd length
                }
                return ((double) (Math.max(l1, l2) + Math.min(r1, r2))) / 2.0; // Even length
            } else if (l1 > r2) {
                high = mid1 - 1; // Move towards left in nums1
            } else {
                low = mid1 + 1; // Move towards right in nums1
            }
        }

        return 0.0; // Should not reach here for valid inputs
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input for first array
        System.out.print("Enter the size of the first array: ");
        int n1 = scanner.nextInt();
        int[] nums1 = new int[n1];
        System.out.println("Enter the elements of the first array (sorted):");
        for (int i = 0; i < n1; i++) {
            nums1[i] = scanner.nextInt();
        }

        // Input for second array
        System.out.print("Enter the size of the second array: ");
        int n2 = scanner.nextInt();
        int[] nums2 = new int[n2];
        System.out.println("Enter the elements of the second array (sorted):");
        for (int i = 0; i < n2; i++) {
            nums2[i] = scanner.nextInt();
        }

        // Finding the median
        Solution sol = new Solution();
        double median = sol.findMedianSortedArrays(nums1, nums2);
        System.out.println("Median: " + median);

        scanner.close();
    }
}
