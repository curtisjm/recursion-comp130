// File: main.cpp
// Name: Curtis Mitchell
// Date: 5/11/21
// Compiler Used: MinGW-w64
// Purpose: Implement various functions using recursion

#include <iostream>

using namespace std;

int sumOfDigits(long n) {
    if(n == 0) {
        return 0;
    } else {
        return (n % 10 + sumOfDigits(n / 10));
    }
}

int largerInt(int a, int b) {
    return a > b ? a : b;
}

int findMax(int arr[], int size) {
    if(size == 1) {
        return arr[0];
    } else {
        return largerInt(arr[size - 1], findMax(arr, size - 1));
    }
}

int findMinIndex(int arr[], int size) {
    if(size == 1) {
        return 0;
    }
    int p = findMinIndex(arr + 1, size - 1) + 1;
    if(arr[0] < arr[p]) {
        return 0;
    } else {
        return p;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void singlePass(int arr[], int size, int pos) {
    if(size == 1) {
        return;
    }
    if(arr[pos] > arr[pos + 1]) {
        swap(&arr[pos], &arr[pos + 1]);
    }
    singlePass(arr, size - 1, pos + 1);
}

void bubbleSort(int arr[], int size) {
    if(size == 1) {
        return;
    }
    singlePass(arr, size, 0);
    bubbleSort(arr, size - 1);
}

void displayArray(int arr[], int size) {
    static int pos;
    if(pos == size) {
        cout << endl;
        pos = 0;
        return;
    }
    cout << arr[pos] << " ";
    pos++;
    displayArray(arr, size);
}

int main() {
    cout << "sumOfDigits(1234) =\t" << sumOfDigits(1234) << endl;
    const int SIZE = 5;
    int myArr[] = { 23, 64, 99, 1, 8 };
    cout << "Array content:\t";
    displayArray(myArr, SIZE);
    cout << "Max in the array =\t" << findMax(myArr, SIZE) << endl;
    cout << "Index of minimum =\t" << findMinIndex(myArr, SIZE) << endl;
    cout << "Sorting...\n";
    bubbleSort(myArr, SIZE);
    displayArray(myArr, SIZE);

    return 0;
}
