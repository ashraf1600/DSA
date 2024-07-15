//Geeekforgeeks stock span problem
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<int>v(n),x;
  for(int i=0;i<n;i++)
  {
	cin>>v[i];
  }
  int c=1;
  stack<int>st1;
  stack<int>st2;
  st1.push(v[0]);
  x.push_back(c);
  for(int i=1;i<n;i++)
  {
    while(!st1.empty() && v[i]>=st1.top())
	{
		c++;
		st2.push(st1.top());
		st1.pop();
	}

	while(!st2.empty())
	{
		st1.push(st2.top());
		st2.pop();
	}
	st1.push(v[i]);
	x.push_back(c);

	c=1;
  }
  for(auto u:x)
  {
	cout<<u<<" ";
  }
  cout<<endl;
}
