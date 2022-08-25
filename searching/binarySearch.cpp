#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &nums, int t)
{
    int l = 0, r = nums.size() - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] == t)
            return true;
        else if (nums[mid] > t)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int t = 7;

    cout << binarySearch(nums, t) << endl;

    return 0;
}