#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void Merge(int A[], int low, int mid, int high){
    int i,j,k;
    int b = (high - low) + 1;
    int B[b];
    i = low;
    j = mid+1;
    k = low;

    while(i<=mid && j<=high){
        if(A[i]>A[j]){
            B[k] = A[j];
            j++;
            k++;
        }
        else{
            B[k] = A[i];
            i++;
            k++;
        }
    }
    while(i<=mid){
        B[k] = A[i];
        i++;
        k++;
     }
    while(j<=high){
        B[k] = A[j];
        j++;
        k++;
    }
    for(int p=low; p<=high; p++){
        A[p] = B[p];
    }

}
void MergeSort(int A[], int low, int high){
    if(high > low){
        int mid = (low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}

void printArray(int A[], int n){
    for(int i=0; i<=n-1; i++){
        cout<< A[i] << " ";
    }
    cout <<"\n";
}

int main(){
    int A[] = {4,6,7,2,1,9,6};
    int n = 7;
    printArray(A,n);
    MergeSort(A,0,6);
    printArray(A,n);

}