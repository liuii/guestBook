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
这样写程序当然会出错，在第二章中有一个非常重要的概念：`标识符`。所有的变量、常量、函数名都需要符合标识符的命名规则，这个书上有，不说了。  
  
这个程序当中出现的所有错误都是因为这个问题，因此我们就引出了如何命名的问题。由于变量的名字必须符合标识符的命名规则，因此是不能出现括号和空格的。  
  
但是在遵从规则的情况下，我们依然有更好的办法来表示SPAM事件的概率或者是P（W|S），例如：  

| Probability | VariableName |
|----|----|
|P(S)|probabilityOfSpam|
|P(H)|probabilityOfHealthy|
|P(W\|S)|probabilityOfWordWhenSpam|
|P(W\|H)|probabilityOfWordWhenHealthy|

尽管这样看上去会给写程序带来更多的输入量，但是再有上下文提示的编辑器里面完全不是问题（不幸的是VC6.0并不具有这种编辑器）。  

下面我们来看看使用了这种命名风格的程序如何书写：  
``` c++
#include <iostream>
using namespace std;
int main() {
	// define the variables need user input
	double probabilityOfSpam;
	double probabilityOfHealthy;
	double probabilityOfWordWhenSpam;
	double probabilityOfWordWhenHealthy;
	// define the result variables
	double probabilityOfSpamWhenWord;
	
	// output the text and input the probability
	cout << "Please input the probability of spam (e.g. 0.5): ";
	cin >> probabilityOfSpam;
	cout << "Please input the probability of Healthy (e.g. 0.5): ";
	cin >> probabilityOfHealthy;
	cout << "Please input the probability of keyword in spam (e.g. 0.05): ";
	cin >> probabilityOfWordWhenSpam;
	cout << "Please input the probability of keyword in healthy (e.g. 0.0005): ";
	cin >> probabilityOfWordWhenHealthy;

	// caculate the result
	// notice that the statement can be break, but the tokens cannot be break
	probabilityOfSpamWhenWord = (probabilityOfWordWhenSpam * probabilityOfSpam) / 
								(probabilityOfWordWhenSpam * probabilityOfSpam +
								probabilityOfWordWhenHealthy * probabilityOfHealthy);

	// output the result
	cout << "The probability of spam when keyword found is "
		 << probabilityOfSpamWhenWord
		 << endl;

	// success
	return 0;
}
```
当然我上课解释过，之所以用如此长的变量名，是为了提高可读性，但是你用VC6写程序就会苦不堪言。当然在写这份文档的时候，我并不在乎，因为我在用`sublime text`编辑代码。:)  

另外，在开始写程序的时候，关注的是程序结构的设计，而非真正的工程应用，所以开始学的时候变量名可以用的简单些。例如使用下面的变量名：  

| Probability | VariableName |
|----|----|
|P(S)|a|
|P(H)|b|
|P(W\|S)|c|
|P(W\|H)|d|

所以上面的程序就变成了：

``` c++
#include <iostream>
using namespace std;
int main() {
	// define the variables need user input
	double a, b, c, d;
	// define the result variables
	double r;
	
	// output the text and input the probability
	cout << "Please input the probability of spam (e.g. 0.5): ";
	cin >> a;
	cout << "Please input the probability of Healthy (e.g. 0.5): ";
	cin >> b;
	cout << "Please input the probability of keyword in spam (e.g. 0.05): ";
	cin >> c;
	cout << "Please input the probability of keyword in healthy (e.g. 0.0005): ";
	cin >> d;

	// caculate the result
	// notice that the statement can be break, but the tokens cannot be break
	r = (c * a) / (c * a + d * b);

	// output the result
	cout << "The probability of spam when keyword found is " << r << endl;

	// success
	return 0;
}
```

所以在学习编程的早期，对于短小的程序直接使用abc就可以，毕竟可以提高编写的效率而不会降低可读性。但是，如果程序比较大的话，那么变量的命名必须具有自明性，因此前面的命名方法（骆驼命名法）就极为有用了，这也是行业内的书写代码的规则。  

对于函数的问题，因为这个学期我们还无法讨论这一话题，但是下学期会讨论。至于面对真的邮件如何去计算这四个概率，概念上讲非常简单，但是实现起来有很多的难点：  

1、需要对邮件文本进行分词，通常会使用一些分词的API来完成，如果独立完成的话可以作为研究生期间的课题。  
2、文本搜索的算法设计，为了提高效率，要对搜索算法进行深入的研究，作为研究生期间的课题完全没有问题。  
3、利用贝叶斯分布来解决判定的问题，这是【计算机学科】下的【机器学习】领域中的一个子领域【统计学习】的范畴。  
4、也许你会希望利用其他【机器学习】的方法来解决邮件断定的问题。  

因此，对于垃圾邮件推断系统，我们只能初窥门径，深入做的话恐怕就需要转专业了，但是其原理如此简明，如果用abc这样的变量，核心的语句只有一条：  
``` c++
p = ( a * b ) / ( a * b + c * d )
```
如此简明有力，这也是我选择这个例子来介绍顺序结构的原因。  

写在最后的话：  
**我并不喜欢在《计算思维》的课堂上客串《概率论与数理统计》的老师，所以后面的课基本上都不会去客串了，当然只是“基本”。**