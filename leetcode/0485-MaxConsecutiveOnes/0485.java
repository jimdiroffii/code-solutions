class Solution {
  public int findMaxConsecutiveOnes(int[] nums) {
    // Return the max number of consecutive 1s in the array
    int max = 0;
    int counter = 0;
    for (int i = 0; i < nums.length; i++) {
      if (nums[i] == 1) {
        counter += 1;
      } else {
        counter = 0;
      }

      if (counter > max) {
        max = counter;
      }
    }

    return max;
  }
}