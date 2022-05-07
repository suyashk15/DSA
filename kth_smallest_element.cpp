// Identify Problems :
// "k" & array are inputs, involves sorting O(nlogn)
// Using heap, we can reduce it to O(nlogk)
// Types of heap : Min heap -> Minimum Element is at the top (Used to find kth largest element)
//                          => priority_queue <int, vector<int>, greater<int> > minh;
//                 Max heap -> Maximum Element is at the top (Used to find kth smallest element)
//                          => priority_queue <int> maxh;
// k -> size of heap

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,pair<int,int>> ppi;

int main(){
    int A[6] = {7,10,4,3,20,15};
    int n = 6;
    int k = 3;  //Third smallest element

    // Brute Force : O(nlogn)
    //     vector<int> v;
    //     for(int i=0;i<n;i++){
    //         v.push_back(A[i]);
    //     }
    //     sort(v.begin(),v.end());
    //     cout << v[k];

    // Optimised : O(nlogk) 
    priority_queue <int> maxh;
    for(int i=0;i<n;i++){
        maxh.push(A[i]);
        if(maxh.size() > k){
            maxh.pop();        // Delete the top element
        }
    }
    cout<< maxh.top();
}
