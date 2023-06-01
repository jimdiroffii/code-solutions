class Solution {
  public int findNumbers(int[] nums) {
    // Given an array nums of integers, return how many of them contain an even
    // number of digits.
    int count = 0;
    for (int i = 0; i < nums.length; i++) {
      String s = String.valueOf(nums[i]);
      if (s.length() % 2 == 0) {
        count += 1;
      }
    }

    return count;
  }
}