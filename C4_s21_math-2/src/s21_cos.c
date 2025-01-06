#include "s21_math.h"

// long double cos(double x)	вычисляет косинус
long double s21_cos(double x) {
  long double cos_sum = 0;
  long double prev_mem = 0;

  x = s21_fmod(x, 2 * S21_PI);

  cos_sum = -1 * x * x / 2.0;
  prev_mem = cos_sum;
  cos_sum += 1;
  register int j = 0;
  for (register int i = 2; i < 500; i = i + 2) {
    if (j % 2 == 0) {
      cos_sum += s21_fabs(prev_mem * x * x / ((i + 1) * (i + 2)));
      prev_mem = s21_fabs(prev_mem * x * x / ((i + 1) * (i + 2)));
    } else {
      cos_sum -= s21_fabs(prev_mem * x * x / ((i + 1) * (i + 2)));
      prev_mem = -1 * s21_fabs(prev_mem * x * x / ((i + 1) * (i + 2)));
    }
    j++;
  }
  return cos_sum;
}