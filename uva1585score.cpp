#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
int processInput(string input){
    int count = 0;
    for( int i = input.length()-1; i >= 0 ; --i){
        if(input[i] == 'O' ){
            count += 1;
            for( int j = i-1; j >=0; --j){
                if(input[j] == 'X'){
                    break;
                }
                else{
                    count += 1;
                }
            }
        } else{
            continue; 
        }


    }
    return count;

}
int main(int argc, char ** argv){
	int count;
    scanf("%d\n",&count);
    while(count-- > 0){
        string input;
        getline(cin, input);
        printf("%d\n", processInput(input));
    }
}

