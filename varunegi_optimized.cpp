#include <iostream>
#include <stdio.h>

using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int bubbleSort(int arr[], int n)
{
   int i, j, k=0;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
            k++;
           swapped = true;
        }
 
     if (swapped == false)
        break;
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
