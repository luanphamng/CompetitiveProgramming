#include <iostream>

using namespace std;

void swap (int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int partition (int arr[], int low, int high)
{
 int pivot = arr[high];    // pivot
 int left = low;
 int right = high - 1;

 while(true){
     while(left <= right && arr[left] < pivot) left++;
     while(right >= left && arr[right] > pivot) right--;
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
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70, 75};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    //cout << "Hello world!" << endl;
    //for(int i = 0; i < n; i++)
    //    cout << arr[i] << "   ";
    printArray(arr, n);
    return 0;
}
