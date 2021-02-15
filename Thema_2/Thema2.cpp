#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Symbol
{
public:

	string Expression;

	Symbol(string Expression)
	{

		this->Expression = Expression;
	}


	bool Checker(string s)
	{
		/*The checker function scans from the left to the right to find the most left non-final symbol.*/
		for (int i = 0; i < s.length(); i++)
		{

			if (s[i] == '<')
			{
				return true; //return true if it finds it
			}
		}
		return false; //and false otherwise

	}

	void ReplaceCharacters()
	{ /*This function replace the most left non-terminal symbol in our string with another final or
	  non-final symbol/s according to the grammaticall rules we were given, if checker function
	  has returned true*/
		int random;
		int j;
		for (int i = 0; i < 50; i++) {
			j = 0;
			if (!Checker(Expression))
			{
				break;
				/*
				* if the checker returns false it means we have only terminal symbols, so we break.
				* Else we transfer to the next most left position with a non-final symbol
				*/
			}

			while (Expression[j] != '<')
			{
				j++;
			}

			switch (Expression[j + 1]) //Depending on the non-terminal symbol, we choose the corresponding grammatical rule
			{
			case 'E':
				cout << "According to the grammatical rule :  <E> ::= (<Y>) " << endl;
				cout << "The <E> is replaced by (<Y>)" << endl;
				Expression[j] = '(';
				Expression[j + 1] = '<';
				Expression[j + 2] = 'Y';
				Expression.insert(j + 3, ">)");
				break;
			case 'Y':
				cout << "According to the grammatical rule :  <Y> ::= <A><B> " << endl;
				cout << "The <Y> is replaced by <A><B>" << endl;
				Expression[j + 1] = 'A';
				Expression.insert(j + 3, "<B>");
				j++;
				break;
			case 'A':
				cout << "According to the grammatical rule :  <A> ::= v | <E> " << endl;
				random = (rand() % 2);
				if (random == 0) {
					Expression[j] = 'v';
					Expression.erase(j + 1, 2);
					cout << "The <A> is replaced by v" << endl;
				}
				else {
					Expression[j + 1] = 'E';
					cout << "THE <A> is replaced by <E>" << endl;
				}
				break;
			case 'B':
				cout << "According to the grammatical rule :  <B> ::= -<Y> | +<Y> | empty space   " << endl;
				random = (rand() % 3);
				if (random == 0)
				{
					Expression[j] = '+';
					Expression[j + 1] = '<';
					Expression[j + 2] = 'Y';
					Expression.insert(j + 3, ">");
					j++;
					cout << "The <B> is replaced by  +<Y>  " << endl;
				}
				else if (random == 1)
				{
					Expression[j] = '-';
					Expression[j + 1] = '<';
					Expression[j + 2] = 'Y';
					Expression.insert(j + 3, ">");
					j++;
					cout << "The <B> is replaced by  -<Y>  " << endl;

				}
				/*
				* According to the grammatical rules  we have  <A> --> v|<E>
				* and <B> --> -<Y>|+<Y>| empty space
				* so in this case we should choose one symbol by chance ,
				* in this case we use the rand() function in order to choose a symbol
				* for the <A> and <B>
				*
				*/
				else {
					Expression.erase(j, 3);
					cout << "The <B> is replaced  by empty space " << endl;
				}
				break;
			}
			cout << Expression << endl;
			cout << endl;
			/*
			We give 50 steps for the replace to make a string that contains only final symbols. If this doesn't happen
			it will leave the non-final symbols as they are
			*/
		}
	}
};

int main()
{
	srand(time(NULL)); // Giving the time of the cpu as a seed to our rand () function
	Symbol testSymbol("<E>"); // We begin with <E> according to our rules so the Symbol() constructor takes <E> as an overload
	testSymbol.ReplaceCharacters();
	system("pause");
	return 0;

}
