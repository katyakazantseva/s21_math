#include "math.h"
#include "s21_math.h"

//возвращает ближайшее целое число, не меньшее заданного значения
long double s21_ceil(double x) {
  long double ceil = 0;
  long double x_mod = 0;
  x_mod = fmod(x, (long long int)x);
  if (x_mod == 0)
    ceil = x;
  else {
    if (x >= 0) {
      ceil = x - x_mod + 1;
    } else {
      ceil = x - x_mod;
    }
  }
  return ceil;
}