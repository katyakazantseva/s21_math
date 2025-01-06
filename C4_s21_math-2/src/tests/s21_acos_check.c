#include "s21_math_check.h"

START_TEST(s21_acos_test_zero_neg_zero) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), 1e-6);
  double x_1 = -0.0;
  ck_assert_ldouble_eq_tol(s21_acos(x_1), acos(x_1), 1e-6);
}
END_TEST

START_TEST(s21_acos_test_NAN) {
  double x = 1.1;
  ck_assert_ldouble_nan(s21_acos(x));
  double x_1 = -1.1;
  ck_assert_ldouble_nan(s21_acos(x_1));
  double x_2 = S21_NAN;
  ck_assert_ldouble_nan(s21_acos(x_2));
  double x_3 = S21_NAN;
  ck_assert_ldouble_nan(s21_acos(x_3));
}
END_TEST

START_TEST(s21_acos_test_1) {
  for (double i = -1; i <= 1; i = i + 0.1) {
    ck_assert_ldouble_eq_tol(s21_acos(i), acos(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_acos_test_MAX_MIN) {
  double x = DBL_MAX;
  ck_assert_ldouble_nan(s21_acos(x));
  double x_1 = DBL_MIN;
  ck_assert_ldouble_eq_tol(s21_acos(x_1), acos(x_1), 1e-6);
}
END_TEST

START_TEST(s21_acos_INF) {
  double x = S21_INF;
  ck_assert_ldouble_nan(s21_acos(x));
  double x_1 = -S21_INF;
  ck_assert_ldouble_nan(s21_acos(x_1));
}

Suite *s21_acos_suite(void) {
  Suite *s = suite_create("s21_acos");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_acos_test_zero_neg_zero);
  tcase_add_test(tc_core, s21_acos_test_NAN);
  tcase_add_test(tc_core, s21_acos_test_1);
  tcase_add_test(tc_core, s21_acos_test_MAX_MIN);
  tcase_add_test(tc_core, s21_acos_INF);
  suite_add_tcase(s, tc_core);

  return s;
}
