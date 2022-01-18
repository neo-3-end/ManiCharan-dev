#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int a[n1], b[n2];
    for (int i=0; i<n1; i++)
        a[i] = arr[l + i];
    for (int j=0; j<n2; j++)
        b[j] = arr[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if(a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else{
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while(j <  n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int lb, int ub)
{
    if(lb<ub)
    {
        int m;
        m = lb + (ub -lb) / 2;
        mergesort(arr,lb,m);
        mergesort(arr,m+1,ub);
        
        merge(arr,lb,m,ub);
    }
    
}
int main(void) 
{
    int n;
    cout << "Enter number of elements ";
	cin >> n;
	int arr[n];
    cout << "Enter elements into array" << endl;
	for (int i = 1; i <= n; i++)
	{
        cout << "arr[" << i << "] ";
	    cin >> arr[i];
	}
	mergesort(arr,1,n);
    cout << "Sorted array is......" << endl;
	for (int i = 1; i <= n; i++)
	{
	    cout << arr[i] << endl;
	}
	return 0;
}

