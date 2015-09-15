#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
struct Point{
    Point(){
        
    }
    Point(int x, int y, int distance=0, int distance2=0){
        this->x = x;
        this->y = y;
        this->distance = distance;
        this->distance2 = distance2;
    }
    int x;
    int y;
    int distance;
    int distance2;
};

int main(int argc, const char * argv[]) {
    int testCase = 1;
    while (true) {
        int count;
        scanf("%d",&count);
        if(count == 0) {
            break;
        }
        int x,y;
        vector<Point> allHouse;
        vector<int> dis4Center1;
        vector<int> dis4Center2;
        while (count--) {
            scanf("%d %d", &x, &y);
            Point point(x,y);
            allHouse.push_back(point);
        }
        
        Point center1;
        Point center2;
        int caseCount;
        
        scanf("%d%d%d%d%d",&center1.x, &center1.y, &center2.x, &center2.y, &caseCount);
        for_each(allHouse.begin(), allHouse.end(), [&center1, &center2, &dis4Center1, &dis4Center2](Point& p) mutable{
            p.distance = pow(center1.x - p.x,2)+pow(center1.y - p.y,2);
            p.distance2 = pow(center2.x - p.x,2)+pow(center2.y - p.y,2);
            dis4Center1.push_back(p.distance);
            dis4Center2.push_back(p.distance2);
        });
       
        sort(dis4Center1.begin(), dis4Center1.end());
        sort(dis4Center2.begin(), dis4Center2.end());
       int radia1, radia2;
       printf("Case %d:\n", testCase);

       while(caseCount--){
           scanf("%d%d", &radia1,&radia2);
            radia1 = pow(radia1,2);
            radia2 = pow(radia2,2);
            int score=0;
            int left = 0, right = allHouse.size();
            int mid;
            while (left!=right)  { 
                mid=(left+right)/2;   
                if (dis4Center1[mid]<=radia1) 
                    left=mid+1;   
                else 
                    right=mid;  
            } 
            score = (left);
            left = 0;
            right = allHouse.size();
            while (left!=right)  { 
                mid=(left+right)/2;   
                if (dis4Center2[mid]<=radia2) 
                    left=mid+1;   
                else 
                    right=mid;  
            } 
    
            score += (left);
            score = allHouse.size() - score;
    
            printf("%d\n",max(score,0));
       }
       
        testCase++;
    }
    return 0;
}

