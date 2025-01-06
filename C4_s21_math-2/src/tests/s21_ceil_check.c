#include "s21_math_check.h"

START_TEST(s21_ceil_test_zero) {
  int x = 0;
  ck_assert_ldouble_eq(x, x);
}
END_TEST

START_TEST(s21_ceil_test_NEG_zero) {
  int x = -0;
  ck_assert_ldouble_eq(x, x);
}
END_TEST

START_TEST(s21_ceil_test_1) {
  for (double x = 1; x < 100; x += 0.1) {
    ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
  }
  for (double x = -1; x > -100; x -= 0.1) {
    ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
  }
}
END_TEST

START_TEST(s21_ceil_test_MAX_MIN) {
  int x = INT_MAX;
  ck_assert_ldouble_eq(x, x);

  int x_1 = INT_MIN;
  ck_assert_ldouble_eq(x_1, x_1);
}
END_TEST

Suite *s21_ceil_suite(void) {
  Suite *s = suite_create("s21_ceil");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_ceil_test_zero);
  tcase_add_test(tc_core, s21_ceil_test_NEG_zero);
  tcase_add_test(tc_core, s21_ceil_test_1);
  tcase_add_test(tc_core, s21_ceil_test_MAX_MIN);
  suite_add_tcase(s, tc_core);

  return s;
}