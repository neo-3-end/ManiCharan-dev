#include<iostream>
using namespace std;

void swap(int*, int*);
void MaxHeap(int[], int);
void Sorted_Array(int[], int);

int main()
{
    int n;
    cout << "Enter number of elements inn an array " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements into array ";
    for (int i = 1; i <= n; i++)
    {
        cout << "arr["<<i<<"] ";
        cin >> arr[i];
    }
    Sorted_Array(arr, n);
    cout << "Sorted Array is......." << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void MaxHeap(int arr[], int n)
{
    for (int i = n; i >= 1; --i)
    {
        if ( arr[i] > arr[i/2])
            swap( &arr[i], &arr[i/2]);
    }
}
void Sorted_Array(int arr[], int n)
{
    MaxHeap(arr, n);
    for (int i = 1; i <= n; i++)
    {
        swap(&arr[1], &arr[(n + 1) - i]);
        MaxHeap(arr, n - i);
    }
}
