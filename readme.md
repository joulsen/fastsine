# fastsine for Arduino
A small collection of fast sine implementations for Arduino. All functions are found in `fastsine.ino`.

Each function has a relative error of less than 2% except at `sin(0)` where the relative error is undefined.

Each function is only defined for an x such that: `0 < x < PI / 2`

Each function is constructed as a straight line for `0 < x < 0.34` - up until that point the relative error stays below 2%.

Below is a description of each function
## fastsine1
A bruteforced dissection into linear regressions using no fixed points. It is quite bad and not particularly faster than `fastsine3` which works on a similar premise, but is more preicse.

## fastsine2
A model using a straight line and a second order polynomial realized using Horner's method. Thanks to Jonas :)

## fastsine3
Just like `fastsine1` but using fixed points and different coefficients. This requires far less dissection, but each dissection has more computation time. Therefore it is slower in best case, and better in worst case.
