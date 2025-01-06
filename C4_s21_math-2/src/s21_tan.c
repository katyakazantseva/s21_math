#include "s21_math.h"

// long double tan(double x)	вычисляет тангенс
long double s21_tan(double x) {
  long double tan = 0;
  tan = s21_sin(x) / s21_cos(x);
  return tan;
}