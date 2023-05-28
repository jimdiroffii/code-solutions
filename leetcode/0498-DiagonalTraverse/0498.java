class Solution {
  public int[] findDiagonalOrder(int[][] mat) {
    /*
     * The objective is to receive a 2D array, and return a
     * 1D array with the elements printed in a "diagonal" order.
     *
     * In this case, diagonal means to traverse every element
     * starting with the first and second elements, in a back
     * and forth diagonal fashion.
     * 
     * 
     * | 1 | 2 | 3 |
     * | 4 | 5 | 6 |
     * | 7 | 8 | 9 |
     *
     * In a 3x3 square, the correct output is:
     * [1,2,4,7,5,3,6,8,9]
     *
     * Edge cases:
     * - Single square
     * - Single row
     * - Single column
     *
     * How to move:
     * - We always start with index 0
     * - if, there is no other element, return the element
     * - If there is no element to the right, the input is a single column,
     * - and the output is that column in order.
     * - If there is an element to the right, that is our move.
     * - Our next move is back one and down one
     * - If there is no element there, the input is a single row to output in order
     *
     * Testcases:
     * [[1,2],[3,4],[5,6]]
     * [[1,2,3],[4,5,6]]
     * [[1,2,3],[4,5,6],[7,8,9],[10,11,12]]
     * [[5]]
     * [[1,7,3]]
     */

    int[] answer = new int[mat.length * mat[0].length];

    // // Single element
    // if (answer.length == 1) {
    // answer[0] = mat[0][0];
    // return answer;
    // }

    // // Single row
    // if (mat.length == 1) {
    // for (int i = 0; i < mat[0].length; i++) {
    // answer[i] = mat[0][i];
    // }
    // return answer;
    // }

    // // Single column
    // if (mat[0].length == 1) {
    // for (int i = 0; i < mat.length; i++) {
    // answer[i] = mat[i][0];
    // }
    // return answer;
    // }

    // This for loop routine reprints the 3D array into a 2D array
    // but does so in a linear fashion.
    // for (int i = 0; i < mat.length; i++) {
    // for (int j = 0; j < mat[i].length; j++) {
    // answer[((mat.length - 1) * i) + j] = mat[i][j];
    // }
    // }

    // The algorithm we need will be very similar in nature, but
    // needs to go back and forth across the grid. There is a pattern
    // of going down and to the left, and up and to the right. All
    // grids will start with this pattern.
    // After starting with 1 and 2, we go down and left one at a time
    // until we reach the left edge or bottom edge. Then we go down one more if we
    // can,
    // and come back up one at a time until the top or right edge.
    // This repeats until the final square is accessed.

    int row = 0;
    int col = 0;
    boolean isUp = true;
    boolean isTEdge = false; // top
    boolean isBEdge = false; // bottom
    boolean isREdge = false; // right
    boolean isLEdge = false; // left

    for (int i = 0; i < answer.length; i++) {
      // Record element
      answer[i] = mat[row][col];

      // Edge detection
      if (row - 1 < 0) {
        isTEdge = true;
      } else {
        isTEdge = false;
      }
      if (row + 1 >= mat.length) {
        isBEdge = true;
      } else {
        isBEdge = false;
      }
      if (col - 1 < 0) {
        isLEdge = true;
      } else {
        isLEdge = false;
      }
      if (col + 1 >= mat[0].length) {
        isREdge = true;
      } else {
        isREdge = false;
      }

      // Determining movement
      //
      // There is an interesting trick here, which is that when you are
      // moving up and to the right, the right edge takes precedence,
      // Where as, when moving down and to the left, the bottom edge
      // take precendence.
      if (isREdge == true && isUp == true) {
        row += 1;
        isUp = false;
        continue;
      }
      if (isTEdge == true && isUp == true) {
        col += 1;
        isUp = false;
        continue;
      }
      if (isUp == true) {
        col += 1;
        row -= 1;
        continue;
      }

      // We haven't escaped the loop yet, so we must be moving down
      // Remember the bottom edge takes precendence over the left edge
      if (isBEdge == true) {
        col += 1;
        isUp = true;
        continue;
      }
      if (isLEdge == true) {
        row += 1;
        isUp = true;
        continue;
      }
      col -= 1;
      row += 1;
    }

    return answer;
  }
}
