class Solution {
  public boolean checkStraightLine(int[][] coordinates) {
    /*
     * Check if it is a Straight Line
     * 
     * A line drawn between two points is always straight.
     * A straight line has a constant slope.
     * Only checking a couple line segments is not sufficient,
     * so every segment must be checked for straightness and
     * continuity.
     *
     * We are guarenteed at least two coordinates given as an
     * XY pair, and there are guarenteed to be no duplicates.
     *
     * If a line is drawn from the first point to the last point,
     * all provided points must exist on this line for it to be straight.
     * 
     * Slope-Intercept: y = mx + b.
     * Point-Slope Form: y - y1 = m(x - x1)
     * [x,y] are the coordinates.
     * m is the slope
     * b is the y-intercept
     * Slope is (y2 - y1) / (x2 - x1)
     * Regardless of where the line is located, for this problem,
     * we can continually calculate slopes between each point. If
     * the slope diverges at any point, the line is no longer straight.
     *
     * I see some potential for inaccuracy here, if there is a rounding
     * error or something that causes the slope calculates to differ when
     * they should be equivilent. A way of comparing exact values would
     * be preferred.
     */
    double slopeReference = 0.0;
    double slopeCalculation = 0.0;

    // Any need to divide by zero is undefined, and means we have a vertical line.
    // To represent the vertical line, we use the POSITIVE_INFINITY value.
    // A slope of zero means a horizontal line.
    // A vertical line will always have the same x values.
    // A horizontal line will always have the same y values.
    if ((coordinates[coordinates.length - 1][0] - coordinates[0][0]) != 0) {
      slopeReference = ((double) (coordinates[coordinates.length - 1][1] - coordinates[0][1]) /
          (coordinates[coordinates.length - 1][0] - coordinates[0][0]));
    } else {
      slopeReference = Double.POSITIVE_INFINITY;
    }

    // Now that we have the slope, check each line segment
    for (int i = 0; i < coordinates.length - 1; i++) {
      if ((coordinates[i + 1][0] - coordinates[i][0]) != 0) {
        slopeCalculation = ((double) (coordinates[i + 1][1] - coordinates[i][1]) /
            (coordinates[i + 1][0] - coordinates[i][0]));
      } else {
        slopeCalculation = Double.POSITIVE_INFINITY;
      }

      if (slopeCalculation != slopeReference) {
        return false;
      }
    }

    // System.out.println(slopeReference);
    return true;
  }
}