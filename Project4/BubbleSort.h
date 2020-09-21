

/**
  @File   BubbleSort.h
  @Author: Renat Norderhaug

  @date Created on March 22, 2018, 2:01 PM
 */

#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>

using namespace std;

/**
@param  takes in two integer pointers
@pre two integer pointers
@post the two integer pointers values are replaced
@note Swap function
@return none
*/
void swap(int *i, int *j)

{
    int temp = *i;
    *i = *j;
    *j = temp;
}
/**
@param  takes in an integer array and a single integer
@pre an array with a value
@post the array is sorted
@note the process of how an array is sorted using bubble sort
@return sorted array
*/

void bubbleSort(int a[], int n)
{
   int i, j;
   long c = 0;
   long s = 0;
   for (i = 0; i < n-1; i++){
       bool swapped = false;
       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++) {
           c++;
           if (a[j] > a[j+1]) {
              swap(&a[j], &a[j+1]);
              swapped = true;
              s++;
           }
       }
       if (!swapped) {
             break;
       }
   }
   cout << "Number of comparisons: " << c << endl;
   cout << "Number of swaps: " << s << endl;

}



/*
  Function that prints an array
 */

void printArray(int a[], int size)

{

    int i;

    for (i=0; i < size; i++)

        printf("%d ", a[i]);

    printf("\n");

}

/// makes  an array


int* generateArray(int n) {

  int r[n];

  for (int i = 0; i < n; ++i) {

    r[i] = rand() % n + 1;

  }

  return r;

}


#endif /* BUBBLESORT_H */

