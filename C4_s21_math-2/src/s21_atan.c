#include "s21_math.h"

// long double atan(double x) вычисляет арктангенс
long double s21_atan(double x) {
  long double atan_sum = 0;
  long double prev_mem = 0;
  long double current_mem = 0;
  if (x >= -1 && x <= 1)
    prev_mem = x;
  else
    prev_mem = 1.0 / x;
  atan_sum = prev_mem;
  register int j = 1;
  if (x == 1 || x == -1)
    atan_sum = x * 0.785398;
  else if (x < -10000300 || x > 10000300)
    atan_sum = 1.570796 * (x > 0 ? 1.0 : -1.0);
  else {
    for (long double i = 1; i < 500000; i = i + 2) {
      if (x > -1 && x < 1)
        current_mem = s21_fabs(prev_mem * x * x / ((i + 2.0) / i));
      else
        current_mem = s21_fabs(prev_mem * (1.0 / (x * x)) / ((i + 2.0) / i));
      if (j % 2 == 0) {
        if (x > 0) {
          atan_sum += current_mem;
          prev_mem = current_mem;
        } else {
          atan_sum -= current_mem;
          prev_mem = -1 * current_mem;
        }
      } else {
        if (x > 0) {
          atan_sum -= current_mem;
          prev_mem = -1 * current_mem;
        } else {
          atan_sum += current_mem;
          prev_mem = current_mem;
        }
      }
      j++;
    }
    if (x <= -1 || x >= 1)
      atan_sum = S21_PI * s21_fabs(x) / (2.0 * x) - atan_sum;
  }
  return atan_sum;
}