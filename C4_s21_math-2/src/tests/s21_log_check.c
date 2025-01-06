#include "s21_math_check.h"

START_TEST(s21_log_test_zero_neg_zero) {
  double x = 0.0;
  ck_assert_ldouble_eq(s21_log(x), log(x));
  double x_1 = -0.0;
  ck_assert_ldouble_eq(s21_log(x_1), log(x_1));
}
END_TEST

START_TEST(s21_log_test_NAN) {
  double x = S21_NAN;
  double x_1 = -S21_NAN;
  ck_assert_ldouble_nan(s21_log(x));
  ck_assert_ldouble_nan(s21_log(x_1));
}
END_TEST

START_TEST(s21_log_test_1) {
  for (double i = 1; i < 1000; i += 1) {
    ck_assert_ldouble_eq_tol(s21_log(i), log(i), 1e-6);
  }
  for (double j = -1; j > -1000; j -= 1) {
    ck_assert_ldouble_nan(s21_log(j));
  }
}
END_TEST

START_TEST(s21_log_MAX_MIN_INT) {
  double x = INT_MAX;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 1e-6);
  double x_1 = INT_MIN;
  ck_assert_ldouble_nan(s21_log(x_1));
}
END_TEST

START_TEST(s21_log_test_MAX_MIN) {
  double x = DBL_MAX;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), 1e-6);
  double x_3 = 3e-6;
  ck_assert_ldouble_eq_tol(s21_log(x_3), log(x_3), 1e-6);
  double x_2 = -DBL_MAX;
  ck_assert_ldouble_nan(s21_log(x_2));
}
END_TEST

START_TEST(s21_log_test_INF) {
  double x = S21_INF;
  ck_assert_ldouble_eq(s21_log(x), log(x));
  double x_1 = -S21_INF;
  ck_assert_ldouble_nan(s21_log(x_1));
}
END_TEST

Suite *s21_log_suite(void) {
  Suite *s = suite_create("s21_log");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_log_test_zero_neg_zero);
  tcase_add_test(tc_core, s21_log_test_NAN);
  tcase_add_test(tc_core, s21_log_test_1);
  tcase_add_test(tc_core, s21_log_MAX_MIN_INT);
  tcase_add_test(tc_core, s21_log_test_MAX_MIN);
  tcase_add_test(tc_core, s21_log_test_INF);
  suite_add_tcase(s, tc_core);

  return s;
}