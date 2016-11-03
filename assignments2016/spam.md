# 垃圾邮件处理-贝叶斯理论的简单应用

有同学发来邮件询问为什么他的程序是错误的，程序如下：
``` c++
#include <iostream.h>
int P( int );
int main()
{	int P(int S), P(int H), P(int W/S), P(int W/H), P(int S/W);  
	/*	P(S)表示垃圾邮件概率。
	P(H)表示正常邮件概率。
	P(W/S)表示垃圾邮件中含有fapiao的概率。
	P(W/H)表示正常邮件中含有fapaio的概率。
	P(S/W)表示出现fapiao时邮件为垃圾邮件概率。*/
	cout<<"请分别输入 垃圾邮件概率，正常邮件概率，垃圾邮件中含有fapiao的概率，正常邮件中含有fapaio的概率。\n";
	cin>>P(S)>>P(H)>>P(W/S)>>P(W/H);
	P(S/W)=(P(W/S)*P(S))/(P(W/S)*P(S)+P(W/H)*P(H));
	cout<<"出现fapiao是邮件为垃圾邮件的概率为"<<P(S/W)<<"\n";
	return 0;

}
```
然后编译后提示有如下的错误：
```
D:\VC6SP6\MyProjects\概率\概率.cpp(4) : error C2143: syntax error : missing ',' before '/'
D:\VC6SP6\MyProjects\概率\概率.cpp(4) : error C2059: syntax error : '/'
D:\VC6SP6\MyProjects\概率\概率.cpp(4) : error C2143: syntax error : missing ',' before '/'
D:\VC6SP6\MyProjects\概率\概率.cpp(4) : error C2059: syntax error : '/'
D:\VC6SP6\MyProjects\概率\概率.cpp(4) : error C2143: syntax error : missing ',' before '/'
D:\VC6SP6\MyProjects\概率\概率.cpp(4) : error C2059: syntax error : '/'
D:\VC6SP6\MyProjects\概率\概率.cpp(11) : error C2065: 'S' : undeclared identifier
D:\VC6SP6\MyProjects\概率\概率.cpp(11) : error C2065: 'H' : undeclared identifier
D:\VC6SP6\MyProjects\概率\概率.cpp(11) : error C2065: 'W' : undeclared identifier
```
这样写程序当然会出错，在第二章中又一个非常重要的概念：`标识符`。所有的变量、常量、函数名都需要符合标识符的命名规则，这个书上有，不说了。  
  
这个程序当中出现的所有错误都是因为这个问题，因此我们就引出了如何命名的问题。由于变量的名字必须符合标识符的命名规则，因此是不能出现括号和空格的。  
  
但是再遵从规则的情况下，我们依然有更好的办法来表示SPAM事件的概率或者是P（W|S），例如：

| Probability | Function |
|----|----|
|P(S)|probabilityOfSpam|
|P(H)|probabilityOfHealthy|
|P(W\|S)|probabilityOfWordWhenSpam|
|P(W\|H)|probabilityOfWordWhenHealthy|

尽管这样看上去会给写程序带来更多的输入量，但是再有上下文提示的编辑器里面完全不是问题（不幸的是VC6.0并不具有这种编辑器）。