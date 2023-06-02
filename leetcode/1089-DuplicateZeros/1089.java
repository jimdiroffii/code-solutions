class Solution {
  public void duplicateZeros(int[] arr) {
    /*
     * Duplicate Zeroes
     * 
     * Given a fixed-length int arr, duplicate each occurance of zero,
     * shifting the remaining elements to the right.
     *
     * Make all adjustments in place, and do not return anything.
     *
     * Thoughts:
     * The idea is simple enough, but there is a interesting condition
     * that doesn't seem clear. What if the array only contains zeroes?
     * Each zero should be duplicated, but the array isn't extended.
     * That isn't going to work. The expectation in this case is that
     * we basically do nothing. So, in any case where the input array
     * is all zeroes, nothing needs to be done.
     * So, the zeroes only matter if there is any other number as an
     * element after a zero.
     */

    // Try to handle the single zero test case
    // if (arr[0] == 0) {
    // return;
    // }

    for (int i = 0; i < arr.length; i++) {
      // if the value isn't zero, skip
      if (arr[i] != 0) {
        continue;
      }

      // we must have a zero, so we need to handle it completely
      // we need to shift all the elements, the last run of the
      // loop with add the duplicate zero
      for (int j = arr.length - 1; j > i; j--) {
        arr[j] = arr[j - 1];
      }

      // we also need to skip the added zero, so we don't add
      // another one
      i++;
    }

    return;
  }
}