#include<bits/stdc++.h>
using namespace std;
class Myq
{
public:
	stack<int> st;
	stack<int> temp;
	void enque(int val)
	{
	   st.push(val);
	}
	void dequ()
	{
		while(!st.empty())
		{
			int t=st.top();
			st.pop();
			if(st.empty())
			{
			  break;
			}
			else
			{
			   temp.push(t);
			}
		}
		while(!temp.empty())
		{
			st.push(temp.top());
			temp.pop();
		}
	}
	void frnt()
	{
		while(!st.empty())
		{
			int f=st.top();
			temp.push(f);
			st.pop();
			if(st.empty())
			{
				cout<<f<<endl;
			}
		}
		while(!temp.empty())
		{
			st.push(temp.top());
			temp.pop();
		}
	}
};
int main()
{
	int q;
	cin>>q;
	int op;
	int x;
	Myq que;
	while(q--)
    {
    	cin>>op;
    	if(op==1)
		{
			cin>>x;
			que.enque(x);
		}
		else if(op==2)
		{
			que.dequ();
		}
		else if(op==3)
		{
			que.frnt();
		}


	}
}
