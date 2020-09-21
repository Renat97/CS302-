

/*
 @File   RadixSort.h
 @Author Renat norderhaug

 @date Created on March 22, 2018, 3:35 PM
 */

#ifndef RADIXSORT_H
#define RADIXSORT_H
#include <iostream>
#include <ctime>
#include<stdlib.h>
#include<stdio.h>
#include <fstream>

using namespace std;
/// returns the value of maximum index of the certain array
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
/**
 A function which implements the counting sort of an array based on
 the number that you enter in as exp

@param  takes in an integer array, two integer variables
@pre an unsorted array with random numbers
@post a sorted array that uses the similar count sort algorithm but orders by position values
@note Count sort
@return none
*/
void countSort(int array[], int n, int exp)
{
    int c,s;
    int output[n]; /// the output array
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[ (array[i]/exp)%10 ]++;
        c++;
        s++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
        c++;

    /// Builds the output array
    for (i = n - 1; i >= 0; i--)
    {
        c++;
        output[count[ (array[i]/exp)%10 ] - 1] = array[i];
        count[ (array[i]/exp)%10 ]--;
    }

    /// Copies the  output array to arr[], so that arr[] now
    /// contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        array[i] = output[i];
}
/// pre condition: an array and an integer size for the array
/// post condition, sorts the array
/// parameters, int array and an int value
void radixsort(int arr[], int n)
{
    /// Find the maximum number to know number of digits
    int m = getMax(arr, n);
    for (int exp = 1; m/exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}



#endif /* RADIXSORT_H */

