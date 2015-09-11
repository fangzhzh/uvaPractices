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
    inline bool operator==(Arc rvalue){
        if( rvalue.start == start && rvalue.end == end) {
            return true;
        } else {
            return false;
        }
    }
};
void printAll(vector<Arc> arcs){
    for ( Arc &i : arcs ) {
        std::cout << '(' << i.start << "," << i.end << ')' << '\t';
    }
    cout << endl;
}

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
    ss.seekg(0);

    while(!ss.eof()) {
        Arc arc;
        ss >> ch >> arc.start >> ch >> arc.end >> ch >> ch;
        cout << "input("<< arc.start << "," << arc.end << ")" << endl;
        arcs.push_back(arc);
    }
    
    printAll(arcs);
    
    // sort
    sort(arcs.begin(), arcs.end(),
    [](const Arc& a, const Arc& b)
           {
           return a.start < b.start;
           });
   

    cout << "after sort" << endl;
    printAll(arcs);

    // remove dumplicate
    vector<Arc> arc2Delete;
    for( int pos = 1; pos < arcs.size()-1; ++pos) {
        Arc a = arcs[pos];
        int prevEnd, nextBegin;
        if( pos == 0) {
            prevEnd = 0;
        } else {
            prevEnd = arcs[pos-1].end;
        }
        if( pos == arcs.size()-1) {
            nextBegin = 100;
        } else {
            nextBegin = arcs[pos+1].start;
        }
        if(a.start < prevEnd && a.end > nextBegin){
            arc2Delete.push_back(a);
            pos++;
        }
    }
    printAll(arc2Delete);
    for( const Arc& arc : arc2Delete) {
        arcs.erase(remove(arcs.begin(), arcs.end(), arc),arcs.end());
    }

    cout << "after remove invalid" << endl;
    printAll(arcs);

    // build first level
    vector< vector<int> > link(arcs.size(), vector<int>(circle.end));
    for( int i = 0; i <  arcs.size(); ++i) {
        if (arcs[i].end < arcs[i].start ) {
            link[i][0] = 0;
        }
        else {
            for( int j = i+1; j < arcs.size(); ++j) {
                if( arcs[i].end >= arcs[j].start-1 ) {
                    link[i][0] = j; 
                    cout << "i:" <<  i << "\t link to " << j << endl;
                    break;
                }
            }
        }
    }
    

    // build to end
    int minLevel=circle.end;
    for (int i = 0; i < arcs.size(); ++i){
        minLevel = circle.end;
        for( int level = 0; level < circle.end; ++level) {
            cout << "i:" << i << ",level:" << level << endl;
            if(link[link[i][level]][0]!=0) {
                link[i][level+1]=link[link[i][level]][0];
            }else {
                if( minLevel > level  && level > 0){
                    minLevel = level;
                    break;
                }
            }
        }
    }
    cout << "level:" << minLevel << endl;
}
