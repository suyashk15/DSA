#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A){
    int n = A.size();
    if(n==0 || n==1){
        return 1;
    }
    vector<int> res(n,1);
    int i = 0;
    while(i<n){
        int start = A[i];
        for(int j=i+1;j<n;j++){
            if(A[j] > start){
                res[i] = res[i] + 1;
                start = A[j];
            }
        }
        i++;
    }
    sort(res.begin(),res.end());

    for(int i=0;i<n;i++){
        cout << res[i] << " ";
    }
    return res[n-1];
}

int main(){
    int b[] = {5,2,7};
    vector<int> A;
    for(int i=0;i<3;i++){
        A.push_back(b[i]);
    }
    cout << solve(A);
}