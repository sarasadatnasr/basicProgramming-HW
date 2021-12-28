#include<bits/stdc++.h>
using namespace std;

void printMedians(int arr[], int n)
{
	
	priority_queue<double> s;
	priority_queue<double,vector<double>,greater<double> > g;

	double med = arr[0];
	s.push(arr[0]);
	std::cout << std::fixed;
    std::cout << std::setprecision(1);
    std::cout <<(float) med<< endl;


	for (int i=1; i < n; i++)
	{
		double x = arr[i];

		if (s.size() > g.size())
		{
			if (x < med)
			{
				g.push(s.top());
				s.pop();
				s.push(x);
			}
			else
				g.push(x);

			med = (s.top() + g.top())/2.0;
		}

		else if (s.size()==g.size())
		{
			if (x < med)
			{
				s.push(x);
				med = (double)s.top();
			}
			else
			{
				g.push(x);
				med = (double)g.top();
			}
		}


		else
		{
			if (x > med)
			{
				s.push(g.top());
				g.pop();
				g.push(x);
			}
			else
				s.push(x);

			med = (s.top() + g.top())/2.0;
		}
        std::cout <<(float) med<< endl;
	}
}

int main()
{   int size = 0;
    cin>>size;
    int arr[size];
    for(int i=0 ; i<size ;i++){
        cin>>arr[i];
    }
printMedians(arr, size);
return 0;
}