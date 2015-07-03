/*
ID: fangzhz1
PROG: transform
LANG: C++
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
int main(int argc, char ** argv)
{
    long Base;
    vector<int> Dimentions;
    vector<int> Ls;
    vector<int> Us;
    vector<int> Cs;

    // safe
    if( argc < 1)
        return -1;
    // read file
    printf ("Hello world");
    // init file
    for (int i = 0; i < 100; i++) {
        /* code */
        Ls.push_back(i);
    }
    // calc
    for (int i; i < Ls.size(); ++i){
        /* code */
        printf("%d\n",Ls[i]);
    }
    
    return 0;
}
