#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &nums, int l, int h)
{
    int pivot = nums[l];
    int i = l, j = h;
    while (i < j)
    {
        while (nums[i] <= pivot)
            i++;
        while (nums[j] > pivot)
            j++;
        if (i < j)
            swap(nums[i], nums[j]);
    }
    swap(nums[j], nums[l]);
    return j;
}

void quickSort(vector<int> &nums, int l, int h)
{
    while (l < h)
    {
        int pivot = partition(nums, l, h);
        quickSort(nums, l, pivot - 1);
        quickSort(nums, pivot + 1, h);
    }
}

void PrintVector(vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "\n\n";
}

int main()
{
    vector<int> v = {1, 10, 11, 9, 14, 3, 2, 20, 19};

    cout << "Vector Before Sorting: " << endl;
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "\n\n";

    quickSort(v, 0, v.size() - 1);

    cout << "Vector After Sorting: " << endl;
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "\n\n";

    return 0;
}