#include<cstdio>
#include<cstring>
using namespace std;
//https://blog.csdn.net/r1041953637/article/details/79822952
//https://www.cnblogs.com/luruiyuan/p/5847706.html
const int maxn = 10;
int id[256], letter[maxn];
int G[maxn][maxn]; 
 
int A[maxn],ans[maxn],vis[maxn];
int n,sw; //sw为最优带宽 
 
void dfs(int cur,int bw){ //bw为当前排列的最大带宽 
	if(cur==n){ //走到这里一定是当前最优的了
			memcpy(ans,A,sizeof(int)*n);
			sw=bw;
	}
	else for(int i=0;i<n;i++){
		if(!vis[i]){
			
			//最理想性剪枝
			int m=0; 
			for(int j=0;j<cur;j++){
				if(G[i][j]&&!vis[j]) m++;
			}
			if(m>=sw) break; 
			
			//最优性剪枝 
			int ok=1;
			A[cur]=i;
			for(int j=0;j<cur;j++){
				if(G[A[j]][i]){
					int w=cur-j;
					if(w>=sw){ //当前的最大带宽已经不小于最优解了。放弃
						ok=0;break;
					}
					if(w>bw) bw=w;
				} 
			}
			if(ok) {
				vis[i]=1;
				dfs(cur+1,bw);
				vis[i]=0;
			}
			else{
				break; //如果i在cur带宽已经超了，在cur之后更大，直接跳过cur 
			}
		}
	}
}
 
int main() {
	char input[1000];
	while(scanf("%s", input) == 1 && input[0] != '#') {
		// 计算结点个数并给字母编号
		n = 0;
		for(char ch = 'A'; ch <= 'Z'; ch++)
		if(strchr(input, ch) != NULL) {
			id[ch] = n++;
			letter[id[ch]] = ch;
		}
		sw=n;
	
		// 处理输入
		int len = strlen(input), p = 0, q = 0;
		memset(G,0,sizeof(G));
		for(;;) {
			while(p < len && input[p] != ':') p++;
			if(p == len) break;
			while(q < len && input[q] != ';') q++;
			for(int i = p+1; i < q; i++) {
				G[id[input[p-1]]][id[input[i]]]=1;
				G[id[input[i]]][id[input[p-1]]]=1;
			}
			p++; q++;
			}
	
			// 回溯 
			memset(vis,0,sizeof(vis));
			dfs(0,0);
 
			// 输出
			for(int i = 0; i < n; i++) printf("%c ", letter[ans[i]]);
			printf("-> %d\n", sw);
	}
	return 0;
}