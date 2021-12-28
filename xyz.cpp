#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string>

using namespace std;

void getWords(string words[], int numbers)
{
	for(int i=0 ; i<numbers ; i++)
	{
		cin>>words[i];
		}	
}
void printArray(string words[], int numbers)
{
	for(int i=0 ; i<numbers ; i++)
	{
		cout<<(words[i])<<" ";
	}
}

void CountSort(string arr[], int sz, int l) 
{
	int i, j, k;
	int idx = 0;
	int min, max;
 
	min = max = 10*(int(arr[0][0]))+(int(arr[0][1])-48);
	for(i = 1; i < sz; i++) {
		min = (10*(int(arr[i][0]))+(int(arr[i][1])-48) < min) ? 10*(int(arr[i][0]))+(int(arr[i][1])-48) : min;
		max = (10*(int(arr[i][0]))+(int(arr[i][1])-48) > max) ? 10*(int(arr[i][0]))+(int(arr[i][1])-48) : max;
	}
 
	k = max - min + 1;
	int *B = new int [k]; 
	for(i = 0; i < k; i++) B[i] = 0;

	for(i = 0; i < sz; i++) B[10*(int(arr[i][0]))+(int(arr[i][1])-48) - min]++;
	for(i = min; i <= max; i++) 
	{
		for(j = 0; j < B[i - min]; j++) 
		{
			string n;
			n.push_back(char(i/10));
			n.push_back(char(i%10+48));
			(arr[idx++]) = n;
		}
	}
 

	delete [] B;
}

void radixsort(string arr[], int n)
{
	int m=2;
    for(int i=m-1 ; i>=1 ; i--)
    {
    	CountSort(arr, n, i);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int numbers;
	cin>>numbers;
	string words[numbers];
	getWords(words, numbers);
	radixsort(words , numbers);
	printArray(words, numbers);
	
}