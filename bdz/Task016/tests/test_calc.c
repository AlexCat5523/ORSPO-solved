#include "../../Unity/src/unity.h"
#include "../src/calc.h"

void test_sum_array_correct(void) {
    int arr[] = {1,2,3};
    TEST_ASSERT_EQUAL_INT(6, sum_array(arr, 3));
}


void test_divide_logic_error(void) {
    TEST_ASSERT_EQUAL_INT(5, divide(10, 2)); 
}

void test_division_by_zero(void) {
    TEST_ASSERT_EQUAL_INT(0, divide(10, 0));    // <--- проверяем, что при вызове divide(10, 0) мы получим 0
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_sum_array_correct);
    RUN_TEST(test_divide_logic_error);
    RUN_TEST(test_division_by_zero);
    return UNITY_END();
}