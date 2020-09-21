

/**
  @File   MergeSort.h
  @Author: Renat Norderhaug

  @date Created on March 22, 2018, 2:07 PM
 */

#ifndef MERGESORT_H
#define MERGESORT_H
#include <iostream>
#include <ctime>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
using namespace std;

/**
@param  takes in an integer array, and 3 integer values
@pre an array full of random numbers that are sorted or unsorted, with pivots to divide from
@post an sorted array which is formed by dividing the unsorted array and merging
@note merge function
@return none
*/

void merge(int arr[], int a, int b, int c)
{
    int i, j, k;
    int n1 = b - a + 1;
    int n2 =  c - b;

    /// creates two temp array's
    int A[n1], B[n2];

    /// Copies  data to the temporary arrays
    for (i = 0; i < n1; i++)
        A[i] = arr[a + i];
    for (j = 0; j < n2; j++)
        B[j] = arr[b + 1+ j];

    /// Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = a;
    while (i < n1 && j < n2)
    {
        if (A[i] <= B[j])
        {
            arr[k] = A[i];
            i++;
        }
        else
        {
            arr[k] = B[j];
            j++;
        }
        k++;
    }

    /** Copies the last seperate remaining elements of A[], if there
       are any */
    while (i < n1)
    {
        arr[k] = A[i];
        i++;
        k++;
    }

    /* Copies  the last remaining elements of B[], if there
       are any left */
    while (j < n2)
    {
        arr[k] = B[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}







#endif /* MERGESORT_H */

