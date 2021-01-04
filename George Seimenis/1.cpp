#include <iostream>
#include <stack>
#include <string>
#include <regex>

using namespace std;

//need this function to display the stack below.
void DisplayStack(stack<char> s)
{
	//display the stack with the current elements available in one line.
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}

int main()
{
	//initial message to be shown
	cout << "Exercise 1 in 'Metaglottistes.'" << endl;
	cout << "ADMISSIONS: Let q1, q2 be the states of the Deterministic Stack Automaton, where q1 is a non-final state and q2 is a final state." << endl;
	cout << "Let 'n' be a dummy element in the bottom of the stack." << endl;
	cout << "As soon as you type 'stop', the program will exit." << endl << endl;

	string input;

	//this do-while loop is going to run forever, unless the user types 'stop'.
	do
	{
		//get the input from the user.
		cout << "Input: ";
		cin >> input;

		//convert the input to lowercase.
		transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return tolower(c); });

		//if the message matches the wanted input (which has to be only x and y chars), we proceed to do what the exercise defines.
		if (regex_match(input, regex("[xy]+")))
		{
			//define the stack to be used, and the input length of the input (to use it in the for loop).
			stack<char> NAS_stack;
			int input_length = input.length();

			//push a dummy element into the stack. This will help us make various tests easier. Also, keep track of the accepted input state.
			NAS_stack.push('n');
			bool accepted_input = true;
			string error_output = "";
			string state = "q1";

			//for every character in the input
			for (int i = 0; i < input_length; i++)
			{
				//save the previous element and the current element to these variables.
				char stack_last_element = NAS_stack.top();
				char current_element = input.at(i);

				//if the current character is an 'x', it means that it can be pushed.
				if (current_element == 'x')
				{
					NAS_stack.push(current_element);
					state = "q1";
				}
				//otherwise, if it is a 'y', it means that we have to pop one character out from the stack.
				else
				{
					NAS_stack.pop();

					//if the stack is now empty, after popping the last element (which is always going to be 'n'), that's an error. Inform the user accoordingly.
					if (NAS_stack.empty())
					{
						error_output = "Cannot pop an element from an empty stack.";
						state = "q1";
						accepted_input = false;

						//display what has happened, before breaking out of the loop.
						string remaining_input = input.substr(i + 1, input_length - 1);
						cout << (i + 1) << ". Current State: " << state << ", Stack Items: (empty), Remaining Input: " << remaining_input << endl;
						break;
					}
					else if (NAS_stack.top() == 'n')
						state = "q2";
				}

				//after every loop, we create a substring of the input, representing the remainder of the elements to be tested.
				//we also use DisplayStack(), which outputs the stack after every loop.
				string remaining_input = input.substr(i + 1, input_length - 1);
				cout << (i + 1) << ". Current State: " << state << ", Stack Items: ";
				DisplayStack(NAS_stack);
				cout << ", Remaining Input: " << remaining_input << endl;
			}

			//if the errors are none of the above, we display this error, if the string is rejected, as it is the only possible case left.
			error_output = (error_output.compare("") == 0) ? "Stack is not empty." : error_output;

			//here is the final check. If the stack's top element is our dummy character, it means that the input is correct
			if (NAS_stack.size() == 1 && accepted_input)
				cout << endl << "String '" << input << "' is accepted." << endl << endl;
			//for any other state of the stack, the input is incorrect. If the top element happens to be something else than 'n', or if on the way here the accepted_input state was changed, the input is false.
			else
				cout << endl << "String '" << input << "' is NOT accepted." << endl << "Error message: " << error_output << endl << endl;
		}

		//if the user wants to stop the program, break out of the loop, then exit.
		else if (input.compare("stop") == 0)
		{
			break;
		}

		//if the input doesn't match any case above, there must be some mistake. Inform the user accoordingly.
		else
		{
			cout << "Incorrect Input. Only x or y characters are allowed." << endl << endl;
		}

	} while (true);

	//at this point, there's nothing else to be done. exit with code 0.
	cout << "Program stopped" << endl;
	return 0;
}