#include "s21_math_check.h"

START_TEST(s21_atan_test_zero_neg_zero) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-6);
  x = -0.0;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-6);
}
END_TEST

START_TEST(s21_atan_test_NAN) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_atan(x));
}

START_TEST(s21_atan_test_near_one) {
  double x = 0.999999;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-6);
}
END_TEST

START_TEST(s21_atan_test_1) {
  for (double i = -1; i <= 1; i = i + 0.1) {
    ck_assert_ldouble_eq_tol(s21_atan(i), atan(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_atan_test_huge_negative) {
  double x = -10000000000000.0;
  // printf("s21 atan = %Lf; math = %lf\n", s21_atan(10000300), atan(10000300));
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-6);
}
END_TEST

START_TEST(s21_atan_test_2) {
  for (double i = 0; i < 100; i++) {
    ck_assert_ldouble_eq_tol(s21_atan(i), atan(i), 1e-6);
  }
  for (double i = 0; i > -100; i--) {
    ck_assert_ldouble_eq_tol(s21_atan(i), atan(i), 1e-6);
  }
}
END_TEST

START_TEST(s21_atan_test_huge_positive) {
  double x = 10000000000.0;
  // printf("s21 atan = %Lf; math = %lf\n", s21_atan(x), atan(x));
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-6);
}
END_TEST

START_TEST(s21_atan_test_MAX_MIN) {
  double x = DBL_MAX;
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-6);
  double x_1 = DBL_MIN;
  ck_assert_ldouble_eq_tol(s21_atan(x_1), atan(x_1), 1e-6);
  double x_2 = -DBL_MAX;
  ck_assert_ldouble_eq_tol(s21_atan(x_2), atan(x_2), 1e-6);
}
END_TEST

START_TEST(s21_atan_test_INF) {
  double x = S21_INF;
  // printf("s21 atan = %Lf; math = %lf\n", s21_atan(x), atan(x));
  ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-6);
  double x_1 = -S21_INF;
  // printf("s21 atan = %Lf; math = %lf\n", s21_atan(x), atan(x));
  ck_assert_ldouble_eq_tol(s21_atan(x_1), atan(x_1), 1e-6);
}

Suite *s21_atan_suite(void) {
  Suite *s = suite_create("s21_atan");
  TCase *tc_core = tcase_create("Core");
  ;

  tcase_add_test(tc_core, s21_atan_test_zero_neg_zero);
  tcase_add_test(tc_core, s21_atan_test_NAN);
  tcase_add_test(tc_core, s21_atan_test_huge_negative);
  tcase_add_test(tc_core, s21_atan_test_near_one);
  tcase_add_test(tc_core, s21_atan_test_1);
  tcase_add_test(tc_core, s21_atan_test_2);
  tcase_add_test(tc_core, s21_atan_test_huge_positive);
  tcase_add_test(tc_core, s21_atan_test_MAX_MIN);
  tcase_add_test(tc_core, s21_atan_test_INF);

  suite_add_tcase(s, tc_core);

  return s;
}
