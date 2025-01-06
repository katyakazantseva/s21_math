#include "s21_math_check.h"

START_TEST(s21_pow_test_zero_neg_zero) {
  double x_ZERO = 0.0;
  double y_NEG_ZERO = -0.0;
  ck_assert_ldouble_eq(s21_pow(x_ZERO, x_ZERO), pow(x_ZERO, x_ZERO));
  ck_assert_ldouble_eq(s21_pow(x_ZERO, y_NEG_ZERO), pow(x_ZERO, y_NEG_ZERO));
  ck_assert_ldouble_eq(s21_pow(y_NEG_ZERO, x_ZERO), pow(y_NEG_ZERO, x_ZERO));
  ck_assert_ldouble_eq(s21_pow(y_NEG_ZERO, y_NEG_ZERO),
                       pow(y_NEG_ZERO, y_NEG_ZERO));
}
END_TEST

START_TEST(s21_pow_test_zero_pow) {
  double x[14] = {1.25, -77.73, 8,  7,        -32,     -33,      2.2,
                  -5.6, -9,     27, -S21_NAN, S21_INF, -S21_INF, S21_NAN};
  double zero = 0;
  double pow_rez = 0;
  for (register int i = 0; i < 13; i++) {
    ck_assert_ldouble_eq_tol(s21_pow(x[i], zero), pow(x[i], zero), 1e-6);
    pow_rez = pow(zero, x[i]);
    if (pow_rez != pow_rez)
      ck_assert_ldouble_nan(s21_pow(zero, x[i]));
    else
      ck_assert_ldouble_eq(s21_pow(zero, x[i]), pow(zero, x[i]));
  }
}
END_TEST

START_TEST(s21_pow_test_neg_zero_pow) {
  double x[14] = {1.25, -77.73, 8,  7,        -53,     72,       2.2,
                  -5.6, -9,     53, -S21_NAN, S21_INF, -S21_INF, S21_NAN};
  double zero = -0;
  double pow_rez = 0;

  for (register int i = 0; i < 12; i++) {
    pow_rez = pow(zero, x[i]);
    ck_assert_ldouble_eq_tol(s21_pow(x[i], zero), pow(x[i], zero), 1e-6);
    if (pow_rez != pow_rez)
      ck_assert_ldouble_nan(s21_pow(zero, x[i]));
    else
      ck_assert_ldouble_eq(s21_pow(zero, x[i]), pow(zero, x[i]));
  }
}
END_TEST

START_TEST(s21_pow_test_NAN) {
  double x_NAN[2] = {S21_NAN, -S21_NAN};
  double y_digit[7] = {7.77, -7.77, S21_INF, -S21_INF, DBL_MAX, DBL_MIN};
  int k = 0;
  for (register int i = 0; i < 2; i++) {
    k = 0;
    for (register int j = 0; j < 6; j++) {
      ck_assert_ldouble_nan(s21_pow(x_NAN[i], y_digit[j]));
      ck_assert_ldouble_nan(s21_pow(y_digit[j], x_NAN[i]));
      if (k < 2) ck_assert_ldouble_nan(s21_pow(x_NAN[i], x_NAN[j]));
      k++;
    }
  }
}
END_TEST

START_TEST(s21_pow_one_base) {
  double one = 1;
  double pow_rez = 0;
  double x[7] = {1, 3.23, -3.23, -S21_NAN, S21_INF, -S21_INF, S21_NAN};
  pow_rez = 0;
  for (register int i = 0; i < 7; i++) {
    pow_rez = pow(x[i], one);
    ck_assert_ldouble_eq_tol(s21_pow(one, x[i]), pow(one, x[i]), 1e-6);
    if (pow_rez != pow_rez)
      ck_assert_ldouble_nan(s21_pow(x[i], one));
    else if (s21_fabs(pow_rez) == s21_fabs(S21_INF))
      ck_assert_ldouble_eq(s21_pow(x[i], one), pow(x[i], one));
    else
      ck_assert_ldouble_eq_tol(s21_pow(x[i], one), pow(x[i], one), 1e-6);
  }
}
END_TEST

START_TEST(s21_pow_neg_one) {
  double one = -1;
  double x[7] = {1, 3.23, -3.23, -S21_NAN, S21_INF, -S21_INF, S21_NAN};
  double pow_rez = 0;
  double pow_rez_1 = 0;
  for (register int i = 0; i < 7; i++) {
    pow_rez = pow(one, x[i]);
    pow_rez_1 = pow(x[i], one);
    if (pow_rez != pow_rez)
      ck_assert_ldouble_nan(s21_pow(one, x[i]));
    else
      ck_assert_ldouble_eq_tol(s21_pow(one, x[i]), pow(one, x[i]), 1e-6);

    if (pow_rez_1 != pow_rez_1)
      ck_assert_ldouble_nan(s21_pow(x[i], one));
    else
      ck_assert_ldouble_eq_tol(s21_pow(x[i], one), pow(x[i], one), 1e-6);
  }
}
END_TEST

START_TEST(s21_pow_test_1) {
  double pow_rez = 0;
  for (double x = 0; x < 6; x += 1) {
    for (double y = 0; y < 12; y += 0.1) {
      ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
    }
  }
  for (double x_1 = -1; x_1 > -6; x_1 -= 0.1) {
    for (double y_1 = 0; y_1 > -23; y_1 -= 0.1) {
      pow_rez = pow(x_1, y_1);
      if (pow_rez != pow_rez)
        ck_assert_ldouble_nan(s21_pow(x_1, y_1));
      else
        ck_assert_ldouble_eq_tol(s21_pow(x_1, y_1), pow(x_1, y_1), 1e-6);
    }
  }
}
END_TEST

START_TEST(s21_pow_test_2) {
  double x = 1000;
  double y = 1000;
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(s21_pow_MAX_MIN_INT) {
  double x_INT_MAX = INT_MAX;
  double y_INT_MIN = INT_MIN;

  ck_assert_ldouble_eq(s21_pow(x_INT_MAX, x_INT_MAX),
                       pow(x_INT_MAX, x_INT_MAX));
  ck_assert_ldouble_eq(s21_pow(x_INT_MAX, y_INT_MIN),
                       pow(x_INT_MAX, y_INT_MIN));
  ck_assert_ldouble_eq(s21_pow(y_INT_MIN, x_INT_MAX),
                       pow(y_INT_MIN, x_INT_MAX));
  ck_assert_ldouble_eq(s21_pow(y_INT_MIN, y_INT_MIN),
                       pow(y_INT_MIN, y_INT_MIN));
}

START_TEST(s21_pow_test_MAX_MIN) {
  double x_DBL[3] = {DBL_MAX, -DBL_MAX, DBL_MIN};
  double pow_rez = 0;

  for (register int i = 0; i < 3; i++) {
    for (register int j = 0; j < 3; j++) {
      pow_rez = pow(x_DBL[i], x_DBL[j]);
      if (pow_rez != pow_rez)
        ck_assert_ldouble_nan(s21_pow(x_DBL[i], x_DBL[j]));
      else if (s21_fabs(pow_rez) == s21_fabs(S21_INF))
        ck_assert_ldouble_eq(s21_pow(x_DBL[i], x_DBL[j]),
                             pow(x_DBL[i], x_DBL[j]));
      else
        ck_assert_ldouble_eq_tol(s21_pow(x_DBL[i], x_DBL[j]),
                                 pow(x_DBL[i], x_DBL[j]), 1e-6);
    }
  }
}
END_TEST

START_TEST(s21_pow_test_INF) {
  double x_INF[2] = {S21_INF, -S21_INF};
  double y_digit[14] = {-22, -17,    0.123, -6.23, 1.11,    2.6,      3,
                        8,   -0.123, 0.777, -0.56, DBL_MAX, -DBL_MAX, DBL_MIN};
  int k = 0;
  for (register int i = 0; i < 2; i++) {
    k = 0;
    for (register int j = 0; j < 14; j++) {
      ck_assert_ldouble_eq(s21_pow(x_INF[i], y_digit[j]),
                           pow(x_INF[i], y_digit[j]));
      ck_assert_ldouble_eq(s21_pow(y_digit[j], x_INF[i]),
                           pow(y_digit[j], x_INF[i]));
      if (k < 2)
        ck_assert_ldouble_eq(s21_pow(x_INF[i], x_INF[j]),
                             pow(x_INF[i], x_INF[j]));
      k++;
    }
  }
}

Suite *s21_pow_suite(void) {
  Suite *s = suite_create("s21_pow");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_pow_test_zero_neg_zero);
  tcase_add_test(tc_core, s21_pow_test_NAN);
  tcase_add_test(tc_core, s21_pow_test_zero_pow);
  tcase_add_test(tc_core, s21_pow_test_neg_zero_pow);
  tcase_add_test(tc_core, s21_pow_one_base);
  tcase_add_test(tc_core, s21_pow_neg_one);
  tcase_add_test(tc_core, s21_pow_test_1);
  tcase_add_test(tc_core, s21_pow_test_2);
  tcase_add_test(tc_core, s21_pow_MAX_MIN_INT);
  tcase_add_test(tc_core, s21_pow_test_MAX_MIN);
  tcase_add_test(tc_core, s21_pow_test_INF);
  tcase_add_test(tc_core, s21_pow_test_zero_pow);
  suite_add_tcase(s, tc_core);

  return s;
}