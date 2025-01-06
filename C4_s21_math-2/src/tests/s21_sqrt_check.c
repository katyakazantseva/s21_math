#include "s21_math_check.h"

START_TEST(s21_sqrt_test_zero_neg_zero) {
  double x = 0.0;
  ck_assert_ldouble_eq(s21_sqrt(x), sqrt(x));
  double x_1 = -0.0;
  ck_assert_ldouble_eq(s21_sqrt(x_1), sqrt(x_1));
}
END_TEST

START_TEST(s21_sqrt_test_NAN) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_sqrt(x));
}
END_TEST

START_TEST(s21_sqrt_test_1) {
  for (double i = 0.0000000000000000001; i < 1000; i++) {
    ck_assert_ldouble_eq_tol(s21_sqrt(i), sqrt(i), 1e-6);
  }
  for (double j = -0.00000000000001; j > -1000; j--) {
    ck_assert_ldouble_nan(s21_sqrt(j));
  }
}
END_TEST

START_TEST(s21_sqrt_MAX_MIN_INT) {
  double x = INT_MAX;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
  double x_1 = INT_MIN;
  ck_assert_ldouble_nan(s21_sqrt(x_1));
}
END_TEST

START_TEST(s21_sqrt_test_MAX_MIN) {
  double x_1 = DBL_MIN;
  ck_assert_ldouble_eq_tol(s21_sqrt(x_1), sqrt(x_1), 1e-6);
  double x_2 = -DBL_MAX;
  ck_assert_ldouble_nan(s21_sqrt(x_2));
}
END_TEST

START_TEST(s21_sqrt_test_INF) {
  double x = S21_INF;
  ck_assert_ldouble_eq(s21_sqrt(x), sqrt(x));
  double x_1 = -S21_INF;
  ck_assert_ldouble_nan(s21_sqrt(x_1));
}
END_TEST

Suite *s21_sqrt_suite(void) {
  Suite *s = suite_create("s21_sqrt");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_sqrt_test_zero_neg_zero);
  tcase_add_test(tc_core, s21_sqrt_test_NAN);
  tcase_add_test(tc_core, s21_sqrt_test_1);
  tcase_add_test(tc_core, s21_sqrt_MAX_MIN_INT);
  tcase_add_test(tc_core, s21_sqrt_test_MAX_MIN);
  tcase_add_test(tc_core, s21_sqrt_test_INF);
  suite_add_tcase(s, tc_core);

  return s;
}