#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Whether Subset is present or not 

bool subsetsum(int A[], int sum, int n){

    //int n = A.size();
    bool dp[n+1][sum+1];

    // Initialization :
    for(int i=0;i<=n;i++){
        dp[i][0] = true;   
    }
    for(int j=1;j<=sum;j++){
        dp[0][j] = false;    
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(A[i-1] <= j){
                dp[i][j] = (dp[i-1][j - A[i-1]]) || (dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

// Count of subsets :

int subsetcount(int A[], int sum, int n){

    int dp[n+1][sum+1];

    // Initialization :
    for(int i=0;i<=n;i++){
        dp[i][0] = true;   
    }
    for(int j=1;j<=sum;j++){
        dp[0][j] = false;    
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(A[i-1] <= j){
                dp[i][j] = (dp[i-1][j - A[i-1]]) + (dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

// Number of Subsets with given difference :

int scount(int A[], int diff, int n){

    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum + A[i];
    }

    int s1 = (sum + diff)/2; // Simple math : s1 - s2 = diff & s1 + s2 = sum => s1 = (sum+diff)/2

    return subsetcount(A,s1,n);

}

int main(){
    int A[5] = {1,1,2,3};
    int sum = 3;
    int n = 4;
    int diff = 1;
    cout << subsetsum(A,sum,n) << endl;
    cout << subsetcount(A,sum,n) << endl;
    cout << scount(A,diff,n) << endl;
}
