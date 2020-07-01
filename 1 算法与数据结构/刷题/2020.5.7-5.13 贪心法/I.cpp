//#include<bits/stdc++.h>
#include<cstdio>  
#include<cstring>  
#include<queue>  
#include<cmath>  
#include<algorithm> 
#include<iostream>
//https://www.cnblogs.com/Kiven5197/p/7346127.html
using namespace std;

int main(){
	int n;
	while(cin>>n&&n){
		double x,temp;
		priority_queue<double> q;
		for(int i=0;i<n;i++){
			cin>>x;
			q.push(x);
		}
		while(q.size()>1){
			double a=q.top();
			q.pop();
			double b=q.top();
			q.pop();
			temp=2*sqrt(a*b);
			q.push(temp);
		}
		printf("%.3f\n",q.top());
		//cout<<q.top()<<endl;
	}
	
}