#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    // data
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    selectionSort(arr, n);
    SortTestHelper::printArray(arr, n);

    delete[] arr;
//    int arr[5] = {5, 3, 1, 4, 2};
//    float b[5] = {5.2, 3.4, 1.2, 4.4, 2.1};
//    Student s[5] = {{"D", 90},
//                    {"C", 100},
//                    {"B", 95},
//                    {"A", 95}};
//    // processing
//    selectionSort(arr, 5);
//    for (int ele: arr) {
//        cout << ele << " ";
//    }
//    cout << endl;
//
//    selectionSort(b, 5);
//    for (auto ele: b) {
//        cout << ele << " ";
//    }
//
//    selectionSort(s, 5);
//    for (auto ele: s) {
//        cout << ele << endl;
//    }
    return 0;
}