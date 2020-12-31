#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;




void theEpsilon (string& str) {
//  int y = strlen(str);
    cout << "<E> --> (<Y>)" << endl;
    for (int i  = 0; i < str.size(); i++) {
      cout << str[i] << '\n';
    }
}
void theAlpha (string& str, int v1 ) {
      //  cout << v1 << endl;
        if (v1==1) {
            for (int i =0; i<str.size(); i++) {
                int y = str.compare("A");
                if (y==0) {
                    str.replace(i,"A","v");
                }
            }
        } else  {
            for (int i =0; i<str.size(); i++) {
            int y = str.compare("A");
                if (y==0) {
                    str.replace(i,"A","E");

                }
            }
        }




          cout << str << endl;


}




int main () {
string str;
srand((unsigned) time(0));
int v1  = 1 + (rand() % 3);
//cout << v1 << endl;
str = "E";
cout << "<E> --> (<Y>)" << endl;
str = "Y";
cout << " The string is : " << str << endl ;
cout << "<Y> --> <A><B> " <<endl;
str = "ΑB";
cout << "The string becomes : " << str << endl;
//theEpsilon(str);
theAlpha(str,v1);
cout << str << endl;
/*for (int counnter =2; counter <21; counter++ ) {

}
*/

}
