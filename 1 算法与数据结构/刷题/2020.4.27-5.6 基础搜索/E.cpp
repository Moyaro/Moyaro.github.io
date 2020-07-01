#include<iostream>
#include<stack>
#include<cstdio>
#define N 1005
using namespace std;
int a[N]; 
int main(){
	int n;
	while(cin>>n&&n!=0){
		while(1){
			stack<int> s;
			scanf("%d",&a[0]);
			if(a[0]==0){
				cout<<endl;
				break;
				
			}
			for(int i=1;i<n;i++){
				cin>>a[i];
			}
			int j=0;
			for(int i=1;i<=n;i++){
				s.push(i);
				while(!s.empty()&&s.top()==a[j]){//!s.empty()要放在前面， &&具有短路特性 
					s.pop();
					j++;
				}
			}
			if(s.empty()) cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}

//https://blog.csdn.net/weixin_44484662/article/details/96507109
/*
5
1 2 3 4 5
Yes
5 4 3 2 1
Yes
0

6
6 5 4 3 2 1
Yes
0

0
*/