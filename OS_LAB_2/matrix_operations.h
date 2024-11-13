#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <vector>

// Функция для нахождения минимального и максимального значений в массиве
void findMinMax(const std::vector<int>& arr, int& min_val, int& max_val);

// Функция для нахождения среднего значения в массиве
double findAverage(const std::vector<int>& arr);

// Функция для замены минимального и максимального значений средним значением
void replaceMinMaxWithAverage(std::vector<int>& arr, int min_val, int max_val, double average_val);

#endif // MATRIX_OPERATIONS_H
