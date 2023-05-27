class Solution {
  public int[] plusOne(int[] digits) {
    // Take the incoming array of digits, increase the last digit
    // by one, and send back the resulting array of digits.
    //
    // This is trivial in every case except for one, if the last
    // digit is a 9. In that case, it may be necessary to increase
    // the output array by one element larger than the input. For
    // that to happen, every number in the provided data must be a 9.
    // If that is not the case, one of the elements will increase by
    // 1, and the rest of the 9s turn into 0s.
    //
    // If the input data is all 9s, then the resulting data will be
    // a 1, followed by all 0s.

    // Check for the simplist case, is the last digit is a 9 or not
    if (digits[digits.length - 1] != 9) {
      digits[digits.length - 1] += 1;
      return digits;
    }

    // Last digit must be a 9, check for all 9s condition
    boolean allNines = true;
    for (int i = 0; i < digits.length; i++) {
      if (digits[i] != 9) {
        allNines = false;
      }
    }
    if (allNines == true) {
      int[] answer = new int[digits.length + 1];
      answer[0] = 1;
      for (int i = 1; i < answer.length; i++) {
        answer[i] = 0;
      }
      return answer;
    }

    // The last digit is a nine, but not all elements are 9
    // We need to work backward from the end, finding all of the 9s,
    // change the 9s to 0s, and whatever element is not a 9, increase
    // it by 1.
    int index = digits.length - 1;
    for (int i = digits.length - 1; digits[i] == 9; i--, index--) {
      digits[i] = 0;
    }
    digits[index] += 1;
    return digits;
  }
}