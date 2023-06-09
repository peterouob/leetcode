#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }

    void backtrack(vector<string> board, int row)
    {
        if (row == board.size())
        {
            res.push_back(board);
            return;
        }
        int n = board[row].size();
        for (int column = 0; column < n; column++)
        {
            if (!isValide(board, row, column))
            {
                continue;
            }
            board[row][column] = 'Q';
            backtrack(board, row + 1);
            board[row][column] = '.';
        }
    }

    bool isValide(vector<string> board, int row, int column)
    {
        int n = board.size();
        for (int i = 0; i < n; i++)
        {
            if (board[i][column] == 'Q')
            {
                return false;
            }
        }

        for (int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};