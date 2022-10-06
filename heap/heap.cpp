#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "empty \n";
            return;
        }

        // step 1 : put last element at 1st
        arr[1] = arr[size];

        // step 2 : remove last element
        size--;

        // step 3 : take root to its correct position
        int i = 1;
        while (i < size)
        {
            int leftId = 2 * i;
            int rightId = 2 * i + 1;

            if (leftId < size && arr[leftId] > arr[i])
            {
                swap(arr[leftId], arr[i]);
                i = leftId;
            }

            if (rightId < size && arr[rightId] > arr[i])
            {
                swap(arr[rightId], arr[i]);
                i = rightId;
            }
            else
                return;
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    heap h;

    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.print();

    h.deleteFromHeap();
    h.print();
    h.deleteFromHeap();
    h.print();
    return 0;
}