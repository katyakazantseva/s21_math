#include "s21_math_check.h"

int main(void) {
  tests();
  return 0;
}

void tests(void) {
  Suite *suites[] = {
      s21_abs_suite(),   s21_cos_suite(),  s21_sin_suite(),  s21_tan_suite(),
      s21_floor_suite(), s21_acos_suite(), s21_asin_suite(), s21_atan_suite(),
      s21_ceil_suite(),  s21_fmod_suite(), s21_exp_suite(),  s21_fabs_suite(),
      s21_log_suite(),   s21_sqrt_suite(), s21_pow_suite(),  NULL};
  int count = 1;
  for (Suite **current_suite = suites; *current_suite != NULL;
       current_suite++) {
    SRunner *runner = srunner_create(*current_suite);
    ;
    if (count > 1) printf("\n");
    printf("TEST: %d\n", count);
    count++;
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
  }
}