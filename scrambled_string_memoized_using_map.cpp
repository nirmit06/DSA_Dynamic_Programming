#include <bits/stdc++.h>
using namespace std;
unordered_map<string, bool> mp;
    bool isScramble(string s1, string s2)
    {
        int x = s1.length(), y = s2.length();

        if (s1.compare(s2) == 0)
        {
            return true;
        }

        if (x <= 1)
        {
            return false;
        }
        string st = s1;
        st.push_back(' ');
        st.append(s2);
        if (mp.find(st) != mp.end())
        {
            return mp[st];
        }

        bool flag = false;
        for (int i = 1; i <= x - 1; i++)
        {
            if ((isScramble(s1.substr(0, i), s2.substr(x - i, i)) && isScramble(s1.substr(i, x - 1), s2.substr(0, x - i))) || (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, x - i), s2.substr(i, x - 1))))
            {
                flag = true;
                break;
            }
        }
        return mp[st] = flag;
    }

int main()
{
    string a, b;
    cin >> a >> b;
    if (a.length() != b.length())
    {
        cout << "No,it is not a scrambled string !"
             << "\n";
        return 0;
    }

    if (a.length() == 0 && b.length() == 0)
    {
        cout << "Yes,it is a scrambled string !"
             << "\n";
        return 0;
    }

    if (isScramble(a, b))
    {
        cout << "Yes,it is a scrambled string !"
             << "\n";
    }
    else
    {
        cout << "No,it is not a scrambled string !"
             << "\n";
    }
}