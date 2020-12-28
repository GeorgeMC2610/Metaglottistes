#include <iostream>
#include <stack>
#include <string>
#include <regex>

using namespace std;

int main()
{
	//stack NAS;
	string input;

	cout << "Input: ";
	cin >> input;

	if (regex_match(input, regex("[xy]+")))
		cout << "Correct";
	else
		cout << "Nope";

	return 0;
}