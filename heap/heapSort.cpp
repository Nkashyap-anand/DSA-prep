#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = i * 2;
    int right = i * 2 + 1;

    if (left <= n && arr[largest] < arr[left])
        largest = left;

    if (right <= n && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;

    while (size > 1)
    {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "heap is : ";
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);

    cout << "sorted heap is : ";
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}