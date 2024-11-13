#include "matrix_operations.h" // Подключаем заголовочный файл с объявлениями функций
#include <windows.h> // Для использования потоков Windows API
#include <iostream>
#include <numeric> // Для std::accumulate

// Определения глобальных переменных
std::vector<int> arr;
int min_val;
int max_val;
double average_val;
HANDLE mutex; // Инициализация мьютекса для синхронизации потоков

// Функция для нахождения минимального и максимального значения в массиве
DWORD WINAPI min_max(LPVOID lpParam) {
    // Захват мьютекса перед доступом к глобальным переменным
    WaitForSingleObject(mutex, INFINITE);

        min_val = arr[0];
    max_val = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        Sleep(7);
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        Sleep(7);
    }

    std::cout << "Min value: " << min_val << ", Max value: " << max_val << std::endl;

    // Освобождение мьютекса
    ReleaseMutex(mutex);

    return 0;
}

// Функция для вычисления среднего значения элементов массива
DWORD WINAPI average(LPVOID lpParam) {
    // Захват мьютекса перед доступом к глобальным переменным
    WaitForSingleObject(mutex, INFINITE);

        int sum = 0;
    for (int num : arr) {
        sum += num;
        Sleep(12);
    }

    average_val = static_cast<double>(sum) / arr.size();
    std::cout << "Average value: " << average_val << std::endl;

    // Освобождение мьютекса
    ReleaseMutex(mutex);

    return 0;
}

// Функция для замены минимального и максимального значения на среднее в массиве
void replaceMinMaxWithAverage(std::vector<int>& arr, int min_val, int max_val, double average_val) {
    for (int& num : arr) {
        if (num == min_val || num == max_val) {
            num = static_cast<int>(average_val); // Приведение среднего значения к int
        }
    }
}
void findMinMax(const std::vector<int>& arr, int& min_val, int& max_val) {
    min_val = arr[0];
    max_val = arr[0];

        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] < min_val) {
                min_val = arr[i];
            }
            if (arr[i] > max_val) {
                max_val = arr[i];
            }
        }
}

// Реализация функции findAverage
double findAverage(const std::vector<int>& arr) {
    int sum = std::accumulate(arr.begin(), arr.end(), 0);
    return static_cast<double>(sum) / arr.size();
}
int main() {
    setlocale(LC_ALL, "rus");

        // Ввод данных
        int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    arr.resize(n);
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Инициализация мьютекса
    mutex = CreateMutex(NULL, FALSE, NULL);

    // Создаем потоки min_max и average
    HANDLE hMinMax = CreateThread(NULL, 0, min_max, NULL, 0, NULL);
    HANDLE hAverage = CreateThread(NULL, 0, average, NULL, 0, NULL);

    // Ожидаем завершения потоков
    WaitForSingleObject(hMinMax, INFINITE);
    WaitForSingleObject(hAverage, INFINITE);

    // Закрываем дескрипторы потоков и мьютекс
    CloseHandle(hMinMax);
    CloseHandle(hAverage);
    CloseHandle(mutex);

    // Замена минимального и максимального значения на среднее
    replaceMinMaxWithAverage(arr, min_val, max_val, average_val);

    // Вывод модифицированного массива
    std::cout << "Измененный массив: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}