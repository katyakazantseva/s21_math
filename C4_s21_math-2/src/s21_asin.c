#include "s21_math.h"

// long double asin(double x)	вычисляет арксинус
long double s21_asin(double x) {
  long double asin21 = 0;
  if (x >= -1 && x <= 1)
    asin21 = s21_atan(x / (s21_sqrt(1 - x * x)));
  else
    asin21 = S21_NAN;
  return asin21;
}