#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double fmod = 0;
  if (x == S21_INF || x == -S21_INF || x == S21_NAN || y == S21_NAN)
    fmod = S21_NAN;
  else if (y == 0)
    fmod = S21_NAN;
  else if ((x > 0 && y > 0) && (y > x || y == S21_INF || y == -S21_INF))
    fmod = x;
  else {
    long long int n = 0;
    n = (x / y);
    fmod = (long double)x - n * (long double)y;
    // if(fmod == 0 && (y / (y - y_accurcy) != )) fmod = y;
  }
  // if ((fmod == 0 || fmod < 0.00001 )&& y < 1 && x >= 2.1 && x < 16.1) fmod =
  // y;
  return fmod;
}
// long double s21_fmod(double x, double y) {
//   long double res = 0;
//   if (s21_is_nan(x) || s21_is_nan(y) || s21_is_inf(x) || y == 0) {
//     res = S21_NAN;
//   } else if (s21_is_inf(y)) {
//     res = x;
//   } else
//   if (x == 0.0 && y != 0) {
//     res = 0.0;
//   } else {
//     if (x < 0 || y < 0) {
//       res = -s21_abs(x / y);
//     } else {
//       res = s21_abs(x / y);
//     }
//     res = x - res * y;
//   }
//   return res;
// }
