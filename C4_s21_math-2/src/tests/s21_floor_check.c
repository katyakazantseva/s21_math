#include "s21_math_check.h"

START_TEST(s21_floor_test_zero_neg_zero) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 1e-6);
  double x_1 = S21_NEGZERO;
  ck_assert_ldouble_eq_tol(s21_floor(x_1), floor(x_1), 1e-6);
}
END_TEST

START_TEST(s21_floor_test_NAN) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_floor(x));
}
END_TEST

START_TEST(s21_floor_test_1) {
  for (double i = 0; i <= 5000; i++) {
    ck_assert_ldouble_eq_tol(s21_floor(i), floor(i), 1e-6);
  }
  for (double j = 0; j >= -5000; j--) {
    ck_assert_ldouble_eq_tol(s21_floor(j), floor(j), 1e-6);
  }
}
END_TEST

START_TEST(s21_floor_test_2) {
  for (double i = 0; i <= 100; i = i + 0.01) {
    ck_assert_ldouble_eq_tol(s21_floor(i), floor(i), 1e-6);
  }
  for (double j = 0; j >= -100; j = j - 0.01) {
    ck_assert_ldouble_eq_tol(s21_floor(j), floor(j), 1e-6);
  }
}
END_TEST

START_TEST(s21_floor_test_MIN) {
  double x = LLONG_MAX;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 1e-6);
  double x_1 = DBL_MIN;
  ck_assert_ldouble_eq_tol(s21_floor(x_1), floor(x_1), 1e-6);
}
END_TEST

START_TEST(s21_floor_test_INF) {
  double x = S21_INF;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
  double x_1 = -S21_INF;
  ck_assert_ldouble_eq(s21_floor(x_1), floor(x_1));
}
END_TEST

Suite *s21_floor_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_floor");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_floor_test_zero_neg_zero);
  tcase_add_test(tc_core, s21_floor_test_NAN);
  tcase_add_test(tc_core, s21_floor_test_1);
  tcase_add_test(tc_core, s21_floor_test_2);
  tcase_add_test(tc_core, s21_floor_test_MIN);
  tcase_add_test(tc_core, s21_floor_test_INF);
  suite_add_tcase(s, tc_core);

  return s;
}
