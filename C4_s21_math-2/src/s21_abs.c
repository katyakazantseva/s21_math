#include "s21_math.h"

// int abs(int x)	вычисляет абсолютное значение целого числа
int s21_abs(int x) {
  if (x < 0) x = -x;
  return x;
}