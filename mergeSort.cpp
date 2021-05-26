#include <iostream>
#include <string>
#include "math.h"

using namespace std;

void merge(int arr[], int start, int mid, int end);

void mergeSort(int arr[], int start, int end)
{
    if(start >= end)
        return;
    int mid = (end+start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

void merge(int arr[], int start, int mid, int end)
{
    int sizeLeft = (mid-start+1);
    int sizeRight = end - mid;
    int left[sizeLeft];
    int right[sizeRight];
    int i = 0;
    int j = 0;
    int k = 0;
    
    for(i = 0; i<sizeLeft; i++)
    {
        //cout << "left: " << arr[i] << endl;
        left[i] = arr[start+i];
    }
    
    for(i = 0; i<=sizeRight; i++)
    {
        //cout << "right: " << arr[i+1+mid] << endl;
        right[i] = arr[i+1+mid];
    }
        
    i = 0;
    j = 0;
    k = start; 
    while (i<sizeLeft && j<sizeRight)
    {
        if(left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    // put rest of left
    while(i<sizeLeft)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    // put rest of right
    while(j<sizeRight)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeTwoArrays(int a[], int b[], int sizeA, int sizeB)
{
    int current = sizeA + sizeB - 1;
    int indexA = sizeA - 1;
    int indexB = sizeB - 1;
    
    while(indexA>=0 && indexB>=0)
    {
        if(a[indexA] >= b[indexB])
        {
            a[current] = a[indexA];
            indexA--;
        }
        else
        {
            a[current] = b[indexB];
            indexB--;
        }
        current--;
    }
    while(indexB>=0)
    {
        a[current] = b[indexB];
        indexB--;
        current--;
    }
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    mergeSort(arr, 0, arr_size - 1);
    
    for(int i=0; i<arr_size; i++)
        std::cout << arr[i] << " ";
    cout << endl;
        
    int arr1[10] = { 5, 6, 7, 11, 12, 13 };
    int arr_size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[4] = { 4, 8, 10, 15 };
    int arr_size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    mergeTwoArrays(arr1, arr2, 6, 4);
    
    for(int i=0; i<arr_size1; i++)
        std::cout << arr1[i] << " ";
    
    /*
    int N = 0b100000000000;
    int M = 0b10101;
    
    N = manipulateNumberBetweenBits(N, M, 2, 6);
    cout << N;
    */
    return 0;
}
