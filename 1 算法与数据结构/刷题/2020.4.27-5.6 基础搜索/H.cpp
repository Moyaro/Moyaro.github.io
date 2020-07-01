#include <bits/stdc++.h>//万能头文件
using namespace std;
struct Node{
	int r,c,dir;
	Node(int r=0, int c=0, int dir=0):r(r),c(c),dir(dir) {}
};

int have_edge[10][10][4][3];
int d[10][10][4];
Node pre[10][10][4];
int r0,c0,r1,c1,rf,cf,init_dir;
const char* dirs = "NESW"; //  0123
const char* turns = "FLR";//0不动 1左 顺时针 2右 逆时针

int id_dir(char s){ return strchr(dirs,s) - dirs;}
int id_turn(char s){return strchr(turns,s) - turns;}

const int dr[] = {-1, 0, 1, 0}; //dirs为上右下左
const int dc[] = {0, 1, 0, -1};

bool input(){
	char s1[99], s2[99];
	int o;
	if((o = scanf("%s%d%d%s%d%d",s1,&r0,&c0,s2,&rf,&cf) )!= 6) { return false;}
	printf("%s\n", s1);
	init_dir = id_dir(s2[0]);
	r1 = r0 + dr[init_dir];
	c1 = c0 + dc[init_dir];
//    printf("%d %d %d\n", init_dir,r1,c1);
	memset(have_edge,0,sizeof(have_edge));
	for(;;){
		int r,c;
		scanf("%d", &r);
		if(r == 0) break;
		scanf("%d", &c);
		while(scanf("%s", &s2) && s2[0] != '*'){
			int len = strlen(s2);
			for(int i = 1; i < len; i++){
				have_edge[r][c][id_dir(s2[0])][id_turn(s2[i])] = 1;
			}
		}
	}
	return true;
}
Node walk(const Node& u, int turn){
   int dir = u.dir;
   if(turn == 1) dir = (u.dir+3)%4;
   else if(turn == 2) dir = (u.dir+1) %4;
   return Node(u.r + dr[dir], u.c + dc[dir] , dir);
}

bool inside(int r, int c) {
  return r >= 1 && r <= 9 && c >= 1 && c <= 9;
}
void print_ans(Node u){
	vector<Node> ans;
	for(;;){
		ans.push_back(u);
		if(d[u.r][u.c][u.dir] == 0)
			break;
		u = pre[u.r][u.c][u.dir];
	}
	ans.push_back(Node(r0,c0,init_dir));

	int cnt  = 0;
	for(int i = ans.size() -1; i >= 0; i--){
		if(cnt % 10 == 0) printf(" ");
		printf(" (%d,%d)", ans[i].r, ans[i].c);
		if(++cnt % 10 == 0) printf("\n");
	}
	if(ans.size() % 10 != 0) printf("\n");
}
void solve(){
   queue<Node> q;
   memset(d,-1,sizeof(d));
   d[r1][c1][init_dir] = 0;
   Node u(r1,c1,init_dir);
   q.push(u);
   while(!q.empty()){
		Node u = q.front(); q.pop();
//        printf("$   u %d %d %d\n",u.r, u.c,u.dir);
		if(u.r == rf && u.c == cf){
			print_ans(u);
			return;
		}
		for(int i = 0; i < 3; i++){
			 Node v;
			if(have_edge[u.r][u.c][u.dir][i])
			   v = walk(u,i);
//            printf("&   v %d %d %d\n",v.r, v.c, v.dir);
			if(inside(v.r,v.c) && d[v.r][v.c][v.dir] < 0){
				d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
				pre[v.r][v.c][v.dir] = u;
				q.push(v);
			}
		}
   }
	printf("  No Solution Possible\n");
}
int main(){
	while(input()){
		solve();
	}
	return 0;
}
//https://www.cnblogs.com/Jadon97/p/7204857.html