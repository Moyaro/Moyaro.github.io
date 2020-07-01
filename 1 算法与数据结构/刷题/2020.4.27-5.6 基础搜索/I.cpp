#include<iostream>
using namespace std;
//https://www.cnblogs.com/ssfzmfy/p/4612719.html

int f[10];
int main(){
	int n,p, first=0;//是否为输出的第一个数的标记，用来控制2组测试数据间的空格 
	while (cin>>n&&n!=0){
		if (first)cout<<endl;
		p=0;
		for (int i=0;i<=9;i++) f[i]=0;
		for(int i=1000;i<=55555;i++){
			for (int j=0;j<=9;j++) f[j]=0;
			if (i<10000)
				f[i%10]=f[i/10%10]=f[i/100%10]=f[i/1000%10]=1;
			else 
				f[i%10]=f[i/10%10]=f[i/100%10]=f[i/1000%10]=f[i/10000]=1;
			int j=n*i;
			if (j<100000) 
				f[j%10]=f[j/10%10]=f[j/100%10]=f[j/1000%10]=f[j/10000]=1;
			int s=0;
			for (int k=0;k<=9;k++)    s=s+f[k];
			if (i<10000&& s==9&&f[0]==0) {cout<<j<<" / 0"<<i<<" = "<<n<<endl;p=1; }
			if (s==10) {cout<<j<<" / "<<i<<" = "<<n<<endl;p=1; }
		first=1;
	}
	if(p==0) cout<<"There are no solutions for "<<n<<"."<<endl;
	}
		return 0;    
}