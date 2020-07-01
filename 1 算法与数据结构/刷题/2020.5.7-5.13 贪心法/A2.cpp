//#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<String.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);//cin，cout之所以效率低，是因为先把要输出的东西存入缓冲区，再输出，导致效率降低，而这段语句可以来打消iostream的输入 输出缓存，可以节省许多时间，使效率与scanf与printf相差无几，
	int n;
	cin>>n;
	char s[n+1];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	int a=0,b=n-1,ans=0;
	while(a<=b){
		int flag=0;
		for(int i=0;a+i<=b;i++){//若首位相等则比较下一个 
			if(s[a+i]<s[b-i]){
				flag=1;
				break;
			}
			if(s[a+i]>s[b-i]){
				flag=0;
				break;
			}
		}
		if(flag){
			cout<<s[a++];
			ans++;
		}
		else{
			cout<<s[b--];
			ans++;
		}
		if(ans==80){
			ans=0;
			cout<<endl;
		}
	}
	cout<<endl; 
	return 0;
}