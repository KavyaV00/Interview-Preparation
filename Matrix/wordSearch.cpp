#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

bool dfs(int i, int j, vector<vector<char>> &board, string word, int count){
    if(count == word.length()){
        return true;
    }
    
    if(i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] != word[count]){
        return false;
    }
    
    char temp = board[i][j];
    board[i][j] = ' ';
    
    bool found = dfs(i+1, j, board, word, count+1)||
                 dfs(i, j+1, board, word, count+1)||
                 dfs(i-1, j, board, word, count+1)||
                 dfs(i, j-1, board, word, count+1);
    
    board[i][j] = temp;
    return found;
    
}

bool exist(vector<vector<char>>& board, string word) {
    for(auto i=0;i<board.size();i++){
        for(auto j=0;j<board[i].size();j++){
            if(board[i][j] == word[0] && dfs(i, j, board, word, 0)){
                return true;
            }
        }
    }
    
    return false;
}
};