#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
struct Point
{
    double x, y;
};
struct Wall
{
    Point pos1, pos2;
};

double Distance(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double Cross(Point a, Point b, Point c);
bool IsInterSection(Point l1_pos1, Point l1_pos2, Point l2_pos1, Point l2_pos2);
class Graph
{
public:
    int PointNum;
    vector<vector<double>> Matrix;
    vector<Point> points;
    vector<double> distance;
    vector<int> visited;
    vector<Wall> walls;

    Graph();
    bool IsPath(Point p1, Point p2);
    void Dijkstra();
};

int main()
{
    Graph room = Graph();
    room.Dijkstra();
    cout << fixed << setprecision(2) << room.distance[room.PointNum - 1];
    cout << endl;
    system("pause");
    return 0;
}

double Cross(Point a, Point b, Point c)
{
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool IsInterSection(Point l1_pos1, Point l1_pos2, Point l2_pos1, Point l2_pos2)
{
    return Cross(l1_pos1, l2_pos1, l1_pos2) * Cross(l1_pos1, l2_pos2, l1_pos2) <= 0 && Cross(l2_pos1, l1_pos1, l2_pos2) * Cross(l2_pos1, l1_pos2, l2_pos2) <= 0;
}

Graph::Graph()
{
    int WallNum;
    points.push_back(Point{0, 5});
    cin >> WallNum;
    PointNum = 2 + WallNum * 4;
    Matrix.resize(PointNum, vector<double>(PointNum, 9999));
    visited.resize(PointNum, 0);
    distance.resize(PointNum, 9999);
    double x, a1, b1, a2, b2;
    for (int i = 0; i < WallNum; i++)
    {
        cin >> x >> a1 >> b1 >> a2 >> b2;
        points.push_back(Point{x, a1});
        points.push_back(Point{x, b1});
        points.push_back(Point{x, a2});
        points.push_back(Point{x, b2});

        walls.push_back(Wall{Point{x, 0}, Point{x, a1}});
        walls.push_back(Wall{Point{x, b1}, Point{x, a2}});
        walls.push_back(Wall{Point{x, b2}, Point{x, 10}});
    }
    points.push_back(Point{10, 5});

    for (int i = 0; i < PointNum - 1; i++)
        for (int j = i + 1; j < PointNum; j++)
            if (points[i].x == points[j].x)
                continue;
            else if (IsPath(points[i], points[j]))
                Matrix[i][j] = Distance(points[i], points[j]);
}

bool Graph::IsPath(Point p1, Point p2)
{
    for (size_t i = 0; i < walls.size(); i++)
    {
        if (walls[i].pos1.x >= p2.x)
            break;
        if (walls[i].pos1.x <= p1.x)
            continue;
        if (IsInterSection(p1, p2, walls[i].pos1, walls[i].pos2))
            return false;
    }
    return true;
}

void Graph::Dijkstra()
{
    for (int i = 0; i < PointNum; i++)
        if (i == 0)
            distance[i] = 0;
        else
            distance[i] = Matrix[0][i];
    visited[0] = 1;
    double min;
    int pos;
    for (int i = 0; i < PointNum - 1; i++)
    {
        min = 9999;
        for (int j = 0; j < PointNum; j++)
            if (!visited[j] && distance[j] < min)
            {
                min = distance[j];
                pos = j;
            }
        visited[pos] = 1;
        for (int k = 0; k < PointNum; k++)
            if (!visited[k] && distance[k] > distance[pos] + Matrix[pos][k])
                distance[k] = distance[pos] + Matrix[pos][k];
    }
}