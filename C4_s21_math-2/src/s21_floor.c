#include "s21_math.h"

long double s21_floor(double x) {
  if ((x == 0.0) || (x == S21_NEGZERO) || (x != x) ||
      (s21_fabs(x) == S21_INF)) {
    return x;
  }

  long double int_part = (long long int)x;

  long double fractional_part = s21_fabs(x) - s21_fabs(int_part);

  if (fractional_part == 0) {
    return x;
  }

  else {
    if (x > 0) {
      return int_part;
    } else {
      return int_part - 1;
    }
  }
}