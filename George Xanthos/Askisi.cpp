#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[]) {
  bool start = true;
string answer ;
string str;
string choice;


cout << "The rules of our grammar are :" << endl;
cout << "E --> Y" << endl;
cout << "Y --> AB" << endl;
cout << "A -->  n or  <E> " << endl;
cout << "B--> -Y or +Y or empty" << endl;

while (start) {
  cout << "Do you want to start ???" << endl;
  cin >> answer;
  if (answer.compare("Yes")==0) {
    start = true;
  } else {
    start = false;
  }
  if (start) {
    str = "<E>";
    cout << str << endl;
    cout << "But <E> --> <Y>" << endl;
    cout << "str --> <Y>" << endl;
    cout << "But also <Y> --> <A><B>"<< endl;
    str =  "AB";
    cout << "Your string is :  " << str << endl;  
    cout << "At this point you have to make a choice : " << endl;
    do  {
    cin >> choice;
    }
    while (choice.compare("n")==0 || choice.compare("<E>")==0);

    
  }
}


  return 0;
}
