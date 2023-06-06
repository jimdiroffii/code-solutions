class Solution {
  public int strStr(String haystack, String needle) {
    /**
     * Find the first occurance of needle in haystack.
     *
     * @param String - the haystack
     * @param String - the needle
     *               return int
     * 
     *               haystack is a long string, needle is a short string
     *               If needle is not in haystack, return -1
     *               The string method indexOf does this automatically.
     */
    return haystack.indexOf(needle);
  }
}