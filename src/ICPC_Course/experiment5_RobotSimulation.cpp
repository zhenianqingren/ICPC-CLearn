#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> Map;
void initMap(int length, int width);
void RobotSimulation(int start_x, int start_y);
int main()
{
    int height,width,x,y;
    cout<<"input size: height      width\n";
    cin>>height>>width;
    initMap(height,width);
    cout<<"input start: x      y\n";
    cin>>x>>y;
    RobotSimulation(x,y);
    cout << endl;
    system("pause");
    return 0;
}

void initMap(int height, int width)
{
    Map.resize(height, vector<char>(width));
    cout << "Please input Map\n";
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            cin >> Map[i][j];
}

void RobotSimulation(int start_x, int start_y)
{
    int cur_x = start_x, cur_y = start_y;
    while (true)
    {
        cout<<"( "<<cur_x<<" , "<<cur_y<<" )\n";
        switch (Map[cur_x][cur_y])
        {
        case 'N':
            cur_x -= 1;
            break;

        case 'S':
            cur_x += 1;
            break;
        case 'W':
            cur_y -= 1;
            break;
        case 'E':
            cur_y += 1;
            break;
        }
        if (cur_x < 0 || cur_y < 0 || cur_x >= int(Map.size()) || cur_y >= int(Map[0].size()))
            break;
    }
}
