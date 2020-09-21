

/**
 * ///File:   main.cpp
 * ///Author: renat norderhaug
 *
 * ///Created on March 22, 2018, 1:31 PM
 */

/// bubble Sort by Renat Norderhaug
#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include "BubbleSort.h"
#include "MergeSort.h"
#include "RadixSort.h"

using namespace std;

void fillFunc(int arr[], int n)  {

        for (int i = 1; i < n; i++)

        {

                    arr[i] = 1+ rand() % 10000;

         }



}

void sortArrayWithBubbleSort(int arr[], int n)  {
    srand((unsigned)time(NULL));
    double duration;
    fillFunc(arr, n);
    cout << "Unsorted array" << endl;
    std::clock_t start;
    start=std::clock();
    bubbleSort(arr, n);
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "Took :" << duration * 1000 << " milliseconds " << endl;

    cout << "Sorted array" << endl;
    std::clock_t start1;
    start1=std::clock();
    bubbleSort(arr, n);
    duration = (std::clock() - start1) / (double) CLOCKS_PER_SEC;
    cout << "Took :" << duration * 1000 << " milliseconds " << endl;
}

void sortArrayWithMergeSort(int arr[], int n)  {
    srand((unsigned)time(NULL));
    double duration;
    fillFunc(arr, n);
    cout << "Unsorted array" << endl;
    std::clock_t start;
    start=std::clock();
    mergeSort(arr, 0, n - 1);
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "Took :" << duration * 1000 << " milliseconds " << endl;

    cout << "Sorted array" << endl;
    std::clock_t start1;
    start1=std::clock();
    mergeSort(arr, 0, n - 1);
    duration = (std::clock() - start1) / (double) CLOCKS_PER_SEC;
    cout << "Took :" << duration * 1000 << " milliseconds " << endl;
}

void sortArrayWithRadixSort(int arr[], int n)  {
    srand((unsigned)time(NULL));
    double duration;
    fillFunc(arr, n);
    cout << "Unsorted array" << endl;
    std::clock_t start;
    start=std::clock();
    radixsort(arr, n);
    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "Took :" << duration * 1000 << " milliseconds " << endl;

    cout << "Sorted array" << endl;
    std::clock_t start1;
    start1=std::clock();
    radixsort(arr, n);
    duration = (std::clock() - start1) / (double) CLOCKS_PER_SEC;
    cout << "Took :" << duration * 1000 << " milliseconds " << endl;
}

int main() {

  ofstream output;
  ofstream error;

    output.open("output.txt");
    error.open("error.txt");

    int A[1000];
    cout << "************ Bubble Sort 1000 ***********" << endl;
    sortArrayWithBubbleSort(A, 1000);
    output << "sorted" << endl;

    cout << "************ Merge Sort 1000 ***********" << endl;
    sortArrayWithMergeSort(A, 1000);

    cout << "************ Radix Sort 1000 ***********" << endl;
    sortArrayWithRadixSort(A, 1000);


    int B[10000];
    cout << "************ Bubble Sort 10000 ***********" << endl;
    sortArrayWithBubbleSort(B, 10000);

    cout << "************ Merge Sort 10000 ***********" << endl;
    sortArrayWithMergeSort(B, 10000);

    cout << "************ Radix Sort 10000 ***********" << endl;
    sortArrayWithRadixSort(B, 10000);


    int C[100000];
    cout << "************ Bubble Sort 100000 ***********" << endl;
    sortArrayWithBubbleSort(C, 100000);

    cout << "************ Merge Sort 100000 ***********" << endl;
    sortArrayWithMergeSort(C, 100000);

    cout << "************ Radix Sort 100000 ***********" << endl;
    sortArrayWithRadixSort(C, 100000);

    cout << "************ Bubble Sort 1000000 ***********" << endl;
    // sortArrayWithMergeSort(C, 1000000);
    cout << "************ Merge Sort 1000000 ***********" << endl;
    cout << "************ Radix Sort 1000000 ***********" << endl;

    return 0;
}



