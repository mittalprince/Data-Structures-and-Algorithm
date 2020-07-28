#include<iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int freq[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 'a']++;
    }
    int ct = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] & 1)
            ct++;
    }
    if (ct <= 1)
        cout << "First\n";
    else
    {
        if (ct & 1)
            cout << "First\n";
        else
            cout << "Second\n";
    }
    return 0;
}