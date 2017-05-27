#include <IOSTREAM>
using namespace std;

struct StatisticUnit {
	char ch;
	int count;
};


int main() {
	StatisticUnit su[26];
	for(int i=0; i < 26; i++){
		su[i].ch = char('a' + i);
		su[i].count = 0;
	}

	char str[1000];
	cin.getline(str, 1000);

	for(i = 0; str[i] != '\0'; i++){
		char tmp = str[i];
		tmp = (tmp>='A' && tmp<= 'Z') ? tmp + 32: tmp;
		if (tmp>='a' && tmp<= 'z') {
			su[str[i]-'a'].count ++;
		}
	}

	for(i = 0; i < 25; i ++){
		for(int j = 0; j < 25 - i; j++){
			if (su[j].count < su[j+1].count){
				StatisticUnit t;
				t = su[j];
				su[j] = su[j+1];
				su[j+1] = t;
			}
		}
	}
	return 0;
}