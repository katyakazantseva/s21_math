#include "s21_math.h"

// long double sqrt(double x)	вычисляет квадратный корень
long double s21_sqrt(double x) {
  long double left = 0;
  long double right = 0;
  long double mid = 0;
  if (x == 0)
    mid = 0;
  else if (x < 0)
    mid = S21_NAN;
  else if (x != x)
    mid = S21_NAN;
  else {
    if (x > 1)
      right = x;
    else
      right = 1;

    mid = (left + right) / 2.0;

    while ((mid - left) > S21_EPS) {
      if (mid * mid > x)
        right = mid;
      else
        left = mid;
      mid = (left + right) / 2.0;
    }
  }
  return mid;
}