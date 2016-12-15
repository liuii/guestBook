# 《计算思维》练习作业

## 程序基本结构

### 1. 输入矩形的两个边a、b，求面积S和周长L。（顺序结构）  
``` c++
#include <iostream>
using namespace std;
int main() {
	double a, b;
	double s, l;
	cout << "Please input the length of the width and height: ";
	cin >> a >> b;

	l = 2 * (a + b);
	s = a * b;

	cout << "s=" << s << endl;
	cout << "l=" << l << endl;
	return 0;
}
```

2. 有分段函数：x>=0时y为x+1，x<0时，y为2x-3。输入x值，输出y值。（选择结构）  
``` c++
#include <iostream>
using namespace std;
int main() {
	double x, y;
	cout << "x= ";
	cin >> x;

	if (x >= 0)
		y = x + 1;
	else
		y = 2 * x - 3;

	cout << "y=" << y << endl;
	return 0;
}
```

3. 求1+3+5+…+99。（循环结构）  
``` c++
#include <iostream>
using namespace std;
int main() {
	double s = 0; // NOTICE: 做累加或累积，一定要设置累加变量初值为0。
	
	for (int i = 1; i <= 99; i += 2)
		s += i;

	cout << "s=" << s << endl;
	return 0;
}
```

4. 输入直角三角形的两个直角边a、b，求斜边c和面积s。（顺序结构）  
``` c++
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double a, b;
	double c, s;
	cout << "Please input the a and b: ";
	cin >> a >> b;

	c = sqrt(a * a + b * b);
	s = 0.5 * a * b;

	cout << "c=" << c << endl;
	cout << "s=" << s << endl;
	return 0;
}
```

5. 输入一个成绩，若成绩≥60，输出“通过”，否则输出“未通过”。（选择结构）  
``` c++
#include <iostream>
using namespace std;
int main() {
	int score;
	cout << "Please input the score: ";
	cin >> score;

	if (score >= 60)
		cout << "通过" << endl;
	else
		cout << "未通过" << endl;
	return 0;	
}
```

6. 求1+1/5+1/9+…+1/97（循环结构）  
``` c++
#include <iostream>
using namespace std;
int main() {
	double s = 0;

	for (int i = 1; i <= 97; i += 4)
		s += 1.0 / i;	// NOTICE: 如果你不用1.0，这个程序最后的结果就是0了。

	cout << "s=" << s << endl;
	return 0;	
}
```

7. 已知磅与公斤的换算关系为：1磅=0.454公斤。输入任意的磅值，输出对应的公斤数值。  
``` c++
#include <iostream>
using namespace std;
int main() {
	double lb, kg;
	cout << "lb=";
	cin >> lb;

	kg = lb * 0.454;

	cout << kg << "kg" << endl;
	return 0;	
}
```

8. 空气质量指标在100以下是为好天气，超过100则有空气污染。输入一个空气质量值，若指标≤100，输出“空气质量好”，否则输出“有污染”。  
``` c++
#include <iostream>
using namespace std;
int main() {
	double moist;
	cout << "Moist meter is:";
	cin >> moist;

	if (moist >= 100)
		cout << "有污染" << endl;
	else
		cout << "空气质量好" << endl;
	return 0;	
}
```

9. 求2+4+6+…+100  
``` c++
#include <iostream>
using namespace std;
int main() {
	int s = 0;	// NOTICE: 累加变量的初值一定要设置

	for (int i = 2; i <= 100; i += 2)
		s += i;

	cout << "s=" << s << endl;
	return 0;	
}
```

## 简单程序编程

1. 输入一个4位数，求各位数字之和（如输入1234，输出10）。  
``` c++
#include <iostream>
using namespace std;
int main() {
	int n;
	cout << "Please input the number: ";
	cin >> n;

	int a, b, c, d;	// We assumed the number is : abcd
	d = n % 10;
	c = n / 10 % 10;
	b = n / 100 % 10;
	a = n / 1000;

	int s = a + b + c + d;

	cout << "s=" << s << endl;
	
	return 0;	
}
```

2. 输入3个数a、b、c，按由小到大的顺序输出。  
``` c++
#include <iostream>
using namespace std;
int main() {
	int a, b, c, t; // NOTICE: t是一个临时变量
	cout << "Please input three numbers: ";
	cin >> a >> b >> c;

	if (a > b){
		t = a;
		a = b;
		b = t;
	}

	if (b > c){
		t = b;
		b = c;
		c = t;
	}

	if (a > b){
		t = a;
		a = b;
		b = t;
	}
	
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;	
	return 0;	
}
```

3. 统计100到200之间能被13整除的数。  
``` c++
#include <iostream>
using namespace std;
int main() {
	int count = 0;	// NOTICE: 计数变量需要初始化为0

	for(int i = 100; i <= 200; i ++)
		if (i % 13 == 0)
			count ++;

	cout << "count=" << count << endl;
	return 0;	
}
```

4. 输入10个数，求和及平均值。  
``` c++
#include <iostream>
using namespace std;
int main() {
	double sum = 0, average;
	double a;

	for(int i = 1; i <= 10; i ++){
		cin >> a;
		sum += a;
	}
	average = sum / 10;

	cout << "sum=" << sum << endl;
	cout << "averag=" << average << endl;
	return 0;	
}
```

5. 输入一个4位数，将其反向输出。（如输入1234，输出4321）  
``` c++
#include <iostream>
using namespace std;
int main() {
	// Another method
	int n;
	cout << "n:";
	cin >> n;

	while(n > 0){
		cout << n % 10;
		n = n / 10;
	}

	cout << endl;
	return 0;	
}
```
6. 输入百分制分数，输出对应的五级分制分数。  
``` c++
#include <iostream>
using namespace std;
int main() {
	int score;
	cout << "score: ";
	cin >> score;

	if (score >= 90)
		cout << 'A' << endl;
	else if (score >= 80)
		cout << 'B' << endl;
	else if (score >= 70)
		cout << 'C' << endl;
	else if (score >= 6`0)
		cout << 'D' << endl;
	else
		cout << 'E' << endl;
	return 0;	
}
```

7. 统计所有四位数中，四位数字之和为32的数。  
``` c++
#include <iostream>
using namespace std;
int main() {
	int count = 0;

	for(int i = 1000; i <= 9999; i++){
		int a, b, c, d;
		d = i % 10;
		c = i / 10 % 10;
		b = i / 100 % 10;
		a = i / 1000;
		if (a + b + c + d == 32)
			count ++;
	}

	cout << "count=" << count << endl;
	return 0;	
}
```

8. 输入10个数，求最大值和最小值。  
``` c++
#include <iostream>
using namespace std;
int main() {
	int min, max;

	int x;
	cout << "Please input a number:";
	cin >> x;

	max = x;
	min = x;

	for(int i = 1; i <= 9; i ++){
		cout << "Please input a number:";
		cin >> x;

		if (x < min)
			min = x;

		if (x > max)
			max = x;
	}

	cout << "min=" << min << endl;
	cout << "max=" << max << endl;
	return 0;	
}
```

9.请输入一个6位数字表示的日期，输出对应的年、月、日（例如输入161125，输出16，11，25）。  
``` c++
#include <iostream>
using namespace std;
int main() {
	int date, year, month, day;
	cout << "Please input the date: ";
	cin >> date;

	year	= date / 10000;
	month	= date / 100 % 100;
	day		= date % 100;

	cout << year << ", " << month << ", " << day << endl;
	return 0;	
}
```

10. 某单位工资标准为：若工作时间≤8小时，则按50元/小时付薪酬，若超过8小时，8小时内部分按原标准，超出8小时部分按70元/小时付薪酬。请输入小时数，计算相应应付工资并输出。  
``` c++
#include <iostream>
using namespace std;
int main() {
	int hours, salary;
	cout << "hours=";
	cin >> hours;

	if (hours <= 8)
		salary = hours * 50;
	else
		salary = hours * 70 - 160;

	cout << "salary=" << salary << endl;
	return 0;	
}
```

11. 求1-1/3+1/5-1/7+…+1/99。  
``` c++
#include <iostream>
using namespace std;
int main() {
	double s = 0;
	double sign = 1;

	for(int i = 1; i <= 99; i += 2){
		s = s + sign / i;
		sign = -sign;
	}

	cout << "s=" << s << endl;
	return 0;	
}
```

12. 输入10个数，统计其中的偶数个数，并输出。  
``` c++
#include <iostream>
using namespace std;
int main() {
	int count = 0;

	for(int i = 1; i <= 10; i ++){
		int x;
		cout << "Please input a number: ";
		cin >> x;

		if (x % 2 == 0)
			count ++;
	}

	cout << "count=" << count << endl;
	return 0;	
}
```

## 简单程序编程

1. 输入若干分数，求总分和平均分，求最高分和最低分。  
``` c++
#include <iostream>
using namespace std;
int main() {
	int n;
	cout << "Please tell me the total of the numbers: ";
	cin >> n;

	double sum = 0;
	double max, min, average;
	
	double x;
	cout << "Please input a number: ";
	cin >> x;

	sum = x;
	max = x;
	min = x;

	for(int i = 1; i <= n - 1; i ++){
		cout << "Please input a number: ";
		cin >> x;

		sum += x;

		if (x < min)
			min = x;

		if (x > max)
			max = x;

	}

	average = sum / n;

	cout << "sum=" << sum << endl;
	cout << "average=" << average << endl;
	cout << "max=" << max << endl;
	cout << "min=" << min << endl;
	return 0;	
}
```

2. 输入若干分数，求总分和平均分，并统计各分数段的人数。  
``` c++
#include <iostream>
using namespace std;
int main() {
	int n;
	cout << "Please tell me the total of the numbers: ";
	cin >> n;

	double sum = 0;
	double average;

	int countOfGradeA = 0;
	int countOfGradeB = 0;
	int countOfGradeC = 0;
	int countOfGradeD = 0;
	int countOfGradeE = 0;
	
	double x;
	
	for(int i = 1; i <= n; i ++){
		cout << "Please input a number: ";
		cin >> x;

		sum += x;

		if (x >= 90)
			countOfGradeA ++;
		else if (x >= 80)
			countOfGradeB ++;
		else if (x >= 70)
			countOfGradeB ++;
		else if (x >= 60)
			countOfGradeB ++;
		else
			countOfGradeE ++;
	}

	average = sum / n;

	cout << "sum=" << sum << endl;
	cout << "average=" << average << endl;
	cout << "countOfGradeA=" << countOfGradeA << endl;
	cout << "countOfGradeB=" << countOfGradeB << endl;
	cout << "countOfGradeC=" << countOfGradeC << endl;
	cout << "countOfGradeD=" << countOfGradeD << endl;
	cout << "countOfGradeE=" << countOfGradeE << endl;
	return 0;	
}
```

3. 某选秀比赛，有10个评委给选手打分。评分规则为去掉最高分和最低分之后的平均分为选手的分数。编程实现该功能。  
``` c++
#include <iostream>
using namespace std;
int main() {
	double sum = 0;
	double max, min, finalScore;
	
	double x;
	cout << "Please input a score: ";
	cin >> x;

	sum = x;
	max = x;
	min = x;

	for(int i = 1; i <= 9; i ++){
		cout << "Please input a score: ";
		cin >> x;

		sum += x;

		if (x < min)
			min = x;

		if (x > max)
			max = x;

	}

	finalScore = (sum - max - min) / 8;

	cout << "The final score is" << finalScore << endl;
	return 0;	
}
```
