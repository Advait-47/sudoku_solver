#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int c = 0;
int sqsz = 9;
vector<vector<int>> board(sqsz, vector<int>(sqsz, 0));
vector<pair<pair<int, int>, vector<int>>> domain;

void printBoard()
{
    for (int i = 0; i < sqsz; i++)
    {
        for (int j = 0; j < sqsz; j++)
        {

            if ((j + 1) % 3 == 0)
            {
                if (board[i][j] == 0)
                    cout << "."
                         << " |";
                else
                    cout << board[i][j] << " |";
            }
            else
            {
                if (board[i][j] == 0)
                    cout << "."
                         << " ";
                else
                    cout << board[i][j] << " ";
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0)
        {
            for (int j = 0; j < 21; j++)
            {
                cout << "-";
            }
            cout << endl;
        }
    }
}

bool satisfy(pair<int, int> pos)
{
    // cout << board[pos.first][pos.second] << " marked" << endl;
    // cout << "1\n";
    for (int i = 0; i < sqsz; i++)
    {
        if (board[i][pos.second] == board[pos.first][pos.second] && (i != pos.first))
        {
            // cout << "1 failed\n";
            return false;
        }
    }
    // cout << "2\n";
    for (int i = 0; i < sqsz; i++)
    {
        if (board[pos.first][i] == board[pos.first][pos.second] && (i != pos.second))
        {
            // cout << "2 failed\n";
            return false;
        }
    }
    // cout << "3\n";
    for (int i = 3 * (pos.first / 3); i <= 3 * (pos.first / 3) + 2; i++)
    {
        for (int j = 3 * (pos.second / 3); j <= 3 * (pos.second / 3) + 2; j++)
        {
            if (board[i][j] == board[pos.first][pos.second] && (i != pos.first || j != pos.second))
            {
                // cout << "3 failed\n";
                return false;
            }
        }
    }
    // cout << "trueeeee\n";
    return true;
}

void getDomain()
{
    for (int i = 0; i < sqsz; i++)
    {
        for (int j = 0; j < sqsz; j++)
        {
            if (board[i][j] == 0)
            {
                // cout << i << " " << j << " position\n";
                domain.push_back(make_pair(make_pair(i, j), vector<int>()));
                for (int k = 1; k <= sqsz; k++)
                {
                    board[i][j] = k;
                    if (satisfy(make_pair(i, j)))
                    {
                        // cout << k << " value inserted\n";
                        domain.back().second.push_back(k);
                    }
                    board[i][j] = 0;
                }
                // printBoard();
                //  cin >> c;
            }
        }
    }
}

void setBoard()
{
    for (int i = 0; i < sqsz; i++)
    {
        for (int j = 0; j < sqsz; j++)
        {
            cin >> board[i][j];
        }
    }
}

bool operate(int ind)
{
    if (ind == domain.size())
    {
        return true;
    }
    for (int i = 0; i < domain[ind].second.size(); i++)
    {
        board[domain[ind].first.first][domain[ind].first.second] = domain[ind].second[i];
        if (!satisfy(make_pair(domain[ind].first.first, domain[ind].first.second)))
        {
            board[domain[ind].first.first][domain[ind].first.second] = 0;
            // return false;
        }
        else
        {
            // ind++;
            if (operate(ind + 1))
            {
                return true;
            }
            else
            {
                board[domain[ind].first.first][domain[ind].first.second] = 0;
                // return false;
            }
        }
    }
    return false;
}

int main()
{
    setBoard();
    cout << endl;
    printBoard();
    getDomain();
    // cout << "hi\n";
    if (operate(0))
    {
        printBoard();
    }
    else
    {
        cout << "Can't be solved\n";
    }

    // cout << "bye\n";
}