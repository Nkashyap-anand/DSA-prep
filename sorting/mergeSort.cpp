#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> v, int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    vector<int> temp;

    while (i <= mid && j <= r)
    {
        if (v[i] < v[j])
        {
            temp[k] = v[i];
            i++;
        }
        else
        {
            temp[k] = v[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        while (j < r)
        {
            temp[k] = v[j];
            k++;
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            temp[k] = v[i];
            k++;
            i++;
        }
    }

    for (k = l; k <= r; k++)
    {
        v[k] = temp[k];
    }
}

void mergeSort(vector<int> v, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(v, l, mid);
        mergeSort(v, mid + 1, r);
        merge(v, l, mid, r);
    }
}

int main()
{
    vector<int> v = {1, 10, 11, 9, 14, 3, 2, 20, 19};

    cout << "Vector Before Sorting: " << endl;
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "\n\n";

    mergeSort(v, 0, v.size() - 1);

    cout << "Vector After Sorting: " << endl;
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "\n\n";
    return 0;
}