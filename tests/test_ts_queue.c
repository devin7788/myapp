//
// Created by DEIN2023 on 25-6-24.
//
#include <check.h>
#include "../ts_queue.h"

START_TEST(test_queue_push_pop)
{
    ts_queue_t q;
    ts_queue_init(&q);

    ts_queue_push(&q, 42);
    int val = 0;
    ck_assert(ts_queue_pop(&q, &val) == 1);
    ck_assert_int_eq(val, 42);

    ck_assert(ts_queue_pop(&q, &val) == 0); // 队列已空

    ts_queue_destroy(&q);
}
END_TEST

Suite *queue_suite(void) {
    Suite *s = suite_create("TSQueue");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_queue_push_pop);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int failed;
    Suite *s = queue_suite();
    SRunner *runner = srunner_create(s);

    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (failed == 0) ? 0 : 1;
}
