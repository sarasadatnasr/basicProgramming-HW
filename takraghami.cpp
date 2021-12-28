#include<iostream>
using namespace std;

int digit(long);

int main(){
long number;
long source;
cin>>number;
while(number>=10){
number=digit(number);
}
cout<<number;
}

int digit(long n){
	int s=0;
   	while(n!=0){
	s+=(n%10);
	n=n/10;
    }
return s;
}

