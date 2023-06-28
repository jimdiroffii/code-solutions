class Solution {
  public int arraySign(int[] nums) {
      /** 
       * 1822: Sign of the Product of an Array
       * 
       * Create a function that returns:
       * 1 if x is positive
       * -1 if x is negative
       * 0 is x is equal to 0
       * x is the product of the array values.
       *
       * Given an int array, compute the product of all array values.
       * Return the sign of the product.
       *
       * Approach:
       * The naive approach is to multiply the product and check the value. 
       * However, this will likely result in integer overflows. 
       * A safer, and faster, method would be to check for negative numbers, 
       * and/or a zero. If a zero exists anywhere, the result is zero. If the 
       * number of negative numbers is odd, the result will be negative. 
       */
       
      // verify the input array is not null or empty
      if (nums == null || nums.length == 0) {
          throw new IllegalArgumentException("Error: Empty or null array");
      }

      int negativeCount = 0;

      // check each element for 0 or negative
      for (int num : nums) {
          if (num == 0) {
              return 0;
          }
          else if (num < 0) {
              negativeCount += 1;
          }
      }
      
      // the even/odd count of negative numbers gives the product sign
      return (negativeCount % 2 == 0) ? 1 : -1;
  }
}