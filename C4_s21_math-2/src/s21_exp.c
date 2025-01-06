#include "s21_math.h"

// long double exp(double x) возвращает значение e, возведенное в заданную
// степень
long double s21_exp(double x) {
  long double e = 1;
  long double prev_mem = 1;
  if (x > 777)
    e = S21_INF;
  else if (x < -22)
    e = 0;
  else {
    for (long double i = 1; s21_fabs(prev_mem) > S21_EPS_EXP && i != 0;
         i += 1) {
      prev_mem *= x / i;
      e += prev_mem;
      if (e > DBL_MAX) {
        e = S21_INF;
        prev_mem = S21_EPS_EXP;
      }
    }
  }
  return e;
}