#include <iostream>
using namespace std;

int solve(int val[], int wt[], int n, int W){
    int dp[n+1][W+1];  // 1st row and 1st column are initializations, thus size of dp is (n+1)x(W+1)

    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0 || j==0){ // Cases : Capacity of knapsack = 0 or no items given (empty array)
                dp[i][j] = 0; // Initialize 1st row and and 1st column by zeros
            }
            else if(wt[i-1]<=j){ // If weight of item is less than the knapsack capacity  (Doubt j or W)
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]] , dp[i-1][j] );
                              // If we include               If we exclude
                              // i -> n (Traversal through weight and value arrays)
                              // j -> wt (Through the wt array)
            }
            else{
                dp[i][j] = dp[i-1][j]; // exclude the item
            }
        }
    }
    return dp[n][W];
}

int main(){
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int W = 50;
    int n = 3;
    cout << solve(val,wt,n,W);
}