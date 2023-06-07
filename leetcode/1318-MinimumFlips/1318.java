class Solution {
  public int minFlips(int a, int b, int c) {
    /**
     * Minimum Flips to Make (a | b) == c
     *
     * The OR operation is a bitwise operation.
     * Bitwise OR Table:
     * 00 = 0
     * 01 = 1
     * 10 = 1
     * 11 = 1
     *
     * Constraints:
     * All numbers are 1 or greater
     *
     * Edge Cases:
     * Input values already solve OR operation
     */
    int totalFlips = 0;

    // Loop over the 32-bit integers
    for (int i = 0; i < 32; i++) {
      // Store each bit value
      int bitA = (a >> i) & 1;
      int bitB = (b >> i) & 1;
      int bitC = (c >> i) & 1;

      // // If bitC is 1, we need a flip if both bitA and bitB are 0
      // if (bitC == 1) {
      // if (bitA == 0 && bitB == 0) {
      // totalFlips += 1;
      // }
      // }
      // // If bitC is 0, we need to flip any 1 in bitA and bitB
      // else {
      // totalFlips += bitA + bitB;
      // }

      // Branchless method
      /**
       * bitC & (bitA ^ 1) & (bitB ^ 1) counts the number of flips needed when bitC is
       * 1 but both bitA and bitB are 0. The expression (bitA ^ 1) & (bitB ^ 1)
       * evaluates to 1 only when both bitA and bitB are 0, and then we use bitwise
       * AND with bitC to count only when bitC is 1.
       * 
       * (bitC ^ 1) * (bitA + bitB) counts the number of flips needed when bitC is 0
       * but either bitA or bitB (or both) are 1. The expression (bitC ^ 1) evaluates
       * to 1 when bitC is 0, and bitA + bitB counts the number of 1 bits in a and b.
       * Multiplying these two results gives the number of flips needed in this case.
       */
      totalFlips += (bitC & (bitA ^ 1) & (bitB ^ 1)) + ((bitC ^ 1) * (bitA + bitB));
    }

    return totalFlips;
  }
}
