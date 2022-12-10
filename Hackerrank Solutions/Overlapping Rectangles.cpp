#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.youtube.com/watch?v=ICtwTFkvFHY
// https://www.hackerrank.com/contests/smart-interviews/challenges/si-overlapping-rectangles/submissions/code/1353238518

struct Point{
    long long int x, y;
};

long long int commonRegion(Point a, Point b, Point c, Point d){
    // minimum and maximum of x-values of top co-ordinates(b,d) and of bottom coordinates respectively(a, c) 
    long long int width = min(b.x, d.x) - max(c.x, a.x);  
    // minimum and maximum of y-values of top co-ordinates(b,d) and of bottom coordinates respectively(a, c) 
    long long int length = min(b.y, d.y) - max(c.y, a.y);
    if(width>0 and length>0) return length * width;
    return 0;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        Point a, b, c, d;
        cin >> a.x >> a.y;
        cin >> b.x >> b.y;
        cin >> c.x >> c.y;
        cin >> d.x >> d.y;
        long long int area1 = abs(a.x-b.x) * abs(a.y-b.y);
        long long int area2 = abs(c.x-d.x) * abs(c.y-d.y);
        cout << area1 + area2 - commonRegion(a, b, c, d) << endl;
    }
    return 0;
}
