#include <iostream>
#include <vector>
using namespace std;

// Завдання 1: Рекурсивна функція для знаходження максимального елементу в масиві
int findMax(const vector<int>& arr, int index) {
    if (index == 0) return arr[0];
    return max(arr[index], findMax(arr, index - 1));
}

// Завдання 2: Рекурсивна функція для знаходження мінімального елементу в масиві
int findMin(const vector<int>& arr, int index) {
    if (index == 0) return arr[0];
    return min(arr[index], findMin(arr, index - 1));
}

// Завдання 3: Візуалізація роботи алгоритму швидкого сортування Ломуто
void quickSortLomuto(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    // Вибір опорного елементу
    int pivot = arr[high];
    cout << "Опорний елемент: " << pivot << endl;

    // Поділ масиву
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    int pivotIndex = i + 1;
    cout << "Масив після поділу: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    cout << "Індекс опорного елемента: " << pivotIndex << endl;

    // Виведення лівої та правої частин
    cout << "Ліва частина: ";
    for (int k = low; k < pivotIndex; k++) cout << arr[k] << " ";
    cout << endl;
    cout << "Права частина: ";
    for (int k = pivotIndex + 1; k <= high; k++) cout << arr[k] << " ";
    cout << endl << endl;

    // Рекурсія для лівої та правої частин
    quickSortLomuto(arr, low, pivotIndex - 1);
    quickSortLomuto(arr, pivotIndex + 1, high);
}

int main() {
    // Тестування рекурсивних функцій для знаходження максимуму та мінімуму
    vector<int> testArray = { 34, 7, 23, 32, 5 };
    cout << "Максимальне значення: " << findMax(testArray, testArray.size() - 1) << endl;
    cout << "Мінімальне значення: " << findMin(testArray, testArray.size() - 1) << endl;

    // Тестування алгоритму швидкого сортування Ломуто
    vector<vector<int>> testCases = {
        {34, 7, 23, 32, 5},
        {1, 2, 3, 4, 5, 6},
        {90, 80, 70, 60, 50, 40, 30},
        {5, 3, 8, 8, 1, 5, 3, 9}
    };

    for (auto& arr : testCases) {
        cout << "Початковий масив: ";
        for (int num : arr) cout << num << " ";
        cout << endl;

        quickSortLomuto(arr, 0, arr.size() - 1);

        cout << "Відсортований масив: ";
        for (int num : arr) cout << num << " ";
        cout << endl << endl;
    }

    return 0;
}
