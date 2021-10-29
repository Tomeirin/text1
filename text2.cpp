#include <iostream>
using namespace std;
int dx[]={0,1,-1,0,0};
int dy[]={0,0,0,-1,1};
int n,m;
int sum;
int map[501][501];

void search(int x,int y)
{
	map[x][y]=1;
	for(int i=1;i<=4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(map[nx][ny]==0&&nx>0&&nx<=n&&ny>0&&ny<=m)
		{
			search(nx,ny);
		}
	}
}

int main()
{
	char a;
	cout<<"ÇëÊäÈëx,y"<<endl;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a;
			if(a=='*')
			{
				map[i][j]=1;
			}
			else
			{
				map[i][j]=0;
			}

		}
	}
	for(int i=1;i<=n;i++)
	{
		if(map[i][1]==0)
		{
			search(i,1);
		}
		if(map[i][m]==0)
		{
			search(i,m);
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(map[1][i]==0)
		{
			search(1,i);
		}
		if(map[n][i]==0)
		{
			search(n,i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(map[i][j]==0)
			{
				sum++;
			}
		}
	}
	cout<<sum<<endl;
	system("pause");
	return 0;
}

