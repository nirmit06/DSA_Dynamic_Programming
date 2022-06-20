#include <bits/stdc++.h>
using namespace std;
int t[10005][10005];
bool LCS(string a, string b, int x, int y)
{
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    if (t[x][y] == x)
    {
        return true;
    }
    return false;
}

int main()
{
    string a, b;
    cin >> a >> b;
    int x = a.size();
    int y = b.size();

    if (LCS(a, b, x, y))
    {
        cout << "Found"
             << "\n";
    }
    else
    {
        cout << "Not found"
             << "\n";
    }
}