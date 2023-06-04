class Solution {
  public String mergeAlternately(String word1, String word2) {
    /*
     * Merge Strings Alternately
     * 
     * Given two strings, return a merged string, created by
     * alternating characters. If one word is longer, just append
     * the rest of the word.
     */
    // String mergedString = "";
    StringBuilder sb = new StringBuilder();
    for (int i = 0, j = 0, k = 0; j < word1.length() && k < word2.length(); i++) {
      if (i % 2 == 0) {
        // mergedString += word1.charAt(j);
        sb.append(word1.charAt(j));
        j++;
      } else {
        // mergedString += word2.charAt(k);
        sb.append(word2.charAt(k));
        k++;
      }
      if (j >= word1.length()) {
        // mergedString += word2.substring(k);
        sb.append(word2.substring(k));
      } else if (k >= word2.length()) {
        sb.append(word1.substring(j));
      }
    }
    // return mergedString;
    return sb.toString();
  }
}