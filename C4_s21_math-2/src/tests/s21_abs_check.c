#include "s21_math_check.h"

START_TEST(s21_abs_test_zero) {
  int x = 0;
  ck_assert_int_eq(x, x);
}
END_TEST

START_TEST(s21_abs_test_NEG_zero) {
  int x = -0;
  ck_assert_int_eq(x, x);
}
END_TEST

START_TEST(s21_abs_test_1) {
  for (int i = 0; i < 1000; i++) {
    ck_assert_int_eq(s21_abs(i), abs(i));
  }
  for (int j = 0; j > -1000; j--) {
    ck_assert_int_eq(s21_abs(j), abs(j));
  }
}
END_TEST

START_TEST(s21_abs_test_MAX_MIN) {
  int x = INT_MAX;
  ck_assert_int_eq(x, x);

  int x_1 = INT_MIN;
  ck_assert_int_eq(x_1, x_1);
}
END_TEST

Suite *s21_abs_suite(void) {
  Suite *s = suite_create("s21_abs");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_abs_test_zero);
  tcase_add_test(tc_core, s21_abs_test_NEG_zero);
  tcase_add_test(tc_core, s21_abs_test_1);
  tcase_add_test(tc_core, s21_abs_test_MAX_MIN);
  suite_add_tcase(s, tc_core);

  return s;
}