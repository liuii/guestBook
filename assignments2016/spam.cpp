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
