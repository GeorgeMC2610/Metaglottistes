#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;


void theEpsilon(string& str) {
    //  int y = strlen(str);
    cout << "<E> --> (<Y>)" << endl;
    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << '\n';
    }
}
void theAlpha(string &str) {
            int v1 = rand() % 2;
      cout << v1 << endl;
    if (v1 == 0) {
        for (int i = 0; i < str.length(); i++) {
            int y = str.compare("A");
            if (y == 0) {
                str[i] = 'v';
            }
        }
    }
    else {
        for (int i = 0; i < str.length(); i++) {
            int y = str.compare("A");
            if (y == 0) {
                str[i] = 'E';

            }
        }
    }

    cout << str << endl;





}




int main() {
    string str;
    srand((unsigned)time(0));
   // int v1 = rand() % 2;
    str = "E";
    cout << "<E> --> (<Y>)" << endl;
    str = "Y";
    cout << " The string is : " << str << endl;
    cout << "<Y> --> <A><B> " << endl;
    str = "AB";
    cout << "The string becomes : " << str << endl;

    theAlpha(str);
    cout << str << endl;


}
