#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

struct Point{    
    Point()=default;
    Point(int _x, int _y):x(_x),y(_y){}
    int x = 0;
    int y = 0;
    Point X();
};

int main() {

    vector<int> a = {0, 1, 2, 3, 4};
    int sum = accumulate(a.begin(), a.end(), 5);
    cout<<sum<<endl;
    Point X;
    return 0;
}