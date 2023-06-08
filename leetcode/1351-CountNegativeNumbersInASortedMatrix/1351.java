class Solution {
  public int countNegatives(int[][] grid) {
    /**
     * Count Negative Numbers in a Sorted Matrix
     *
     * Given an m x n matrix sorted in decreasing
     * order, return the number of negative numbers.
     *
     * Constraints:
     * Elements are ints between -100 and 100
     * Grid contains at least 1 element
     *
     * Edge Cases:
     * Single element
     * Single row
     * Single column
     * All negative
     * No negative
     *
     * Approach:
     * The straightforward approach is a brute-force
     * strategy of checking every element and counting
     * the negative values.
     *
     * The brute-force approach has the worst time
     * complexity for all but the edge case where
     * every element is negative. In this case, the
     * brute-force approach actually may have the least
     * overhead.
     * 
     * A binary search would eliminate non-negative
     * elements the fastest in all other cases.
     */

    // // Brute-Force Approach, starting at element 0
    // int count = 0;
    // for (int i = 0; i < grid.length; i++) {
    // for (int j = 0; j < grid[i].length; j++) {
    // if (grid[i][j] < 0) {
    // count += 1;
    // }
    // }
    // }
    // return count;

    // Brute-Force Approach, starting at last element,
    // and breaking the row if an element is nonnegative
    int count = 0;
    for (int row = grid.length - 1; row >= 0; row--) {
      // If the last element is nonnegative, we are done
      if (grid[row][grid[row].length - 1] >= 0) {
        break;
      }

      // Count each negative element
      for (int col = grid[row].length - 1; col >= 0; col--) {
        if (grid[row][col] < 0) {
          count += 1;
        } else {
          break;
        }
      }
    }

    return count;
  }
}
