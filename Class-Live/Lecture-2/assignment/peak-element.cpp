#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    int s = 0, e = n - 1;
    while (s < e)
    {
        int mid = (e + s) / 2;
        if (nums[mid] > nums[mid + 1])
        {
            e = mid;
        }
        else
        {
            s = mid + 1;
        }
    }
    return s;
}

int main()
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << findPeakElement(arr) << endl;
        return 0;
    }