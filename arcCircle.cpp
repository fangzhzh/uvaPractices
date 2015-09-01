#include<stdio.h>

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include <algorithm>
using namespace::std;

struct Arc{
    int start;
    int end;
};

int main(int argc, char **argv){
    // read files
    std::ifstream input( "input.txt" );
    std::ofstream output("output.txt");
    
    std::string line;
    std::getline(input, line);
    std::stringstream ss(line);
    Arc circle;
    char ch;
    ss >> ch >> circle.start >> ch >> circle.end >> ch;
    cout << "circle.start: " << circle.start << '\t' << "circle.end" << circle.end << endl; 
    vector<Arc> arcs;
    
    std::getline(input, line);
    ss << line;
    while(ss.good()) {
        Arc arc;
        ss >> ch >> arc.start >> ch >> arc.end >> ch >> ch;
        arcs.push_back(arc);
        
    }
    
    for ( auto &i : arcs ) {
        std::cout << '(' << i.start << "," << i.end << ')' << '\t';
    }
    cout << endl;
    
    // sort
    sort(arcs.begin(), arcs.end(),
    [](const Arc& a, const Arc& b)
            {
            return a.start < b.start;
            });
    
    

    cout << "after sort" << endl;
    for ( auto &i : arcs ) {
        std::cout << '(' << i.start << "," << i.end << ')' << '\t';
    }
   cout << endl;
    // remove dumplicate
    
    
    // build first leve
    
    // build to end
}
