class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        /**
         * Find Smallest Letter Greater Than Target
         * 
         * You are given an array of characters, letters[], that is sorted
         * in non-decreasing order, and a character, target. There are
         * at least two different characters in letters.
         *
         * Return the smallest character in letters that is
         * lexicographically greater than target. If such a character
         * does not exist, return the first character in letters.
         *
         * Constraints:
         * 2 <= letters.length <= 10^4
         * letters[i] is a lowercase English letter
         * letters is sorted in non-decreasing order
         * letters contains at least two different characters
         * target is a lowercase English letter
         *
         * Edge Cases:
         * letters contains more than one of a single character
         * letters contains the same character for all elements
         * 
         * In Java, char values can be implicitly converted to int values.
         * The incoming letters array is sorted, so we could possibly take
         * advantage of this and use a search algorithm to find a starting
         * place that makes sense given our target.
         * 
         * Otherwise, we can just brute force search the array for the
         * target value.
         */

        // // Brute-Force Approach
        // // First we need to try to find a value greater than the target value
        // for (int i = 0; i < letters.length; i++) {
        // if (letters[i] > target) {
        // return letters[i];
        // }
        // }
        // // Any value greater than target was not found, return first letter
        // return letters[0];

        // Binary Search Approach
        int left = 0;
        int right = letters.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (left == letters.length) {
            return letters[0];
        }

        return letters[left];
    }
}