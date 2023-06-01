class Solution {
  public int pivotIndex(int[] nums) {
    int index = 0;
    int lSum = 0;
    int rSum = addArrayNums(index + 1, nums.length - 1, nums);

    while (lSum != rSum && index <= nums.length - 1) {
      index += 1;
      lSum = addArrayNums(0, index - 1, nums);
      rSum = addArrayNums(index + 1, nums.length - 1, nums);
    }

    if (index == nums.length) {
      return -1;
    }

    return index;
  }

  static int addArrayNums(int startingIndex, int endingIndex, int[] numArr) {
    int sum = 0;
    for (int i = startingIndex; i <= endingIndex; i++) {
      sum = sum + numArr[i];
    }

    return sum;
  }
}
