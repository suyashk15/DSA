#include <bits/stdc++.h>

using namespace std;

int solve(int arr[], int n, int m)
{
    sort(arr, arr+n);

    int start = 0;
    int end = m-1;
    int diff = arr[end]-arr[start];

    while(end<n)
    {
        diff = min(diff, arr[end++]-arr[start++]);
    }
    return diff;
}

int main()
{
    int arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int n = 17;
    int m = 7;

    cout << solve(arr, n, m);
}