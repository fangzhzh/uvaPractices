#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
int main(){
    while(true){
        string input;
        getline(cin, input);
        if( cin.eof() ){
            return 0;
        }
        cout << input << endl;
    }
    return 0;
}
