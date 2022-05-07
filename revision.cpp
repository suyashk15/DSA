#include <bits/stdc++.h>
using namespace std;

int knapsack(int val[], int w[], int cap, int n)
{
    int dp[n+1][cap+1];

    for(int i=0; i<n+1; i++)
        dp[i][0] = 0;

    for(int j=0; j<cap+1; j++)
        dp[0][j] = 0;

    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<cap+1; j++)
        {
            if(w[i-1]<=j)
                dp[i][j] = max(val[i-1] + dp[i-1][j-w[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][cap];
}

int main(){
    int val[] = {60,100,120};
    int w[] = {10,20,30};
    int cap = 50;
    int n = 3;
    cout << knapsack(val,w,cap,n);
}