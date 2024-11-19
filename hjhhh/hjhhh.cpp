#include <iostream>
#include <vector>
using namespace std;

// �������� 1: ���������� ������� ��� ����������� ������������� �������� � �����
int findMax(const vector<int>& arr, int index) {
    if (index == 0) return arr[0];
    return max(arr[index], findMax(arr, index - 1));
}

// �������� 2: ���������� ������� ��� ����������� ���������� �������� � �����
int findMin(const vector<int>& arr, int index) {
    if (index == 0) return arr[0];
    return min(arr[index], findMin(arr, index - 1));
}

// �������� 3: ³��������� ������ ��������� �������� ���������� ������
void quickSortLomuto(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    // ���� �������� ��������
    int pivot = arr[high];
    cout << "������� �������: " << pivot << endl;

    // ���� ������
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    int pivotIndex = i + 1;
    cout << "����� ���� �����: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    cout << "������ �������� ��������: " << pivotIndex << endl;

    // ��������� ��� �� ����� ������
    cout << "˳�� �������: ";
    for (int k = low; k < pivotIndex; k++) cout << arr[k] << " ";
    cout << endl;
    cout << "����� �������: ";
    for (int k = pivotIndex + 1; k <= high; k++) cout << arr[k] << " ";
    cout << endl << endl;

    // ������� ��� ��� �� ����� ������
    quickSortLomuto(arr, low, pivotIndex - 1);
    quickSortLomuto(arr, pivotIndex + 1, high);
}

int main() {
    // ���������� ����������� ������� ��� ����������� ��������� �� ������
    vector<int> testArray = { 34, 7, 23, 32, 5 };
    cout << "����������� ��������: " << findMax(testArray, testArray.size() - 1) << endl;
    cout << "̳������� ��������: " << findMin(testArray, testArray.size() - 1) << endl;

    // ���������� ��������� �������� ���������� ������
    vector<vector<int>> testCases = {
        {34, 7, 23, 32, 5},
        {1, 2, 3, 4, 5, 6},
        {90, 80, 70, 60, 50, 40, 30},
        {5, 3, 8, 8, 1, 5, 3, 9}
    };

    for (auto& arr : testCases) {
        cout << "���������� �����: ";
        for (int num : arr) cout << num << " ";
        cout << endl;

        quickSortLomuto(arr, 0, arr.size() - 1);

        cout << "³����������� �����: ";
        for (int num : arr) cout << num << " ";
        cout << endl << endl;
    }

    return 0;
}
