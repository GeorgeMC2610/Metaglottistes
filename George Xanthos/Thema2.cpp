#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;




 int main() {
  string str = "<A><B>";
  string s1,s2;
 // int counter =0;
   int i=0;
  srand(time(NULL));
  int v1 = (rand() % 3);
  int v2 =(rand()% 2);
  cout << v1 << endl;
  cout << v2 << endl;
 
 for (int i=0; i<20; i++)
 {
    if (str[i]=='E')
   {
     s1 = str.substr(0,i);
     s2 = str.substr(i+1,str.length());
    str = s1 + "<" + "(" + "Y" + ")" + ">" + s2;
    continue;
   }
   if (str[i]=='A' && v2 ==0)
   {
     str[i] = 'v';
     continue;
   }
     if (str[i]=='A' && v2 ==1)
   {
     s1 = str.substr(0,i);
     s2 = str.substr(i+1,str.length());
     str = s1 + "<" + "E" + ">" + s2;
     continue;
   }
     if (str[i]=='B' && v1 == 0 )
   {
     s1 = str.substr(0,i);
      s2 = str.substr(i+1,str.length());
     str = s1 +"+" +"<" + "Y" +">"+ s2;
      continue;
     
   }
    if ( str[i]=='B' && v1 ==1 )
   {
      s1 = str.substr(0,i);
      s2 = str.substr(i+1 , str.length());
     str = s1 + "-" +"<"+ "Y" +">"+ s2 ;
      continue;
     
   }
    if (str[i]=='B' && v1 ==2)
   {
      s1 = str.substr(0,i);
      s2 = str.substr(i+1,str.length());
     str = s1 + s2 ;
      continue;
     
   }
    if (str[i]=='Y')
   {
      s1 = str.substr(0,i);
      s2 = str.substr(i+1,str.length());
     str = s1 + "A" + "B" + s2;
      continue;
     
   }
 }
 
  
   


 
 
 
cout << str ;
  return 0;
}
