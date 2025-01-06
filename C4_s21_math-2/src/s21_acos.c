#include "s21_math.h"

// long double acos(double x)	вычисляет арккосинус
long double s21_acos(double x) {
  long double acos21 = 0;
  if (x == 0)
    acos21 = 1.570796;
  else if (x > 0 && x <= 1)
    acos21 = s21_atan(s21_sqrt(1 - x * x) / x);
  else if (x >= -1 && x < 0)
    acos21 = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  else
    acos21 = S21_NAN;
  return acos21;
}
