//
// Created by Mr.Hu on 2019/2/18.
//
// leetcode 79 word search
//
// 题目给定一个字符板，以及一个字符串，要求判断是否能从字符板中构成给定的字符串，要求的构成的过程只能是顺序的水平或垂直查找，
// 且同一个位置的字符不能使用多次。
//
// 这个题目我们可以使用递归的方式进行解决，每次判断四个方位的字符与当前待比较字符是否相等，相等则继续上述判断，
// 每次待比较字符需要更新。
// 因为每个字符只能使用一次，所以我们需要保存哪些位置的字符已经被访问过，一种方式是使用pair保存，另一个方式即创建一个新的同字符板大小的
// 二值数组，每次访问后对应位置的更新，在访问之前先判断该位置是否被访问过。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    bool judge(vector<vector<char>> &board, string word, vector<vector<int>> &visited, int r, int c, int count) {

        // end condition
        if (count == word.length()) {
            return true;
        }
        // up
        if (r - 1 >= 0 && !visited[r - 1][c] && board[r - 1][c] == word[count]) {
            visited[r - 1][c] = 1;
            if (judge(board, word, visited, r - 1, c, count + 1)) {
                return true;
            }
            visited[r - 1][c] = 0;
        }
        // down
        if (r + 1 < board.size() && !visited[r + 1][c] && board[r + 1][c] == word[count]) {
            visited[r + 1][c] = 1;
            if (judge(board, word, visited, r + 1, c, count + 1)) {
                return true;
            }
            visited[r + 1][c] = 0;
        }
        // left
        if (c - 1 >= 0 && !visited[r][c - 1] && board[r][c - 1] == word[count]) {
            visited[r][c - 1] = 1;
            if (judge(board, word, visited, r, c - 1, count + 1)) {
                return true;
            }
            visited[r][c - 1] = 0;
        }
        // right
        if (c + 1 < board[0].size() && !visited[r][c + 1] && board[r][c + 1] == word[count]) {
            visited[r][c + 1] = 1;
            if (judge(board, word, visited, r, c + 1, count + 1)) {
                return true;
            }
            visited[r][c + 1] = 0;
        }

        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {
        if (word.length() == 0) {
            return true;
        }
        int row = board.size();
        int column = board[0].size();
        vector<vector<int>> visited(row, vector<int>(column));
        int count = 0;
        bool res;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (board[i][j] == word[count]) {
                    visited[i][j] = 1;
                    if (judge(board, word, visited, i, j, count + 1)) {
                        return true;
                    }
                    visited[i][j] = 0;
                }
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    Solution solution;
    bool res = solution.exist(board, word);
    cout << res << endl;
    return 0;
}