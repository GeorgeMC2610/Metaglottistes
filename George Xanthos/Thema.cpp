#include <iostream>
#include <string>
#include <stdlib.h> 
using namespace std;




void theEpsilon (string& str) {
//  int y = strlen(str);
    cout << "<E> --> (<Y>)" << endl;
    for (int i  = 0; i < str.size(); i++) {
      cout << str[i] << '\n';
    }
}
void theAlpha (string& str) {
        int v1 = rand() % 2 + 1;
        if (v1==1) {
            for (int i =0; i<str.size(); i++) {
                int y = strcmp(str[i],"A");
                if (y==0) {
                    str[i].replace(i,"v");
                }
            }
        } else  {
            for (int i =0; i<str.size(); i++) {
            int y = strcmp(str[i],"A");
                if (y==0) {
                    str[i].replace(i,"E");
                }
            }
        }
        

}




int main () {
string str;
str = "E";
cout << "<E> --> (<Y>)" << endl;
str = "Y";
cout << " The string is : " << str << endl ;
cout << "<Y> --> <A><B> " <<endl;
str = "ΑB";
cout << "The string becomes : " << str << endl;
theEpsilon(str);
/*for (int counnter =2; counter <21; counter++ ) {

}
*/

}
