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
    srand(time(NULL));
    int v1 = (rand() % 3);
    for (int i = 0; i < str.length(); i++)
    {
        switch (v1)
        {
        case 0:
            if (str[i] == 'B')
            {
                str[i] = '+Y';
            }
        case 1:
            if (str[i] == 'B')
            {
                str[i] = '-Y';
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
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'Y')
        {
            str[i] = 'AB';
        }
    }
    return str;
}
bool checkCapitals(string str) {
    bool set = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'B' || str[i] == 'Y')
        {
            set = false;
        }
    }
    return set;
}

int main()
{
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

}
