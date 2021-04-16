#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
/*
1. Chon phan tu cuoi mang hoac dau mang hoac la so trung vi
2. Day la vi du chon phan tu la cuoi mang
3. 


*/
int partition(int arr[], int low, int high)
{
    /* Gan pivot */
    int pivot = arr[high]; // pivot
    int left = low;
    int right = high - 1;
    /* 
    0. Lặp vô tận
    1. Duyet left den right & den khi arr[left] không còn nhỏ hơn pivot
    2. Sau đó duyet right den left & arr[right] không còn lớn hơn pivot 
    3. Nếu left >= right thì thoát lặp vô tận ở step 0
    4. swap arr[left], arr[right]
    5. Tăng left, giảm right 

    ...
    hoán vị left & pivot
    */


    while (true)
    {
        while (left <= right && arr[left] < pivot)
            left++;
        while (right >= left && arr[right] > pivot)
            right--;
        if (left >= right)
            break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int piv = partition(arr, low, high);
        quickSort(arr, low, piv - 1);
        quickSort(arr, piv + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70, 75};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}
