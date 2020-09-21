//
//  main.cpp
//  Project 2
//
//  Created by Renat Norderhaug on 2/10/18.
//  Copyright © 2018 Renat Norderhaug. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

//! function to print array
/*!
\param numbers an integer array argument.
\param length array length argument.
\param fout file output stream argument.
*/
void printArray(int numbers [], int length, std::ofstream &fout) {

    	for (int n=0; n<length; n++)//set 'k' to 0 execute while 'k' is less than 5
	   {
		  fout<<"numbers[" << n << "]: " << numbers[n]<<endl;
	   }
}
//! function to swap to array members in different positions
/*!
\param a address of first memeber
\param b address of second member.
*/
void swap(int *a, int *b)
{
    //std::cout<<"Swapping " << *a << " with " << *b <<std::endl ;
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//! function to partition array based on first array member as pivot.
//! it finds the final position of the pivot in the array from low to high
/*!
\param a an integer array argument.
\param low the most left array index argument.
\param low the most right array index argument.
\param fout file output stream argument.
*/
int partition(int a[], int low, int high, std::ofstream &fout)

{
	int i=1;
	int pivot = a[low];
	fout<<"Partitioning the range for low: " << low << " and high: " << high << std::endl;

	// Getting index of pivot.
	for(int j=low; j < high-1; j++)
	{
		if(a[j] <= pivot)
		{
			swap(&a[i], &a[j]);
			i++;
		}
	}
	// Swapping value at high and at the index obtained.
	swap(&a[i], &a[high]);

	return i;
}

//! function to fid kth smallest in the array.
//! Search is similar to how quick sort works but it stops at the point where pivot itself is kth smallest element.
//! Also, we do not recur for both left and right sides of pivot, but recur for one of them according to the position of pivot.
/*!
\param k position of the smallest int we search for.
\param anArray an integer array argument.
\param low the most left array index argument.
\param low the most right array index argument.
\param fout file output stream argument.
*/
int kSmall(int k, int anArray[], int low, int high, std::ofstream &fout)
{
    int pivotIndex = partition(anArray, low, high, fout);
    fout << "Pivot: " << pivotIndex << std::endl;
    printArray(anArray, high-low, fout);
       if (k < pivotIndex - low + 1)
          { fout<<"Recursive call to itself for condition: k < pivotIndex - low + 1" << std::endl;
            return kSmall(k, anArray, low, pivotIndex - 1, fout); }
        else if (k == pivotIndex - low + 1) {
            fout<<"Returning pivotIdex " << std::endl ;
            return pivotIndex;
        }
        else {
            fout<<"Recursive call to itself for remaining conditions" << std::endl;
            return kSmall(k - (pivotIndex - low + 1), anArray, pivotIndex + 1, high, fout);
        }
}

int main() {

	//Declarations (insert as needed)
	int kSmall_pos;            //For User Input
	int kSmall_val = 0;//Populate using your algorithm implementation
	int pivot = 0;                //Pivot position in array

	//User Input DO NOT MODIFY
	std::cout << "Please enter required kth smallest value: ";
	std::cin >> kSmall_pos;

	int length = 0;
	int *numbers = new int[150]; // numbers array for first read in
	std::ifstream fin;  // to read in file

	//File Read code (insert) - This code should be able to parse the data in a text file similar to the provided one and store values in an array for processing.
    fin.open("a2-data.txt");
    if(fin.fail())
    {
        cout << "Error, could not open the file." << endl;
        fin.clear();
        return -1;
    }
    else
    {
        while(!fin.eof())
        {
            fin >> numbers[length++];
        }
    }
    fin.close();

    //appends to the log file
    std::ofstream fout;
    fout.open("log.txt", std::ofstream::out | std::ofstream::app);

    fout<<"Calling recursive function kSmall" <<std::endl;
	//kmsall algorithm implementation or function call (insert) - implement using recursion as indicated
    kSmall_val = kSmall(kSmall_pos, numbers, 0, length-1, fout);

	//Output DO NOT MODIFY
	fout<<"The " << kSmall_pos << "th smallest value = "<< kSmall_val <<std::endl;

	//Log file output (insert) - preferred in .txt format acoording to instructions posted on assignment page
    fout.close();

}



