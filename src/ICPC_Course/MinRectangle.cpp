#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

struct Point
{
    double x, y;
    bool operator==(Point &p) { return this->x == p.x && this->y == p.y; }
};

struct Line
{
    Point pos1, pos2;
};

vector<Point> NodeSet;
vector<Point> ConvexHull;
vector<Line> Lines;
double Distance(Point p1, Point p2);
double Cross(Point a, Point b, Point c);
double Dot(Point a, Point b, Point c); //ab·ac
void InputPoint();
void Graham();
void AllLines();
int LongestPoint(Line line, int pos);
double Area(Line line, int pos);
double FindMinRectangle();

int main()
{
    InputPoint();
    Graham();
    AllLines();
    cout << fixed << setprecision(5) << FindMinRectangle();
    cout << endl;
    system("pause");
    return 0;
}

double Distance(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double Cross(Point a, Point b, Point c) //ab x ac
{
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

double Dot(Point a, Point b, Point c)
{
    return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}

void InputPoint()
{
    int n;
    cin >> n;
    double x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        NodeSet.push_back(Point{x, y});
    }
}

void Graham()
{
    int first = 0;
    for (size_t i = 1; i < NodeSet.size(); i++)
        if (NodeSet[i].y < NodeSet[first].y || (NodeSet[i].y == NodeSet[first].y && NodeSet[i].x < NodeSet[first].x))
            first = i;
    if (first != 0)
        swap(NodeSet[0], NodeSet[first]);

    sort(NodeSet.begin() + 1, NodeSet.end(), [=](Point p1, Point p2) -> bool
         {
             double res = Cross(NodeSet[0], p1, p2);
             if (res > 0 || (res == 0 && Distance(NodeSet[0], p1) < Distance(NodeSet[0], p2)))
                 return true;
             return false;
         });

    ConvexHull.push_back(NodeSet[0]);
    ConvexHull.push_back(NodeSet[1]);
    ConvexHull.push_back(NodeSet[2]);

    for (size_t i = 3; i < NodeSet.size(); i++)
    {
        while (Cross(ConvexHull[ConvexHull.size() - 1], ConvexHull[ConvexHull.size() - 2], NodeSet[i]) >= 0) //剔除共线和向左转的点
            ConvexHull.pop_back();
        ConvexHull.push_back(NodeSet[i]);
    }
}

void AllLines()
{
    Lines.push_back(Line{ConvexHull[ConvexHull.size() - 1], ConvexHull[0]});
    for (size_t i = 0; i < ConvexHull.size() - 1; i++)
        Lines.push_back(Line{ConvexHull[i], ConvexHull[i + 1]});
}

double Area(Line line, int pos)
{
    double height = abs(Cross(ConvexHull[pos], line.pos1, line.pos2)) / Distance(line.pos1, line.pos2);
    double width;
    int left = (pos == (int)ConvexHull.size() - 1 ? 0 : pos + 1);
    int right = (pos == 0 ? ConvexHull.size() - 1 : pos - 1);
    double MaxLeft = 0;
    double MaxRight = 0;
    while (true)
    {
        if (!(ConvexHull[left] == line.pos1) && Dot(line.pos1, ConvexHull[left], line.pos2) <= 0)
            if (abs(Dot(line.pos1, ConvexHull[left], line.pos2)) > abs(MaxLeft))
                MaxLeft = Dot(line.pos1, ConvexHull[left], line.pos2);
        if (!(ConvexHull[left] == line.pos1))
            left = (left + 1) % ConvexHull.size();
        if (!(ConvexHull[right] == line.pos2) && Dot(line.pos2, ConvexHull[right], line.pos1) <= 0)
            if (abs(Dot(line.pos2, ConvexHull[right], line.pos1)) > abs(MaxRight))
                MaxRight = Dot(line.pos2, ConvexHull[right], line.pos1);
        if (!(ConvexHull[right] == line.pos2))
            right = (right == 0 ? ConvexHull.size() - 1 : right - 1);
        if ((ConvexHull[left] == line.pos1) && (ConvexHull[right] == line.pos2))
            break;
    }
    width = (abs(MaxLeft + MaxRight) / Distance(line.pos1, line.pos2)) + Distance(line.pos1, line.pos2);
    return height * width;
}

int LongestPoint(Line line, int pos)
{
    double Max = 0;
    for (size_t i = pos; !(ConvexHull[i] == line.pos1);)
    {
        if (abs(Cross(ConvexHull[i], line.pos1, line.pos2)) > Max)
        {
            Max = abs(Cross(ConvexHull[i], line.pos1, line.pos2));
            pos = i;
        }
        i = (i + 1) % ConvexHull.size();
    }
    return pos;
}

double FindMinRectangle()
{
    int pos;
    double Max = 0;
    for (size_t i = 0; i < ConvexHull.size(); i++)
    {
        if (ConvexHull[i] == Lines[0].pos1 || ConvexHull[i] == Lines[0].pos2)
            continue;
        if (abs(Cross(ConvexHull[i], Lines[0].pos1, Lines[0].pos2)) > Max)
        {
            Max = abs(Cross(ConvexHull[i], Lines[0].pos1, Lines[0].pos2));
            pos = i;
        }
    }
    double min = Area(Lines[0], pos);
    for (size_t i = 1; i < Lines.size(); i++)
    {
        pos = LongestPoint(Lines[i], pos);
        if (Area(Lines[i], pos) < min)
            min = Area(Lines[i], pos);
    }
    return min;
}
