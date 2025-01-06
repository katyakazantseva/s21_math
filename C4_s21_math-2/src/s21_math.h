#ifndef COMMON_MODULES_H
#define COMMON_MODULES_H

#include <float.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_PI 3.14159265358979323846264338327950288
#define S21_EXP 2.71828182845904523536028747135266249
#define S21_INF 1.0 / 0.0
#define S21_NAN 0.0 / 0.0
#define S21_EPS 1e-9
#define S21_EPS_EXP 1e-77
#define S21_ASIN_EPS 1e-16
#define S21_NEGZERO -0.0

int s21_abs(int x);  //вычисляет абсолютное значение целого числа
long double s21_atan(double x);  //вычисляет арктангенс
long double s21_acos(double x);  //вычисляет арккосинус
long double s21_asin(double x);  //вычисляет арксинус
long double s21_cos(double x);   //вычисляет арккосинус
long double s21_exp(
    double x);  //возвращает значение e, возведенное в заданную степень
long double s21_fabs(
    double x);  //вычисляет абсолютное значение числа с плавающей точкой
long double s21_log(double x);  //вычисляет натуральный логарифм
long double s21_pow(double base,
                    double exp);  //возводит число в заданную степень
long double s21_sqrt(double x);  //вычисляет квадратный корень
long double s21_sin(double x);   //вычисляет синус
long double s21_tan(double x);   //вычисляет тангенс
long double s21_ceil(double x);  //возвращает ближайшее целое число, не меньшее
                                 //заданного значения
long double s21_floor(double x);  //возвращает ближайшее целое число, не
                                  //превышающее заданное значение
long double s21_fmod(double x,
                     double y);  //остаток операции деления с плавающей точкой
#endif
