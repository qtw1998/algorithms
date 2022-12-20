//
// Created by qtw1998 on 22-12-17.
//

#ifndef ALGORITHMS_SORTTESTHELPER_H
#define ALGORITHMS_SORTTESTHELPER_H

#include <iostream>
#include <cassert>

using namespace std;

namespace SortTestHelper {
    int *generateRandomArray(int n, int rangeL, int rangeR) {
        int *arr = new int[n];
        srand(time(NULL));
        assert(rangeL <= rangeR);
        for (int i = 0; i < n; ++i)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }

    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
        clock_t start_time = clock();
        sort(arr, n);
        clock_t end_time = clock();

        cout << sortName << " : " << double(end_time - start_time) / CLOCKS_PER_SEC << " s" << endl;
    }

    template<typename T>
    bool isSorted
}


#endif //ALGORITHMS_SORTTESTHELPER_H
