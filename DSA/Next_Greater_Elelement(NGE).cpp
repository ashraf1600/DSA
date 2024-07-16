#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	stack<int>st;
	vector<int>ans(n);
	ans[n-1]=-1;
	st.push(v[n-1]);
	for(int i=n-2;i>=0;i--)
	{
		while(!st.empty() && v[i]>=st.top())
		{
			st.pop();
		}
		if(st.empty())
		ans[i]=-1;
		else ans[i]=st.top();
		st.push(v[i]);
	}
	for(auto u:ans)
	{
		cout<<u<<" ";
	}
}
