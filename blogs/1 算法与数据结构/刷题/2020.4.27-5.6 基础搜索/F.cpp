#include<iostream>
#include<queue>
#include<cstdio>
#include<string.h>
/*queue的基本操作有：
入队，如例：q.push(x); 将x接到队列的末端。
出队，如例：q.pop(); 弹出队列的第一个元素，注意，并不会返回被弹出元素的值。
访问队首元素，如例：q.front()，即最早被压入队列的元素。
访问队尾元素，如例：q.back()，即最后被压入队列的元素。
判断队列空，如例：q.empty()，当队列空时，返回true。
访问队列中的元素个数，如例：q.size()*/

using namespace std;
int main(){
	        int n;
			cin>>n;
			char a[10000];
			int j=0;
			queue<int> s;
			cin>>a[0];
			//scanf("%d",&a[0]);
			gets(a);
			/*for(int i=1;i<n;i++){
				cin>>a[i];
			}*/
			for(int i=1;i<=n;i++){
				if(s.front()==a[i]){					
					if(j<s.size()) j=s.size();
					s.pop();
					}
				s.push(i);				
			}
		cout<<j;

	return 0;
}	