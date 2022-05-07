#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int ksrec(int val[], int wt[], int W, int n){

    int dp[n+1][W+1];
    memset(dp,-1, sizeof(dp));  // Memorization

    if(n == 0 || W== 0){
        return 0;    // Base condition 

    if(dp[n][W] != -1){
        return dp[n][W]; // Avoiding recalculation
    }
    }
    if(wt[n-1]<=W){
        return dp[n][W] = max(val[n-1]+ ksrec(val, wt, W-wt[n-1], n-1) , ksrec(val, wt, W, n-1));
        // returning maximum of : 1) We choose to add the item, thus its value is added to profit and weight of knapsack is reduced by its wight
       //                         2) Exclude the item and move to the next one   
    }
    else{
        return dp[n][W] = ksrec(val,wt,W,n-1);  // Exclude the item and move to the next one   

    }
}

int main(){
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int W = 50;
    int n = 3;
    cout << ksrec(val,wt,W,n);
}