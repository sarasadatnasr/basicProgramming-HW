// C++ program to merge k sorted arrays of size n each.
#include<bits/stdc++.h>
using namespace std;

// A utility function to print array elements
void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

// This function takes an array of arrays as an argument and
// All arrays are assumed to be sorted. It merges them together
// and prints the final sorted output.
void mergeKArrays(int arr[][100], int a, int output[],int n)
{
	int c=0;
	
	//traverse the matrix
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<n ;j++)
			output[c++]=arr[i][j];
	}
	
	//sort the array
	sort(output,output + n*a);
	
}



// Driver program to test above functions
int main()
{
    int n, size, temp= 0;
    cin>>n;
    int arr[n][100];
    for(int i = 0 ; i < n ;i++){
        cin>>temp; 
		size += temp;
        for(int j = 0 ; j < temp ;j++){
           cin>>arr[i][j];
        }
    }

	
	int output[temp];
	mergeKArrays(arr,0,2, output,n);

	cout << "Merged array is " << endl;
	printArray(output, n*k);

	return 0;
}
