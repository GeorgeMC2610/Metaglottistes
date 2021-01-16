# include <iostream>
# include <string>
# include <ctime>

using namespace std;

int  Random (int i)
{
    srand((unsigned) time(0));
    int result = 1 + (rand() % i);
    return result;
}
string replace (string s)
{
    string str = s;
    for (int i=0; i<s.length() ; i++)
    { 
        if (str[i]== 'A')
        {
            if (Random(2)==1)
            {
                str[i] = 'v';
                break;
            }
            else if (Random(2)==2)
            {
                str[i] = 'E';
                break;
            }
        } else if (str[i] == 'B')
        {
            if (Random(2) == 1)
            {
                str[i] = 'Y';
                break;
            } else if (Random(2) == 2)
            {
                str.erase(i);
                break;
            }
        }
        else if  (str[i] == 'E')
        {
            str [i] = 'Y';
            break;
        }
        
    }
    return str;
}

bool check (string s)
{
    for (int i=0; i< s.length() ; i++)
    {
        if (s[i]== 'E'|| s[i] == 'Y'|| s[i]=='A' || s[i]=='B')
        {
            return true;
        }
        else 
        {
            return false;
        }
        
    }
}

int main()
{
   
  string str;
  str = "AB";
 int counter = 0;
 while (check(str))
 {

     str = replace(str);
    counter ++;
    if (counter ==20)
    {
        break;
    }
 }
 cout << str << endl;
 


    return 0;

}
