#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &arr, int target)
{
    int n = arr.size();
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if(arr[mid] == target || arr[s] == target || arr[e] == target) return true;
        if(arr[s] < arr[mid]){
            if(target > arr[s] && target < arr[mid]){
                e=mid-1;
            }
            else s=mid+1;
        }
        else if(arr[mid] < arr[e]){
            if(target > arr[mid] && target < arr[e]){
                s=mid+1;
            }
            else e=mid-1;
        }
        else e--;
    }
    return false;
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
    int k;
    cin >> k;
    cout << search(arr, k) << endl;
    return 0;
}