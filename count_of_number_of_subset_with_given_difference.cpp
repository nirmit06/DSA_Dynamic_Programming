#include <bits/stdc++.h>
using namespace std;
int t[10005][10005];

int count_of_subset_sum(int arr[], int x, int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < x + 1; j++)
        {
            if (i == 0)
            {
                t[i][j] = 0;
            }
            if (j == 0)
            {
                t[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < x + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        {
            for (int j = 0; j <= x; j++)
                cout << t[i][j] << " ";
        }
        cout << endl;
    }
    return t[n][x];
}

int main()
{
    int n;
    cin >> n;
    int dif;
    cin >> dif;
    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    int x = (dif + sum) / 2;

    cout << count_of_subset_sum(arr, x, n) << "\n";
}