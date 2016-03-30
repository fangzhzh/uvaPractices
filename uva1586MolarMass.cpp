#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

float getValue(char atom){
    float ret;
    switch(atom){
        case 'C':
            ret = 12.01;
            break;
        case 'H':
            ret = 1.008;
            break;
        case 'O':
            ret = 16.00;
            break;
        case 'N':
            ret = 14.01;
            break;
        default:
            ret = 0.0;
            break;
    }
    return ret;
}
float processInput(string input){
    float sum = 0.0;
    char curOp = 0;
    int count = 1;
    int numCount = 0;
    for(int i = 0; i < input.length(); ++i){
        char curChar = input[i];
        if(curChar == 'C'
                || curChar == 'H'
                || curChar == 'O'
                || curChar == 'N'){
            sum += (getValue(curOp)*count);
            curOp = curChar;
            count = 1;
            numCount = 0;
        } else if( curChar <='9'
                && curChar >='0'){
            if( numCount > 0){
                count = count * 10 + curChar - '0';
            }  else{
                count = curChar - '0';
                numCount++;
            }

        }
    }
    sum += (getValue(curOp) * count);
    return sum;
}
int main(int argc, char ** argv){
	int count;
    scanf("%d\n",&count);
    while(count-- >0){
        string input;
        getline(cin, input);
        printf("%.3f\n", processInput(input));
    }
}

