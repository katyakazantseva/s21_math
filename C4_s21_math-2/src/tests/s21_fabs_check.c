#include "s21_math_check.h"

START_TEST(s21_fabs_test_zero_neg_zero) {
  double x = 0.0;
  ck_assert_ldouble_eq(s21_fabs(x), fabs(x));
  double x_1 = -0.0;
  ck_assert_ldouble_eq(s21_fabs(x_1), fabs(x_1));
}
END_TEST

START_TEST(s21_fabs_test_NAN) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_fabs(x));
}

START_TEST(s21_fabs_test_1) {
  for (double i = 0; i < 1000; i++) {
    ck_assert_ldouble_eq(s21_fabs(i), fabs(i));
  }
  for (double j = 0; j > -1000; j--) {
    ck_assert_ldouble_eq(s21_fabs(j), fabs(j));
  }
}
END_TEST

START_TEST(s21_fabs_test_2) {
  for (double i = 0; i < 1000; i = i + 0.1) {
    ck_assert_ldouble_eq(s21_fabs(i), fabs(i));
  }
  for (double j = 0; j > -1000; j = j - 0.1) {
    ck_assert_ldouble_eq(s21_fabs(j), fabs(j));
  }
}
END_TEST

START_TEST(s21_fabs_MAX_MIN_INT) {
  double x = INT_MAX;
  ck_assert_ldouble_eq(s21_fabs(x), fabs(x));
  double x_1 = INT_MIN;
  ck_assert_ldouble_eq(s21_fabs(x_1), fabs(x_1));
}

START_TEST(s21_fabs_test_MAX_MIN) {
  double x = DBL_MAX;
  ck_assert_ldouble_eq(s21_fabs(x), fabs(x));
  double x_1 = DBL_MIN;
  ck_assert_ldouble_eq(s21_fabs(x_1), fabs(x_1));
}
END_TEST

START_TEST(s21_fabs_test_INF) {
  double x = S21_INF;
  ck_assert_ldouble_eq(s21_fabs(x), fabs(x));
  double x_1 = -S21_INF;
  ck_assert_ldouble_eq(s21_fabs(x_1), fabs(x_1));
}

Suite *s21_fabs_suite(void) {
  Suite *s = suite_create("s21_fabs");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_fabs_test_zero_neg_zero);
  tcase_add_test(tc_core, s21_fabs_test_NAN);
  tcase_add_test(tc_core, s21_fabs_test_1);
  tcase_add_test(tc_core, s21_fabs_test_2);
  tcase_add_test(tc_core, s21_fabs_MAX_MIN_INT);
  tcase_add_test(tc_core, s21_fabs_test_MAX_MIN);
  tcase_add_test(tc_core, s21_fabs_test_INF);
  suite_add_tcase(s, tc_core);

  return s;
}