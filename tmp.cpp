#include <vector>
#include <iostream>
using namespace std;

int func(int y)
{
    return (y++);
}

int main()
{
    vector<vector<int>> x;

    // for (int i = 0; i < 3; i++)
    // {
    //     x.push_back(vector<int>());
    //     for (int j = 0; j < 3; j++)
    //     {
    //         int tmp;
    //         cin >> tmp;
    //         x[i].push_back(tmp);
    //     }
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << x[i][j];
    //     }
    // }

    // x.push_back(vector<int>());
    // x.push_back(vector<int>());
    // x[0].push_back(123);
    // x[1].push_back(234);

    // cout << (*(x.end() - 1))[0];

    return 0;
}