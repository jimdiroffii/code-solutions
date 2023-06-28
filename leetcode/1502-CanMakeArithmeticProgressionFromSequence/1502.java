class Solution {
  public boolean canMakeArithmeticProgression(int[] arr) {
    /**
     * 1502: Can Make Arithmetic Progression From Sequence
     * A sequence of numbers is called an arithmetic progression
     * if the difference between any two consecutive elements is
     * the same. Given an array of numbers arr, return true if
     * the array can be rearranged to form an arithmetic progression.
     * Otherwise, return false.
     *
     * Approach:
     * Sort the array using built in sort, then calculate the differences
     * between values. If there is any deviation in the difference, return false.
     */
    if (arr == null || arr.length == 0) {
      throw new IllegalArgumentException("Error: Array is null or empty");
    }

    Arrays.sort(arr);

    // calculate initial difference
    int diff = arr[1] - arr[0];

    for (int i = 1; i < arr.length - 1; i++) {
      if (arr[i + 1] - arr[i] != diff) {
        // return immediately if any deviation found
        return false;
      }
    }

    // we never escaped, so the diff must be the same between all values
    return true;
  }
}
