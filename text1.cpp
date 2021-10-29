#include <iostream>
using namespace std;
int v[25],w[25];
int dp[25][30000]={0};
int sum=0;
int max(int i,int j)
{
	if(i>j)return i;
	else return j;
}
void find(int i,int j)
{
	if(i==0)
	{
		cout<<sum<<endl;
		return;
	}
	if(dp[i][j]==dp[i-1][j])
	{
		find(i-1,j);
	}
	else if(dp[i][j]==dp[i-1][j-v[i]]+w[i])
	{
		sum+=v[i]*w[i];
		find(i-1,j-v[i]);
	}
}
int main()
{
	int n,m;
	cout<<"请输入总钱数和希望购买物品的个数"<<endl;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>v[i]>>w[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(v[i]>j)
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
		}
	}
	find(m,n);
	system("pause");
	return 0;
}

