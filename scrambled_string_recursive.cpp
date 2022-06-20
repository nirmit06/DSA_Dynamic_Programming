#include <bits/stdc++.h>
using namespace std;
bool solve(string a, string b)
{
    if (a.compare(b) == 0)
    {
        return true;
    }

    if (a.length() <= 1)
    {
        return false;
    }
    bool flag = false;
    int n = a.length();
    for (int i = 1; i <= n - 1; i++)
    {
        if ((solve(a.substr(0, i), b.substr(n - i, i)) && (solve(a.substr(i, n - 1), b.substr(0, n - i)))) || (solve(a.substr(0, i), b.substr(0, i)) && (solve(a.substr(i, n - 1), b.substr(i, n - i)))))
        {
            flag = true;
            break;
        }
    }

    return flag;
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

    if (solve(a, b))
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