#include<bits/stdc++.h>
using namespace std;
void rev(stack<int>st,int element)
{
	if(st.empty()) return;
	element=st.top();
	st.pop();
	rev(st,element);
	st.push(element);
	return;

}
int main()
{
	int x;
	stack<int>st;
	while(true)
	{
		cin>>x;
		if(x==-1) break;
		st.push(x);

	}
	rev(st,st.top());
	while(!st.empty())
	{
		cout<<st.top()<<endl;
		st.pop();
	}

}
