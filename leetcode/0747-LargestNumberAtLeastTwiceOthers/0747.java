class Solution {
  /*
   * Rather than keeping track of the second largest value at the same time,
   * to simplify the problem, we first look for the largest value, then the
   * second largest. We simply keep track of our largest index value seperately
   * and return it if we match the proper condition.
   * Testcases:
   * [0,1]
   * [0,1,2,3]
   * [3,2,1,0]
   * [0,0,100]
   * [100,0,0]
   * [0,1,100]
   * [100,1,0]
   * [5,10,15,20,40,80]
   */
  public int dominantIndex(int[] nums) {
    int largestNum = 0;
    int secondLargest = 0;
    int index = 0;

    for (int i = 0; i < nums.length; i++) {
      if (nums[i] > largestNum) {
        largestNum = nums[i];
        index = i;
      }
    }

    for (int i = 0; i < nums.length; i++) {
      if (nums[i] < largestNum && nums[i] > secondLargest) {
        secondLargest = nums[i];
      }
    }

    if (largestNum / 2 >= secondLargest) {
      return index;
    }

    return -1;
  }
}