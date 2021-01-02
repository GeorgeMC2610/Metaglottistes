#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;


string theEpsilon(string str) {
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'E')
        {
            str[i] = 'Y';
        }
    }
    return str;
}

string theAlpha(string str)
{
    cout << "We will replace the <A> according to the Rule <A> --> v| <E>" << endl;
    srand(time(NULL));
    int v1 = (rand() % 2);

    cout << v1 << endl;

    if (v1 == 0)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'A')
            {
                str[i] = 'v';
            }
        }
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'A')
            {
                str[i] = 'E';
            }
        }
    }

    return str;
}
string theBita(string str)
{
    string s1, s2;
    srand(time(NULL));
    int v1 = (rand() % 3);
    for (int i = 1; i < str.length(); i++)
    {

        switch (v1)
        {
        case 0:
            if (str[i] == 'B')
            {
                s1 = str.substr(0, i);
                s2 = str.substr(i + 1, str.length() - 1);
                str = s1 + "+" + "Y" + s2;
            }
        case 1:
            if (str[i] == 'B')
            {
                s1 = str.substr(0, i);
                s2 = str.substr(i + 1, str.length() - 1);
                str = s1 + "-" + "Y" + s2;
            }
        case 2:
            if (str[i] == 'B')
            {
                str[i] = 'E';
            }


        }
    }

    return str;
}
string theYpsilon(string str)
{
    string s1, s2;
    for (int i = 1; i < str.length(); i++)
    {

        if (str[i] == 'Y')
        {
            s1 = str.substr(0, i);
            s2 = str.substr(i + 1, str.length() - 1);
            str = s1 + "A" + "B" + s2;
        }
    }
    return str;
}
bool checkCapitals(string str) {
    bool set = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'B' || str[i] == 'Y')
        {
            set = 1;
        }
    }
    return set;
}

int main()
{
    int counter = 1;
    string str;
    bool set2;
    str = "E";
    cout << "<E> --> (<Y>)" << endl;
    str = "Y";
    cout << " The string is : " << str << endl;
    cout << "<Y> --> <A><B> " << endl;
    str = "AB";
    cout << "The string becomes : " << str << endl;
    for (int i = 1; i < 20; i++)
    {
        counter++;
        if (checkCapitals(str) == 0)
        {
            for (int y = 0; y < str.length(); y++)
            {
                switch (str[i])
                {

                case 'A':
                    str = theAlpha(str);
                    break;
                case 'B':
                    str = theBita(str);
                    break;
                case 'Y':
                    str = theYpsilon(str);
                    break;
                case 'E':
                    str = theEpsilon(str);
                    break;
                }



            }
        }
    }
    if (counter == 20 && checkCapitals(str) == 1)
    {
        for (int i = 0; i < str.length(); i++)
        {
            switch (str[i])
            {
            case 'E':
                cout << "According to grammae rules : <E> --> <Y> --> <A><B> : " << endl;
                str = str.substr(0, i - 1) + "Y" + str.substr(i + 1, str.length() - 1);
                cout << str << endl;
                str = str.substr(0, i - 1) + "v" + str.substr(i + 1, str.length() - 1);
            case 'Y':
                cout << "The rule for <Y> is :  <Y> --> <A><B>" << endl;
                str = str.substr(0, i - 1) + "v" + str.substr(i + 1, str.length() - 1);
                cout << str << endl;
            case 'A':
                cout << "The <A> --> v  to finalize the prossecion" << endl;
            case 'B':
                str = str.substr(0, i - 1) + str.substr(i + 1, str.length() - 1);
                cout << str << endl;


            }




        }
    }
    cout << str;

}
