#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
struct Point{
    Point(){
        
    }
    Point(int x, int y, int distance=0){
        this->x = x;
        this->y = y;
        this->distance = distance;
    }
    int x;
    int y;
    int distance;
    
};

int main(int argc, const char * argv[]) {
    auto printVecPoint = [](string info, vector<Point> vec){
        return;
        cout << "=========" << info << "       begin" << endl;
        for_each(vec.begin(), vec.end(), [](Point p){
                cout << p.x << '\t' << p.y << '\t' << p.distance << endl;
                });
        cout << "=========" << info << "       end" << endl;
    };

    // insert code here...
    int count;
    scanf("%d",&count);
    int x,y;
    vector<Point> allHouse;
    while (count--) {
        scanf("%d %d", &x, &y);
        Point point(x,y);
        allHouse.push_back(point);
    }
    printVecPoint("all house raw", allHouse);

    Point center1;
    Point center2;
    int caseCount;
    
    scanf("%d%d%d%d%d",&center1.x, &center1.y, &center2.x, &center2.y, &caseCount);

    vector<Point> points4Center1;
    vector<Point> points4Center2;
    for_each(allHouse.begin(), allHouse.end(), [&center1, &points4Center1](Point p){
            Point point(p.x, p.y, pow((center1.x - p.x),2)+pow(center1.y - p.y,2));
            points4Center1.push_back(point);
    });

    for_each(allHouse.begin(), allHouse.end(), [&center2, &points4Center2](Point p){
            Point point(p.x, p.y, pow((center2.x - p.x),2)+pow(center2.y - p.y,2));
            points4Center2.push_back(point);
    });


    sort(points4Center1.begin(), points4Center1.end(),[](const Point point1, const Point point2){
        return point1.distance < point2.distance;
    });
    sort(points4Center2.begin(), points4Center2.end(),[](const Point point1, const Point point2){
        return point1.distance < point2.distance;
    });
    
    int radia1, radia2;
    int caseSeq = 1;
    
    printf("Case 1:\n");
    while (caseCount --) {
        scanf("%d%d", &radia1, &radia2);
        radia1 = pow(radia1,2);
        radia2 = pow(radia2,2);
        vector<Point> dangerPoint1, safePoints1;
        for_each(points4Center1.begin(), points4Center1.end(), [&radia1, &dangerPoint1, &safePoints1](Point point){
            if (point.distance <= radia1) {
                dangerPoint1.push_back(point);
            }else {
                safePoints1.push_back(point);
            }
        });
        
        vector<Point> dangerPoint2, safePoints2;
        for_each(points4Center2.begin(), points4Center2.end(), [&radia2, &dangerPoint2, &safePoints2](Point point){
            if (point.distance <= radia2) {
                dangerPoint2.push_back(point);
            }else {
                safePoints2.push_back(point);
            }
        });

        printVecPoint("dangerPoints1", dangerPoint1);
        printVecPoint("dangerPoints2", dangerPoint2);
        printVecPoint("safePoints1", safePoints1);
        printVecPoint("safePoints2", safePoints2);

        vector<Point> dangerDoublePoint;
        vector<Point> dangerNonePoint;
        for_each(allHouse.begin(), allHouse.end(), [&dangerDoublePoint, &dangerNonePoint, dangerPoint1, dangerPoint2, safePoints1, safePoints2](Point p){
            bool inDanger1 = any_of(dangerPoint1.begin(), dangerPoint1.end(), [p](Point curPoint){
                return curPoint.x == p.x && curPoint.y == p.y;
            });
            bool inDanger2 = any_of(dangerPoint2.begin(), dangerPoint2.end(), [p](Point curPoint){
                return curPoint.x == p.x && curPoint.y == p.y;
            });
            if (inDanger1 && inDanger2) {
                dangerDoublePoint.push_back(p);
            }
            
            bool inSafe1 = any_of(safePoints1.begin(), safePoints1.end(), [p](Point curPoint){
                return curPoint.x == p.x && curPoint.y == p.y;
            });
            bool inSafe2 = any_of(safePoints2.begin(), safePoints2.end(), [p](Point curPoint){
                return curPoint.x == p.x && curPoint.y == p.y;
            });
            if (inSafe1 && inSafe2) {
                dangerNonePoint.push_back(p);
            }

        });
        
        printVecPoint("double", dangerDoublePoint);
        printVecPoint("none", dangerNonePoint);
        
        printf("%d\n",(int)dangerNonePoint.size()-(int)dangerDoublePoint.size());
    }
    
    return 0;
}
