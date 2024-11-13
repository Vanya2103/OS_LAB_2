#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <vector>

// ������� ��� ���������� ������������ � ������������� �������� � �������
void findMinMax(const std::vector<int>& arr, int& min_val, int& max_val);

// ������� ��� ���������� �������� �������� � �������
double findAverage(const std::vector<int>& arr);

// ������� ��� ������ ������������ � ������������� �������� ������� ���������
void replaceMinMaxWithAverage(std::vector<int>& arr, int min_val, int max_val, double average_val);

#endif // MATRIX_OPERATIONS_H
