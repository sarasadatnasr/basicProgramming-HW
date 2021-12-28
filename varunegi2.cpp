// C++ program for implementation of Bubble sort
#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
int bubbleSort(int arr[], int n)
{
	int i, j ,k=0;
	for (i = 0; i < n-1; i++){
	
	// Last i elements are already in place
	for (j = 0; j < n-i-1; j++){
		if (arr[j] > arr[j+1]){
			swap(&arr[j], &arr[j+1]);
            k++;}
        }
    }
    return k;

}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n ;i++){
        cin>>arr[i];
    }
    cout<<bubbleSort(arr, n);
}


// This code is contributed by rathbhupendra
