#include "s21_math_check.h"

START_TEST(s21_tan_test_zero_neg_zero) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), 1e-6);
  double x_1 = S21_NEGZERO;
  ck_assert_ldouble_eq_tol(s21_tan(x_1), tan(x_1), 1e-6);
  // double x_3 = S21_PI / 2;
  // ck_assert_ldouble_eq_tol(s21_tan(x_3), tan(x_3), 1e-6);
  // double x_2 = S21_PI / 2 + S21_EPS;
  // ck_assert_ldouble_eq_tol(s21_tan(x_2), tan(x_2), 1e-6);
}
END_TEST

START_TEST(test_tan_two_pi) {
  double x = S21_PI;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), 1e-6);
}
END_TEST

START_TEST(s21_tan_test_NAN) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_tan(x));
}
END_TEST

START_TEST(s21_tan_test_1) {
  for (double i = 0; i < 5000; i++) {
    ck_assert_ldouble_eq_tol(s21_tan(i), tan(i), 1e-6);
  }
  for (double j = 0; j > -5000; j--) {
    ck_assert_ldouble_eq_tol(s21_tan(j), tan(j), 1e-6);
  }
}
END_TEST

START_TEST(s21_tan_test_MIN) {
  double x_1 = DBL_MIN;
  ck_assert_ldouble_eq_tol(s21_tan(x_1), tan(x_1), 1e-6);
}
END_TEST

START_TEST(s21_tan_test_INF) {
  double x = S21_INF;
  ck_assert_ldouble_nan(s21_tan(x));
  double x_1 = -S21_INF;
  ck_assert_ldouble_nan(s21_tan(x_1));
}
END_TEST

Suite *s21_tan_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_tan");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_tan_test_zero_neg_zero);
  tcase_add_test(tc_core, s21_tan_test_NAN);
  tcase_add_test(tc_core, test_tan_two_pi);
  tcase_add_test(tc_core, s21_tan_test_1);
  tcase_add_test(tc_core, s21_tan_test_MIN);
  tcase_add_test(tc_core, s21_tan_test_INF);
  suite_add_tcase(s, tc_core);

  return s;
}
