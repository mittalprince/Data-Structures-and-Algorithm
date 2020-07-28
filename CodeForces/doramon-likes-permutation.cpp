#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<pair<int, int>> ans;
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool front_exist = true;
        set<int> front;
        int i = 0;
        for (; i < n; i++)
        {
            if (front.find(arr[i]) == front.end())
            {
                front.insert(arr[i]);
            }
            else
                break;
        }
        set<int> front_2;
        for (; i < n; i++)
        {
            if (front_2.find(arr[i]) == front_2.end())
            {
                front_2.insert(arr[i]);
            }
            else
            {
                front_exist = false;
                break;
            }
        }
        if ((front.size() != *(--front.end())) || (front_2.size() != *(--front_2.end())) || front.empty() || front_2.empty())
        {
            front_exist = false;
        }
        if (front_exist)
        {
            ans.push_back(make_pair(front.size(), front_2.size()));
        }
        bool last_exist = true;
        set<int> last;
        int j = n - 1;
        for (; j >= 0; j--)
        {
            if (last.find(arr[j]) == last.end())
            {
                last.insert(arr[j]);
            }
            else
                break;
        }
        set<int> last_2;

        for (; j >= 0; j--)
        {
            if (last_2.find(arr[j]) == last_2.end())
            {
                last_2.insert(arr[j]);
            }
            else
            {
                last_exist = false;
                break;
            }
        }
        if ((last.size() != *(--last.end())) || (last_2.size() != *(--last_2.end())) || last.empty() || last_2.empty())
        {
            last_exist = false;
        }
        if (last_exist)
        {
            if (last_2.size() == front.size() && last.size() == front_2.size())
            {
            }
            else
                ans.push_back(make_pair(last_2.size(), last.size()));
        }

        if (ans.empty())
        {
            cout << "0\n";
        }
        else
        {
            cout << ans.size() << endl;
            for (auto i : ans)
            {
                cout << i.first << " " << i.second << endl;
            }
        }
    }
}