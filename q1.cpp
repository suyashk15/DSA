/*
 * Binary Search
 *
 * First occurence of an element in a sorted array
 *
 * Last occurence of an element in a sorted array
 *
 * Count of an element in a sorted array
 *
 * No. of times a sorted array is rotated
 *
 * Find element in sorted rotated array
 *
 * Search in a nearly sorted array
 *
 * Find floor of an element in a sorted array
 *
 * Peak Element
 *
 * Search in Row wise And Column wise Sorted Array
 *
 * Allocate Books [IMP]
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int binarySearchItr(int arr[], int start, int end, int ele)
{
  while (start <= end)
  {
    int mid = start + (end-start)/2;

    if (arr[mid] == ele) return mid;

    if (arr[mid] < ele) start = mid + 1;

    else end = mid - 1;
  }

  return -1;
}

int binarySearchRec(int arr[], int start, int end, int ele)
{
    if (end >= start)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == ele)
            return mid;

        if (arr[mid] > ele)
            return binarySearchRec(arr, start, mid - 1, ele);

        return binarySearchRec(arr, mid + 1, end, ele);
    }

    return -1;
}

int firstocc(int arr[], int start, int end, int ele)
{
	int ans = -1;
	 while (start <= end)
	  {
	    int mid = start + (end-start)/2;

	    if (arr[mid] == ele)
	    {
	    	ans = mid;
	    	end = mid-1;
	    }

	    else if (arr[mid] < ele)
	        start = mid + 1;

	    else
	         end = mid - 1;
	  }

	return ans;
}

int lastocc(int arr[], int start, int end, int ele)
{
	 int ans = -1;
	 while (start <= end)
	  {
	    int mid = start + (end-start)/2;

	    if (arr[mid] == ele)
	    {
	    	ans = mid;
	    	start = mid+1;
	    }

	    else if (arr[mid] < ele)
	        start = mid + 1;

	    else
	         end = mid - 1;
	  }

	return ans;
}

int count(int arr[], int size, int ele)
{
	return lastocc(arr,0,size-1,ele) - firstocc(arr,0,size-1,ele) + 1;
}

int noOfRotations(int arr[], int start, int end, int N)
{
	while(start<=end)
	{
		int mid = start + (end-start)/2;
		int prev = (mid + N - 1)%N;
		int next = (mid+1)%N;

		if(arr[mid]<=arr[prev] and arr[mid]<=arr[next]) return mid;

		if(arr[0]<=arr[mid]) start=mid+1;

		else if(arr[mid]<=arr[N-1]) end = mid-1;
	}
	return -1;
}

int findEle(int arr[], int start, int end, int N, int ele)
{
	int index = noOfRotations(arr,start,end,N-1); //Index of minimum element

	return max(binarySearchItr(arr,start,index,ele), binarySearchItr(arr,index,N-1,ele));
	// Any one function will return -1. So max will be the ans.
}

int EleInNsa(int arr[], int start, int end, int ele)
{
	// Nsa means ith element can be at i-1,i,i+1

	while(start <= end)
	{
		int mid = start + (end-start)/2;

		if(arr[mid]==ele) return mid;

		if(mid-1>=start and arr[mid-1]==ele) return mid-1; //Checking at i-1 position, avoiding mid<0

		if(mid+1<=end and arr[mid+1]==ele) return mid+1;  //Checking at i+1 position, avoiding mid>N

		else if(arr[mid]<ele) start = mid+2; //Already checked at mid+1

		else if(arr[mid]>ele) end = mid-2; //Already checked at mid-1
	}
	return -1;
}

int findFloor(int arr[], int start, int end, int ele)
{
	//floor is largest element <= element in the given array
	int ans;
	while(start<=end)
	{
		int mid = start + (end-start)/2;

		if(arr[mid]==ele) return arr[mid];

		else if(arr[mid]<ele)
		{
			ans = arr[mid];  // Since ans is less than ele, it can be the floor
			start = mid+1;
		}
		else if(arr[mid]>ele) end = mid-1;
	}
	return ans;
}

int findPeak(int arr[], int start, int end, int N)
{
	while(start<=end)
	{
		int mid = start + (end-start)/2;

		if(mid>0 and mid<N-1)
		{
			if(arr[mid-1]<=arr[mid] and arr[mid]>=arr[mid+1]) return mid;  //Peak element

			else if(arr[mid+1]>=arr[mid]) start = mid+1;   // Move to the right part of array

			else if(arr[mid-1]>=arr[mid]) end = mid-1;  // Move to the left part of array
		}

		else if(mid==0)
			{
				if(arr[mid+1]<=arr[mid]) return mid;
				else return 1;
			}

		else if(mid==N-1)
			{
				if(arr[mid-1]<=arr[mid]) return mid;
				else return N-2;
			}
	}
		return -1;
}

pair<int,int> matSearch(vector<vector<int>> &arr, int n, int m, int key)
{
	int i = 0;     // Top right corner
	int j = m-1;
	pair<int,int> result;

	while(i<n and j>=0)
	{
		if(arr[i][j] == key)
			{
				result.first=i;
				result.second=j;
				return result;
			}

		else if(arr[i][j] > key) j--;   // All enteries below that will also be > than key, so move to left column

		else if(arr[i][j] < key) i++;
	}

	cout << "Element not found" <<endl;
	return result;
}

//IMP Question Book Allocation starts:
bool isValid(int arr[], int k, int n, int mid)
{
	// Returns whether our estimate of max no. of pages is valid or not

	int students = 1;  // No. of students required for mid to be an ans
	int sum = 0;		// Should be less than mid for a student

	for(int i=0; i<n; i++)
	{
		sum += arr[i];

		if(sum>mid)
		{
			students++;
			sum = arr[i]; //For new student, first book will have arr[i] pages
		}

		if(students > k) return false;
	}

	return true;
}

int allocateBooks(int arr[], int k, int n)
{
	int start = 0;
	int end = 0;
	int ans = 0;

	if(n<k) return -1;  // If no. of books is less than no. of students, its impossible

	for(int i=0; i<n; i++)
	{
		if(arr[i]>start) start = arr[i];   //Start will finally be maximum element from the array

		end += arr[i];    // End will be equal to sum of all elements
	}

	while(start<=end)
	{
		int mid = start + (end-start)/2;

		if(isValid(arr,k,n,mid)==true)
		{
			ans = mid;  // mid can be a possible ans
			end = mid-1; // We have to minimize mid, so we move to the left
		}
		else start = mid+1;  // If isValid returns false, increase the no. of pages
	}

	return ans;
}


int main()
{
    //int arr[] = {11,12,15,18,2,5,6,8};
    //int arr2[] = {5,10,30,20,40};
	//int arr[] = {1,2,3,4,8,10,10,12,19};
    //int size = sizeof(arr)/sizeof(arr[0]);
//    vector<vector<int>> v = {{10,20,30,40}, {15,25,35,45}, {27,29,37,48}, {32,33,39,50}};
//    pair<int,int> p = matSearch(v,4,4,29);

	int arr[] = {10,20,30,40};
	int k = 2;

    cout << allocateBooks(arr,k,4);

	return 0;
}



