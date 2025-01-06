#include <math.h>

#include "s21_math.h"

// long double log(double x)	вычисляет натуральный логарифм
// long double s21_log(double x) {
//   long double a = 1;
//   long double a_0 = 1;
//   long double b = 4.0 / (x * 524288);
//   long double b_0 = 4.0 / (x * 524288);
//   long double M = 0;
//   long double rez = 0;
//   a = (a_0 + b_0) / 2;
//   b = sqrt(a_0*b_0);
//   M = a - b;
//   a_0 = a;
//   b_0 = b;
//   while (M > S21_EPS) {
//     a = (a_0 + b_0) / 2;
//     b = sqrt(a_0*b_0);
//     M = a - b;
//     a_0 = a;
//     b_0 = b;
//   }
//   M = a;
//   rez = S21_PI / (2 * M) - 19 * S21_LN2;
//   return rez;
// }
long double s21_log(double x) {
  long long int ex_pow = 0;
  long double result = 0;
  long double n = 0;
  // long double x = x;

  if (x == 0)
    result = -S21_INF;
  else if (x < 0 || x != x)
    result = S21_NAN;
  else if (x > DBL_MAX)
    result = S21_INF;
  else {
    for (; x >= S21_EXP; x /= S21_EXP) ex_pow++;
    for (register int i = 0; i < 500; i++) {
      n = result;
      result = n + 2 * (x - s21_exp(n)) / (x + s21_exp(n));
      if (n == result) i = 500;
      // printf("result = %Lf\n", result);
    }
    result += ex_pow;
  }
  return (result);
}

// long double s21_log(double x) {
//   long double res = 0;
//   if (x < 0 || x == -S21_INF || x != x) {
//     res = S21_NAN;
//   } else if (x == 0) {
//     res = -S21_INF;
//   } else if (x == S21_INF) {
//     res = S21_INF;
//   } else if (x == 1) {
//     res = 0;
//   } else {
//     double N = 0.0, P = x, A = 0;
//     while (P >= S21_EXP) {
//       P /= S21_EXP;
//       N++;
//     }
//     N += (P / S21_EXP);
//     P = x;
//     int j = 0;
//     do {
//       double L, R;
//       A = N;
//       L = (P / (s21_exp(N - 1.0)));  // exp(x)   на s21_exp(x)
//       R = ((N - 1.0) * S21_EXP);
//       N = ((L + R) / S21_EXP);
//       j++;
//     } while (N != A && j < 10000);
//     res = N;
//   }
//   return res;
// }
