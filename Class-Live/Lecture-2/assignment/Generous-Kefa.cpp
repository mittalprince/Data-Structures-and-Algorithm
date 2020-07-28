#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int arr[26] = {0};
    for (int i = 0; i < n; i++)
    {
        arr[s[i] - 'a']++;
        if (arr[s[i] - 'a'] > k)
        {
            // cout<<arr[s[i]-'a']<<" "<<s[i]<<endl;
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}