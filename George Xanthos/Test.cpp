#include <iostream>
#include <string>
#include <ctime>
#include <regex>

using namespace std;

class Symbol
{
public:
	bool Final;
	string Expression;

	Symbol(string Expression, bool Final)
	{
		this->Final = Final;
		this->Expression = Expression;
	}

	static string GenerateExpression()
	{
		string str = "";
		srand(time(NULL));

		//to megethos tou string
		int stringLength = 4 + (rand() % 4);

		for (int i = 0; i < stringLength; i++)
		{
			int random = (rand() % 4);

			switch (random)
			{
			case 0:
				str += "E";
				break;
			case 1:
				str += "Y";
				break;
			case 2:
				str += "A";
				break;
			case 3:
				str += "B";
				break;
			}
		}

		return str;
	}
	bool Checker(string s)
	{
		//return regex_match(s,regex("[+-ne]+"));
		string s2 = "";
		for (int i = 0; i < s.length(); i++)
		{
			s2 = s[i];
			if (!regex_match(s2, regex("[+-ne]")))
			{
				return false;
			}
		}
		return true;

	}

	void ReplaceCharacters()
	{
		//srand(time(NULL));
		int random;
		//int i = 0;
		int j = 0;
		for (int i = 0; i < 20; i++) {
			j = 0;
			if (!Checker(Expression))
			{
				break;
			}
			while (Expression[j] == 'n' || Expression[j] == '-' || Expression[j] == '+' || Expression[j] == 'e')
			{
				j++;
			}
			switch (this->Expression[j])
			{
			case 'E':
				this->Expression[j] = 'Y';
				break;
			case 'Y':
				this->Expression[j] = 'A';
				this->Expression.insert(j + 1, "B");
				j++;
				//i--;
				break;
			case 'A':
				random = (rand() % 2);

				this->Expression[j] = (random == 0) ? 'n' : 'E';
				break;
			case 'B':
				random = (rand() % 3);

				if (random == 0)
				{
					this->Expression[j] = '+';
					this->Expression.insert(j + 1, "Y");
					j++;
				}
				else if (random == 1)
				{
					this->Expression[j] = '-';
					this->Expression.insert(j + 1, "Y");
					j++;
				}
				else
					this->Expression[j] = 'e';

				//i--;
				break;
			}

			//i++;
			cout << Expression << endl;



		}
	}
};

int main()
{
	srand(time(NULL));
	Symbol testSymbol("E", false);

	cout << testSymbol.Expression << endl;

	testSymbol.ReplaceCharacters();

	cout << testSymbol.Expression << endl;




}