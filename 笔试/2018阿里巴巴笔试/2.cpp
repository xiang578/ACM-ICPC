#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point
{
    int value;
    int num;
    double ratio;
};

void input(vector<Point>* points);

double calculateExpectation(const vector<Point>& points, const int total, const int min);
int main()
{
    int total = 0;
    cin >> total;
    int min = 0;
    cin >> min;

    vector<Point> points;
    input(&points);

    double res = calculateExpectation(points, total, min);
    cout << setiosflags(ios::fixed) << setprecision(6) << res << endl;                                                                                                                                                                                          
    return 0;
}

void input(vector<Point>* points)
{
    int n = 0;
    cin >> n;
    points->resize(n);

    double sum = 0;
    for (int i = 0; i < n; ++i)
    {   
        Point& point = (*points)[i];
        cin >> point.value;
        cin >> point.num;
        sum += point.num;
    }

    for (int i = 0; i < n; ++i)
    {   
        Point& point = (*points)[i];
        point.ratio = point.num / sum;
    }
}

double calculateExpectation(const vector<Point>& points, const int total, const int min)
{
    return 1;
}