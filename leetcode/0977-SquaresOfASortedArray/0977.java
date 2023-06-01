class Solution {
  public int[] sortedSquares(int[] nums) {
    // Square all elements and sort them in increasing order
    /*
     * int[] answer = new int[nums.length];
     *
     * for (int i = 0; i < nums.length; i++) {
     * answer[i] = nums[i] * nums[i];
     * }
     *
     * Arrays.sort(answer);
     * return answer;
     */

    // The code above is fully working. Now to attempt an O(n) approach.

    // The incoming array is sorted, and may contain negative numbers.
    // Therefore, the head or tail of the array may be our highest square.
    // By using the two pointer method, we can fill our resulting array
    // backwards, always filling in the higher value.
    int[] answer = new int[nums.length];
    int left = 0;
    int right = nums.length - 1;
    int index = answer.length - 1;

    while (left <= right) {
      if (nums[left] * nums[left] > nums[right] * nums[right]) {
        answer[index] = nums[left] * nums[left];
        left++;
      } else {
        answer[index] = nums[right] * nums[right];
        right--;
      }
      index--;
    }

    return answer;
  }
}