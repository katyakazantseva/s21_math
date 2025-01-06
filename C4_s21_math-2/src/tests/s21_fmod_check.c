#include "s21_math_check.h"

START_TEST(s21_fmod_test_zero_neg_zero) {
  double x = 0.0;
  double y = 0.0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  double x_1 = -0.0;
  double y_1 = -0.0;
  ck_assert_ldouble_nan(s21_fmod(x_1, y_1));
}
END_TEST

START_TEST(s21_fmod_test_NAN) {
  double x = S21_NAN;
  double y = S21_NAN;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}

START_TEST(s21_fmod_test_1) {
  for (double x = 1; x < 500; x++) {
    for (double y = 1; y < 500; y++) {
      // printf("x := %lf | y := %lf    | s21_fmod = %.10Lf | math = %.10lf;\n",
      // x, y, s21_fmod(x, y), fmod(x, y));
      ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
    }
  }
  for (double x = -1; x > -500; x--) {
    for (double y = -1; y > -500; y--) {
      // printf("x := %lf | y := %lf    | s21_fmod = %.10Lf | math = %.10lf;\n",
      // x, y, s21_fmod(x, y), fmod(x, y));
      ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
    }
  }
}
END_TEST

START_TEST(s21_fmod_test_2) {
  for (double x = 1; x < 50; x += 0.1) {
    for (double y = 1; y < 50; y += 0.1) {
      // printf("x := %lf | y := %lf    | s21_fmod = %.10Lf | math = %.10lf;\n",
      // x, y, s21_fmod(x, y), fmod(x, y));
      ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
    }
  }
  for (double x = -1; x > -50; x -= 0.1) {
    for (double y = -1; y > -50; y -= 0.1) {
      // printf("x := %lf | y := %lf\n", x, y);
      ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
    }
  }
}
END_TEST
START_TEST(s21_fmod_MAX_MIN_INT) {
  double x = INT_MAX;
  double y = INT_MIN;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
  double x_1 = INT_MIN;
  double y_1 = INT_MAX;
  ck_assert_ldouble_eq_tol(s21_fmod(x_1, y_1), fmod(x_1, y_1), 1e-6);
}

// START_TEST(s21_fmod_test_MAX_MIN) {
//     double x = DBL_MAX;
//     double y = DBL_MIN;
//     ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
//     double x_1 = DBL_MIN;
//     double y_1 = DBL_MAX;
//     ck_assert_ldouble_eq_tol(s21_fmod(x_1, y_1), fmod(x_1, y_1), 1e-6);
// }
// END_TEST

START_TEST(s21_fmod_test_INF) {
  double x = S21_INF;
  double y = S21_INF;
  ck_assert_ldouble_nan(s21_fmod(x, y));
  double x_1 = -S21_INF;
  double y_1 = -S21_INF;
  ck_assert_ldouble_nan(s21_fmod(x_1, y_1));
}

/////////

// START_TEST(fmod_test1) {
//   double x = 12.0;
//   double y = 4.0;
//   ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
// }
// END_TEST

// START_TEST(fmod_test2) {
//   double x = 0.0;
//   double y = 5.5;
//   ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
// }
// END_TEST

// START_TEST(fmod_test3) {
//   double x = S21_INF;
//   double y = 5.5;
//   ck_assert_ldouble_nan(s21_fmod(x, y));
// }
// END_TEST

// START_TEST(fmod_test4) {
//   double x = -S21_INF;
//   double y = 5.5;
//   ck_assert_ldouble_nan(s21_fmod(x, y));
// }
// END_TEST

// START_TEST(fmod_test5) {
//   double x = 5.8;
//   double y = 0.0;
//   ck_assert_ldouble_nan(s21_fmod(x, y));
// }
// END_TEST

// START_TEST(fmod_test6) {
//   double x = 5.8;
//   double y = S21_NEGZERO;
//   ck_assert_ldouble_nan(s21_fmod(x, y));
// }
// END_TEST

// START_TEST(fmod_test7) {
//   double x = 5.8;
//   double y = S21_INF;
//   ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
// }
// END_TEST

// START_TEST(fmod_test8) {
//   double x = 5.8;
//   double y = -S21_INF;
//   ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
// }
// END_TEST

// START_TEST(fmod_test9) {
//   double x = S21_NAN;
//   double y = 12.6;
//   ck_assert_ldouble_nan(s21_fmod(x, y));
// }
// END_TEST

// START_TEST(fmod_test10) {
//   double x = 5.5;
//   double y = S21_NAN;
//   ck_assert_ldouble_nan(s21_fmod(x, y));
// }
// END_TEST

Suite *s21_fmod_suite(void) {
  //   Suite *s = suite_create("suite_fmod");
  //   TCase *tc = tcase_create("fmod_tc");

  //   tcase_add_test(tc, fmod_test1);
  //   tcase_add_test(tc, fmod_test2);
  //   tcase_add_test(tc, fmod_test3);
  //   tcase_add_test(tc, fmod_test4);
  //   tcase_add_test(tc, fmod_test5);
  //   tcase_add_test(tc, fmod_test6);
  //   tcase_add_test(tc, fmod_test7);
  //   tcase_add_test(tc, fmod_test8);
  //   tcase_add_test(tc, fmod_test9);
  //   tcase_add_test(tc, fmod_test10);

  //   suite_add_tcase(s, tc);
  Suite *s = suite_create("s21_fmod");
  TCase *tc_core = tcase_create("Core");
  ;

  tcase_add_test(tc_core, s21_fmod_test_zero_neg_zero);
  tcase_add_test(tc_core, s21_fmod_test_NAN);
  tcase_add_test(tc_core, s21_fmod_test_1);
  tcase_add_test(tc_core, s21_fmod_test_2);
  tcase_add_test(tc_core, s21_fmod_MAX_MIN_INT);
  // tcase_add_test(tc_core, s21_fmod_test_MAX_MIN);
  tcase_add_test(tc_core, s21_fmod_test_INF);
  suite_add_tcase(s, tc_core);

  return s;
}