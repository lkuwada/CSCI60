#include <iostream>
#include <utility>

using namespace std;

pair<int, double> read_pair()
{
    cout << "Enter two integers: ";
    int x;
    double y;
    cin >> x >> y;
    return pair<int, double>(x,y);
}

int main()
{
    pair<int, double> p;
    p = read_pair();

    cout << p.first << ", " << p.second << endl;
}
