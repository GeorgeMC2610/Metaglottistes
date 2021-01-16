#include <iostream>
#include <string>
#include <ctime>

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

	/*	static string GenerateExpression()
		{
			string str = "";
			//srand(time(NULL));

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
		}*/
	bool Checker(string s)
	{
		//return regex_match(s,regex("[+-ne]+"));
		//string s2 = "";
		for (int i = 0; i < s.length(); i++)
		{
			//s2 = s[i];
			if (s[i] == '<')
			{
				return true; //true ama vrei ena mh termatiko
			}
		}
		return false; //false ama einai ola termatika

	}

	void ReplaceCharacters()
	{
		//srand(time(NULL));
		int random;
		//int i = 0;
		int j = 0;
		for (int i = 0; i < 50; i++) {
			j = 0;
			if (!Checker(Expression))
			{
				break;
			}
			while (Expression[j] != '<')
			{
				j++;
			}
			switch (this->Expression[j + 1])
			{
			case 'E':
				this->Expression[j] = '(';
				this->Expression[j + 1] = '<';
				this->Expression[j + 2] = 'Y';
				this->Expression.insert(j + 3, ">)");
				break;
			case 'Y':
				this->Expression[j + 1] = 'A';
				this->Expression.insert(j + 3, "<B>");
				j++;
				//i--;
				break;
			case 'A':
				random = (rand() % 2);

				//this->Expression[j] = (random == 0) ? 'n' : 'E';

				if (random == 0) {
					this->Expression[j] = 'n';
					this->Expression.erase(j + 1, 2);
				}
				else {
					this->Expression[j + 1] = 'E';
				}
				break;
			case 'B':
				random = (rand() % 3);

				if (random == 0)
				{
					this->Expression[j] = '+';
					this->Expression[j + 1] = '<';
					this->Expression[j + 2] = 'Y';
					this->Expression.insert(j + 3, ">");
					j++;
				}
				else if (random == 1)
				{
					this->Expression[j] = '-';
					this->Expression[j + 1] = '<';
					this->Expression[j + 2] = 'Y';
					this->Expression.insert(j + 3, ">");
					j++;
				}
				else {
					this->Expression.erase(j, 3);
				}

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
	Symbol testSymbol("<E>", false);
	string s = "abcfdbfhtrhrthbrdev";
	s.erase(2, 1);
	cout << s << endl;

	cout << testSymbol.Expression << endl;

	testSymbol.ReplaceCharacters();

	//cout << testSymbol.Expression << endl;
}
