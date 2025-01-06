#include "s21_math.h"

// long double sin(double x)	вычисляет синус
long double s21_sin(double x) {
  int j = 1;
  long double sin_sum = 0;
  long double prev_mem = 0;
  x = s21_fmod(x, 2 * S21_PI);
  prev_mem = x;
  sin_sum = prev_mem;
  if (x < 0) j = 2;
  for (long double i = 1; i < 500; i = i + 2) {
    if (j % 2 == 0) {
      sin_sum += s21_fabs(prev_mem * x * x / ((i + 1.0) * (i + 2.0)));
      prev_mem = s21_fabs(prev_mem * x * x / ((i + 1.0) * (i + 2.0)));
    } else {
      sin_sum -= s21_fabs(prev_mem * x * x / ((i + 1.0) * (i + 2.0)));
      prev_mem = -1 * s21_fabs(prev_mem * x * x / ((i + 1.0) * (i + 2.0)));
    }
    j++;
  }
  return sin_sum;
}