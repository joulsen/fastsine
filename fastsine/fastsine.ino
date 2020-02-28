/* Information:
 * Written by Andreas P. (www.github.com/supercigar) for the Digital Design course.
 * Also, thanks to Jonas J. for the math behind fastsine2
 * Both functions are faster than the default sine function from Arduino - even in worst case.
 * Both functions have a relative error of less than 2%, except at x = 0, where the relative
 * error goes toward infinity.
* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE":
 * <ajpo18@student.aau.dk> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. - ANdreas P.
 * ----------------------------------------------------------------------------
 */

/* fastsine1:
 * A lot of if statements and some linear relationships without points or 
 * compensation. The coefficients are brute forced such that relative error
 * never goes below 2%. Worst case for any x > 1.54.
 */
float fastsine1(float x) {
  if (x < 0.34) {
    return x;
  }
  if (x < 0.58) {
    return 0.965*x;
  }
  if (x < 0.74) {
    return 0.927*x;
  }
  if (x < 0.89) {
    return 0.890*x;
  }
  if (x < 1.01) {
    return 0.855*x;
  }
  if (x < 1.12) {
    return 0.820*x;
  }
  if (x < 1.21) {
    return 0.785*x;
  }
  if (x < 1.31) {
    return 0.753*x;
  }
  if (x < 1.39) {
    return 0.720*x;
  }
  if (x < 1.47) {
    return 0.692*x;
  }
  if (x < 1.54) {
    return 0.662*x;
  }
  if (x < 1.7) {
    return 0.632*x;
  }
}

/* fastsine2:
 * Implemented using a straight line and a second order polynomial.
 * The second order polynomial is realized using Horner's method.
 * Thanks to Jonas J.
 */
// Sinus implemented using a second order polynomial.
float fastsine2(float x) {
  if (x < 0.34) {
    return x;
  }
  if (x < 0.84) {
    return -0.15 * x * x + x + 0.011;
  }
  return -0.08 + x * (1.32 + x * (-0.4));
  //return -0.4 * x * x + 1.32 * x - 0.08;
}

/* fastsine3:
 * Implemented using tangents with their coefficients and
 * their starting points. Worst case x > 1.6. Slower than
 * fastsine1 for mixed cases, but way faster for worst case.
 */
float fastsine3(float x) {
  if (x < 0.34) {
    return x;
  }
  if (x < 0.61) {
    return 0.33 + 0.94 * (x-0.34);
  }
  if (x < 0.85) {
    return 0.57 + 0.82 * (x-0.61);
  }
  if (x < 1.07) {
    return 0.75 + 0.66 * (x-0.85);
  }
  if (x < 1.26) {
    return 0.88 + 0.48 * (x-1.07);
  }
  if (x < 1.47) {
    return 0.95 + 0.31 * (x-1.26);
  }
  if (x < 1.6) {
    return 0.99 + 0.10 * (x-1.47);
  }
}
