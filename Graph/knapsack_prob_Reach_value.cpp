#include<bits/stdc++.h>
using namespace std;
bool knapsack(long long int st,long long int n)
{
	if(st==n) return true;
	if(st>n) return false;
	bool op1=knapsack(st*10,n);
	bool op2=knapsack(st*20,n);
	return op1 || op2;
}
int main()
{
	long long int n;
	int tc;
	cin>>tc;
	while(tc--)
	{
	cin>>n;
	int st=1;
	//knapsack(st,n);
	if(knapsack(st,n))
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	}

}
