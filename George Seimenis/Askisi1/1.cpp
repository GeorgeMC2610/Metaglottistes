#include <iostream>
#include <stack>
#include <string>
#include <regex>

using namespace std;

int main()
{
	//stack NAS;

	cout << "Exercise 1 in 'Metaglottistes.'" << endl;
	cout << "As soon as you type 'stop', the program will exit." << endl << endl;
	string input;

	do 
	{
		cout << "Input: ";
		cin >> input;

		//this means "convert to lowercase"
		transform(input.begin(), input.end(), input.begin(), [](unsigned char c){ return tolower(c); });

		if (regex_match(input, regex("[xy]+")))
		{
			cout << "Correct" << endl;
		}
		else if (input.compare("stop") == 0)
		{
			break;
		}	
		else
		{
			cout << "Incorrect Input. Only x or y characters are allowed." << endl;
		}
			
	} while(true);
	
	cout << "Program stopped" << endl;


	return 0;
}