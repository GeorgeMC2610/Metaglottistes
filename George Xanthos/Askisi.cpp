#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[]) {
cout << "The rules of our grammar are :" << endl;
cout << "E --> Y" << endl;
cout << "Y --> AB" << endl;
cout << "A -->  n or  empty" << endl;
cout << "B--> -Y or +Y or empty" << endl;
bool start = true;
string answer ;
string str;
while (start) {
  cout << "Do you want to start ???" << endl;
  std::cin >> answer;
  if (answer.compare("Yes")) {
    start = true;
  } else {
    start = false;
  }
  if (start) {
    str = "<E>";
    cout << str << endl;
    cout << "But <E> --> <Y>" << endl;
    cout << "str --> <Y>" << endl;
    
  }
}


  return 0;
}
