#include <bits/stdc++.h>
using namespace std;

int LIS(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    int len=1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind]=arr[i];
        }
        for(int j=0;j<temp.size();j++){
            cout<<temp[j]<<" ";
        }
        cout<<"-\n";
    }
    return len;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << LIS(arr, n) << "\n";
}