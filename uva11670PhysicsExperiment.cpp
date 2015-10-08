#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAXN = 100000;
double point[MAXN], dist;
int main() {
    int n, cases = 0;
    while (scanf("%d", &n) == 1 && n != 0) {
        for (int i = 0; i < n; i++)
            scanf("%lf", &point[i]);
        scanf("%lf", &dist);
        
        sort(point, point + n);
        double t = 0;
        for (int i = 1; i < n; i++) {
            if (point[i] - point[i-1] > dist) { 
                if ((point[i] - t) - point[i-1] > dist) { 
                    double move = ((point[i] - t) - point[i-1] - dist)/2;
                    point[i] = point[i] - move - t;
                    t += move;
                } else {
                    point[i] = point[i-1] + dist;
                }
            } else { 
                if (point[i] + t < point[i-1] + dist)
                    point[i] = point[i] + t;
                else
                    point[i] = point[i-1] + dist;
            }
        }
        printf("Case %d: %.3lf\n", ++cases, t);
    }    
    return 0;
}
