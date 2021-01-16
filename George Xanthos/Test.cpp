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

	void ReplaceCharacters()
	{
		srand(time(NULL));
		//<E>:: = (<Y>)
		//<Y>:: = <A><B> *
		//<A>:: = v | <E>
		//<B>:: = -<Y> | +<Y> | e
		int random;
		int i = 0;
		while (i < this->Expression.length())
		{
			switch (this->Expression[i])
			{
			case 'E':
				this->Expression[i] = 'Y';
				break;
			case 'Y':
				this->Expression[i] = 'A';
				this->Expression.insert(i+1, "B");
				i--;
				break;
			case 'A':
				random = (rand() % 2);

				this->Expression[i] = (random == 0) ? 'n' : 'E';
				break;
			case 'B':
				random = (rand() % 3);

				if (random == 0)
				{
					this->Expression[i] = '+';
					this->Expression.insert(i + 1, "Y");
				}
				else if (random == 1)
				{
					this->Expression[i] = '-';
					this->Expression.insert(i + 1, "Y");
				}
				else
					this->Expression[i] = 'e';

				i--;
				break;
			}

			i++;
		}
	}
};

int main()
{
	Symbol testSymbol("", false);
	testSymbol.Expression = Symbol::GenerateExpression();
	cout << testSymbol.Expression << endl;

	testSymbol.ReplaceCharacters();
	cout << testSymbol.Expression << endl;
	

	//string s1 = "ABCDEF";
	//s1.insert(3, "09");
	//cout << s1 << endl;

	//s1.erase(2, 1);
	//cout << s1;

	//return 0;
}
