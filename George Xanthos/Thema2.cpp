#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;




 int main() {
  string str = "AB";
  int counter =0;
  srand(time(NULL));
  int v1 = (rand() % 3);
  int v2 =(rand()% 2);
  cout << v1 << endl;
  cout << v2 << endl;
  do {
    for (int i =0 ;i<str.length();i++)
    {
      if (str[i]=='A')
      {
        if (v2 ==0)
        {
          str[i] = 'v';

        }else
        {
          str[i] = 'E';
        }
      }
      if (str[i] == 'B')
      {
        if (v1 == 0 )
        {
          string s1 = str.substr(0,i-1);
            string s2 = str.substr(i+1,str.length());
            str = s1 + "+" + "Y" + s2;
        }else if (v1 == 1)
        {
          string s1 = str.substr(0,i-1);
            string s2 = str.substr(i+1,str.length());
          str = s1 + "-" + "Y" +s2;

        }else
        {string s1 = str.substr(0,i-1);
          string s2 = str.substr(i+1,str.length());
          str = s1 +s2 ;

        }
        if (str[i] == 'Y')
        {string s1 = str.substr(0,i-1);
          string s2 = str.substr(i+1,str.length());
          str = s1 +"A"+ "B"+ s2;
        }
      }
    }
  counter ++;
  } while(counter<20);
cout << str ;
  return 0;
}
