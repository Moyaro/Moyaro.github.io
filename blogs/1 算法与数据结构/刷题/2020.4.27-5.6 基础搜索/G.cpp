#include<iostream>
#include<string.h>
using namespace std;

int N;
int M;
char field[1000][1000];

void dfs(int x ,int y)
{
	field[x][y] = '.';

	for (int dx = -1; dx <= 1;++dx)
	{
		for (int dy = -1; dy <= 1;++dy)
		{
			int nx = x + dx;
			int ny = y + dy;
			if(0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W')//判断有误出界，是否为W
			{
				dfs(nx, ny);
			}
		}
	}
	return;
}

int main()
{
	int res = 0;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++) cin>>field[i][j];
	}
	for (int i = 0; i < N;++i)
	{
		for (int j = 0; j < M;++j)
		{
			if(field[i][j]=='W')
			{
				dfs(i, j);
				res++;
			}
		}
	}

	cout << res << endl;
}
