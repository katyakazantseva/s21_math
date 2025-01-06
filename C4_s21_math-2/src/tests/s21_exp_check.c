#include "s21_math_check.h"

START_TEST(s21_exp_test_NAN) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_exp(x));
}
END_TEST

START_TEST(s21_exp_test_zero_neg_zero) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
  double x_1 = -0.0;
  ck_assert_ldouble_eq_tol(s21_exp(x_1), exp(x_1), 1e-6);
}
END_TEST

START_TEST(s21_exp_test_1) {
  for (double i = 0; i < 21.5; i = i + 0.5) {
    ck_assert_ldouble_eq_tol(s21_exp(i), exp(i), 1e-6);
  }
  for (double j = 0; j > -25; j = j - 0.5) {
    ck_assert_ldouble_eq_tol(s21_exp(j), exp(j), 1e-6);
  }
  double x = 716;
  ck_assert_ldouble_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(s21_exp_test_MAX_INT) {
  double x = INT_MAX;
  ck_assert_ldouble_eq(s21_exp(x), exp(x));
  double x_1 = INT_MIN;
  ck_assert_ldouble_eq(s21_exp(x_1), exp(x_1));
}
END_TEST

START_TEST(s21_exp_test_MAX_MIN) {
  double x = DBL_MAX;
  ck_assert_ldouble_eq(s21_exp(x), exp(x));

  double x_1 = DBL_MIN;
  ck_assert_ldouble_eq(s21_exp(x_1), exp(x_1));

  double x_2 = -DBL_MAX;
  ck_assert_ldouble_eq(s21_exp(x_2), exp(x_2));
}
END_TEST

START_TEST(s21_exp_INF) {
  double x = S21_INF;
  ck_assert_ldouble_eq(s21_exp(x), exp(x));
  double x_1 = -S21_INF;
  ck_assert_ldouble_eq(s21_exp(x_1), exp(x_1));
}

Suite *s21_exp_suite(void) {
  Suite *s = suite_create("s21_exp");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_exp_test_zero_neg_zero);
  tcase_add_test(tc_core, s21_exp_test_NAN);
  tcase_add_test(tc_core, s21_exp_test_1);
  tcase_add_test(tc_core, s21_exp_test_MAX_INT);
  tcase_add_test(tc_core, s21_exp_test_MAX_MIN);
  tcase_add_test(tc_core, s21_exp_INF);
  suite_add_tcase(s, tc_core);

  return s;
}
