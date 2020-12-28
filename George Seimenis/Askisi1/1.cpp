#include <iostream>
#include <stack>
#include <string>
#include <regex>
#include <typeinfo>

using namespace std;

int main()
{
	//initial message to be shown
	cout << "Exercise 1 in 'Metaglottistes.'" << endl;
	cout << "As soon as you type 'stop', the program will exit." << endl << endl;

	string input;

	//this do-while loop is going to run forever, unless the user types 'stop'.
	do 
	{
		//get the input from the user.
		cout << "Input: ";
		cin >> input;

		//convert the input to lowercase.
		transform(input.begin(), input.end(), input.begin(), [](unsigned char c){ return tolower(c); });

		//if the message matches the wanted input (which has to be only x and y chars), we proceed to do what the exercise defines.
		if (regex_match(input, regex("[xy]+")))
		{
			//define the stack to be used, and the input length of the input (to use it in the for loop).
			stack<char> NAS_stack;
			int input_length = input.length();


		}
		//if the user wants to stop the program, break out of the loop, then exit.
		else if (input.compare("stop") == 0)
		{
			break;
		}	
		//if the input doesn't match any case above, there must be some mistake. Inform the user accoordingly.
		else
		{
			cout << "Incorrect Input. Only x or y characters are allowed." << endl;
		}
			
	} while(true);
	
	//at this point, there's nothing else to be done. exit with code 0.
	cout << "Program stopped" << endl;
	return 0;
}