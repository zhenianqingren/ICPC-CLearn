#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

struct Point
{
    double x, y;
};

vector<Point> points;

void input();
double Cross(Point a, Point b, Point c); //ab x ac
bool IsInterSection(Point l1_pos1, Point l1_pos2, Point l2_pos1, Point l2_pos2);
bool IsCross();
double Area();

int main()
{
    input();
    if (points.size() < 3 || IsCross())
        cout << "Impossible\n";
    else
        cout << Area();
    cout << endl;
    system("pause");
    return 0;
}

void input()
{
    int size;
    double x, y;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> x >> y;
        points.push_back(Point{x,y});
    }
}

double Cross(Point a, Point b, Point c)
{
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool IsInterSection(Point l1_pos1, Point l1_pos2, Point l2_pos1, Point l2_pos2)
{
    return Cross(l1_pos1, l2_pos1, l1_pos2) * Cross(l1_pos1, l2_pos2, l1_pos2) <= 0 && Cross(l2_pos1, l1_pos1, l2_pos2) * Cross(l2_pos1, l1_pos2, l2_pos2) <= 0;
}

bool IsCross()
{
    for (size_t i = 2; i < points.size() - 1; i++)
        for (size_t j = 0; j < i - 1; j++)
            if (IsInterSection(points[i], points[i + 1], points[j], points[j + 1]))
                return true;

    for (size_t i = 1; i < points.size() - 2; i++)
        if (IsInterSection(points[points.size() - 1], points[0], points[i], points[i + 1]))
            return true;
    return false;
}

double Area()
{
    double area = 0;
    for (size_t i = 1; i < points.size() - 1; i++)
        area += abs(Cross(points[0], points[i], points[i + 1])) / 2;
    return area;
}