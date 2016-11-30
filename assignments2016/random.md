# 随机数的获得

在我们的大作业里面存在对生成随机数的需求，而且随机数的生成是一个在未来编程中无法避免要遇到的问题，尤其是在设计启发性算法的时候（例如我们第一次课介绍的遗传算法）。  

## 1. 如何取得一个随机数？  
通过使用`int rand(void)`函数可以取得随机数，例如我们要输出一个随机数，可以写成：  
``` c++
#include <iostream.h>
#include <stdlib.h>
void main() {
	int foobar = rand(); // foobar is a conventional
	cout << foobar << endl;
}
```
或者写成标准c++的风格：  
``` c++
#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
	int foobar = rand(); 
	cout << foobar << endl;
	return 0;
}
```
注意他们之间的区别，后面我们一律使用标准c++风格。然后我们就可以得到输出为：  
```
41
```
注意在不同的机器上运行可能会得到不同的结果，但是你会发现每次运行这个程序的输出都是一样的。  

## 2. 为什么每次取得的随机数都一样？
因为我们使用的`rand`函数是一个**伪**随机序列生成器。通过某种算法来产生一个序列，每次调用`rand`函数时从这个序列里面按顺序拿出一个数字。  
例如我们连续输出10个随机数：
``` c++
#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
	int foobar;
	for (int i = 0; i < 10; i ++) {
		foobar = rand();
		cout << foobar << ' ';
	}
	cout << endl;
	return 0;
}
```
得到的输出为：  
```
41 18467 6334 26500 19169 15724 11478 29358 26962 24464
```
再运行一次得到的输出和上次一样：  
```
41 18467 6334 26500 19169 15724 11478 29358 26962 24464
```
很难解释为什么要用**伪**随机数序列，但是解释为什么不用**真**随机序列生成器比较简单。通常真正的随机序列生成器需要一个小型的反应堆，通过测量半衰期就可以得到随机序列。但是对于今天普通的电脑来说，这个要求有点太高了。所以我们只好用**伪**随机序列发生器了。  

## 3. 每次生成的随机序列都一样，有什么用？
其实`rand`还是能够生成不同的随机序列的，但是需要提供一个不同的种子。所谓的种子就是一个整数，用来表示随机数生成器的输入参数。  

用来设置随机序列种子的函数是`void srand(usigned int)`，为其设置不同的值就可以得到不同的随机序列。例如下面的程序：  
``` c++
#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
	int foobar, i;
	srand(1); // seed is set to 1
	cout << "==================== Seed 1 ====================" << endl;
	for (i = 0; i < 10; i ++) {
		foobar = rand();
		cout << foobar << ' ';
	}
	cout << endl;

	srand(2); // seed is set to 2
	cout << "==================== Seed 2 ====================" << endl;
	for (i = 0; i < 10; i ++) {
		foobar = rand();
		cout << foobar << ' ';
	}
	cout << endl;
	return 0;
}
```
那么我们就可以发现两个不同的种子，产生的随机序列是不一样的。  
```
==================== Seed 1 ====================
41 18467 6334 26500 19169 15724 11478 29358 26962 24464
==================== Seed 2 ====================
45 29216 24198 17795 29484 19650 14590 26431 10705 18316
```

## 4. 可是我该如何产生一个随机的种子呢？
我们需要引入外部的随机因素来作为随机数的种子。  
对于移动设备可采取的外部随机因素很大，例如用GPS获得的经纬度、用陀螺仪取得手机的位姿、当前可以探测到的Wifi热点的数量、以及所有Wifi热点强度的和等等，当然这些方法又慢又耗电，所以基本上没人用。而对于台式设备，由于缺乏丰富的传感器，所以前面提到的大部分方法都用不了。  

但是，依然有个外部因素是可以容易利用的，那就是**时间**。我们可以用用户执行程序的时间作为随机数的种子：  
``` c++
srand((unsigned int)time(NULL));
```
`(unsigned int)`是指将`time`函数的结果强制转换为**无符号整型**，`NULL`是**空指针**（需要阅读第四章先理解指针的概念才能明白，现在先直接这样用）。
因此前面的程序就可以改为：  
``` c++
#include <iostream>
#include <cstdlib>
#include <ctime> // 1. the filename is time.h
using namespace std;
int main() {
	int foobar, i;
	srand((unsigned int)time(NULL)); // 2. time as seed
	for (i = 0; i < 10; i ++) {
		foobar = rand();
		cout << foobar << ' ';
	}
	cout << endl;
	return 0;
}
```
这回每次执行就可以得到不同的结果了，但是注意`time`函数的时间颗粒度是1秒钟，所以两次运行的间隔一定要大于1秒钟。  
+1s : )  

## 5. 如何取得某个范围的数字，例如22-48之间？
`rand`函数取得的随机数范围为`0`到`RAND_MAX(32767)`，想要缩小随机数的区间，最简单的方法就是求余：  
``` c++
rand() % 100
```
这条语句可以获得0到99之间的随机数（包括0和99）。  
所以想要22-48之间的随机数，通过简单的计算可以得到`22-48之间的随机数`等于`22加上一个0-26之间的随机数`。写成数学表达式就是：  
``` c++
22 + rand() % 27
```
我们修改前面的程序为：  
``` c++
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	int foobar, i;
	srand((unsigned int)time(NULL));
	for (i = 0; i < 10; i ++) {
		foobar = 22 + rand() % 27; // modified
		cout << foobar << ' ';
	}
	cout << endl;
	return 0;
}
```
这样就可以得到一组22-48之间的随机数了。

## 6. 还有要补充的吗？
注意`rand`函数产生的随机数是均匀分布的，但是如果我们想要的随机数不是均匀分布的，例如我们要随机产生一组学生的成绩。  

我们知道学生成绩是符合正态分布的，也叫做高斯分布。简单的说就是靠近平均分的人数多，高分和低分的人数少。这就需要等你们学完《概率论与数理统计》才能解决这个问题了。  

而且，我们仅仅是简单介绍如何产生一个均匀分布的随机数，但是我们并没有介绍到底这个伪随机序列是如何生成的。`rand`函数用的是线性同余，当然还有很多生成方法，这方面的内容网上可以搜到很多，关键词是：`伪随机数生成算法`。  

我个人推荐这一篇短文：[`Pseudo-random number generator`](https://en.wikipedia.org/wiki/Pseudorandom_number_generator)。  