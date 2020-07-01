#include<iostream>
#include<stdio.h>
#include<string.h>//<string.h>是标准C提供的字符处理函数集。面向char *.
//<string>是C++特化的字符容器，内含string类。
//<cstring>是C++为兼容C提供的<string.h>的C++版本，里面的主要改进应该是有：将一些隐藏变量编入命名空间；修正一些C++编译器认为Bug的代码。
//在新标准后的标准库中都有一个不带“.h”扩展名的相对应，不带“.h”的升级了并附有std命名空间。但string是个例外，string.h和string，二者没有关系，后者并非前者的升级。


using namespace std;
int main() 
{
	int i = 0, j , k;
	char s[1001], temp;
	gets(s);//gets()方法接受一个字符串，它的参数为char*，而不是string。
	//另外若定义char ch[n]，长度为n，需要注意输入的字符串长度不要大于n，否则会报错，gets()对空格也不敏感，注意，gets()在vs2017中不能使用，应使用gets_s()代替。
	//cin>>s;//根据cin>>a 中a的变量类型读取数据，遇到结束符（Space、Tab、Enter）就结束，且对于结束符，并不保存到a中。
	while(s[i])
	{
		while (s[i] == ' ') i++;
		if(!s[i]) break;//在C语言中没有专门的字	符串变量，通常用一个字符数组来存放一个字符串。字符串总是以'\0'作为串的结束符。
		//因此当把一个字符串存入一个数组时，也把结束符 '\0'存入数组，并以此作为该字符串是否结束的标志。有了'\0'标志后，就不必再用字符数组的长度来判断字符串的长度了。
		j = i;
		while(s[j] != ' '&&s[j]) j++;
		for (k = i; k < (i + j) / 2; k++)
		{
			temp = s[k];
			s[k] = s[j-1+i-k];
			s[j-1+i-k] = temp;    
		}
		i = j;
	}
	cout<<s;
	return 0;
}
