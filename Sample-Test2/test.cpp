#include <gtest/gtest.h>
#include "pch.h"
#include "../OS_LAB_2/matrix_operations.h" // ваш заголовочный файл с объявлениями функций

// Тесты для функции findMinMax
TEST(MatrixOperationsTest, FindMinMax) {
    std::vector<int> arr = { 3, 1, 4, 1, 5, 9 };
    int min_val, max_val;

    findMinMax(arr, min_val, max_val);

    EXPECT_EQ(min_val, 1);
    EXPECT_EQ(max_val, 9);
}

// Тесты для функции findAverage
TEST(MatrixOperationsTest, FindAverage) {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };

    double average = findAverage(arr);

    EXPECT_DOUBLE_EQ(average, 3.0);
}

// Тесты для функции replaceMinMaxWithAverage
TEST(MatrixOperationsTest, ReplaceMinMaxWithAverage) {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    int min_val = 1;
    int max_val = 5;
    double average_val = 3.0;

    replaceMinMaxWithAverage(arr, min_val, max_val, average_val);

    EXPECT_EQ(arr[0], 3); // min_val заменяется на average
    EXPECT_EQ(arr[4], 3); // max_val заменяется на average
    EXPECT_EQ(arr[1], 2); // остальное не меняется
    EXPECT_EQ(arr[2], 3); // остальное не меняется
    EXPECT_EQ(arr[3], 4); // остальное не меняется
}

// Основная функция для запуска тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
