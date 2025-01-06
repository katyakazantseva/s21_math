#include <math.h>

#include "s21_math.h"

// long double pow(double base, double exp)	возводит число в заданную
// степень
long double s21_pow(double base, double exp) {
  long double result = 1;
  long double x = base;
  // long long int y = (long long int)exp;  //важно ашалеть

  if (base == 1 || exp == 0)
    result = 1;
  else if (s21_fabs(exp) == S21_INF && base == -1)
    result = 1;
  else if (base != base || exp != exp ||
           (base < 0 && s21_fmod(exp, 1) != 0 && base != -S21_INF &&
            s21_fabs(exp) != S21_INF &&
            s21_fabs(exp) != DBL_MAX)) {  //это вообще норм???
    result = S21_NAN;
  } else if (exp == 1)  //спросить у Амира нужно ли это?
    result = base;
  else if (x < 0) {
    x = -x;
    result = s21_exp((exp)*s21_log(x));
    if (exp != S21_INF) {
      if (base == -S21_INF) {
        if (s21_fmod(exp, 1) == 0 && s21_fmod(exp, 2) != 0) result = -result;
      } else if (((s21_fmod(exp, 2) != 0) && s21_fabs(exp) != DBL_MAX) &&
                 exp != -S21_INF)
        result = -result;
    }
  } else
    result = s21_exp(exp * s21_log(base));
  return result;
}

// long double s21_pow(double base, double exp_1) {
//   long double result = 1;
//   long double x = base;
//   long double exp_1_1 = exp_1;
//   long long int y = (long long int)exp_1;  //важно ашалеть

//   if (base == 1 || exp_1 == 0)
//     result = 1;
//   else if(s21_fabs(exp_1) == S21_INF && base == -1) result = 1;
//   else if (base != base || exp_1 != exp_1 || (base < 0 && fmod(exp_1, 1) != 0
//   &&
//            base != -S21_INF && s21_fabs(exp_1) != S21_INF)) { //это вообще
//            норм???
//     result = S21_NAN;
//   }
//   else if (exp_1 == 1)  //спросить у Амира нужно ли это?
//     result = base;
//   else if (x < 0) {
//     x = -x;
//     result = exp((exp_1)*s21_log(x));
//     if (exp_1 != S21_INF) {
//       if (base == -S21_INF) {
//         if (fmod(exp_1, 1) == 0 && fmod(exp_1, 2) != 0) result = -result;
//       } else if (fmod(exp_1, 2) != 0 && exp_1 != -S21_INF)
//         result = -result;
//     }
//   } else
//     result = exp(exp_1 * s21_log(base));
//   return result;
// }
