#include "s21_math.h"

// long double fabs(double x)	вычисляет абсолютное значение числа с плавающей
// точкой
long double s21_fabs(double x) {
  if (x < 0) x = -x;
  return x;
}