#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    int flag=0;
    for(int i=0;i<9;i++)
    {
        vector<int> visit1(9,0);
        vector<int> visit2(9,0);
        vector<int> visit3(9,0);
        for(int j=0;j<9;j++)
        {
            if(board[i][j]!='.')
            {
                int ind1=board[i][j]-'0'-1;
                if(visit1[ind1])
                {
                    flag++;
                    break;
                }
                else
                {
                    visit1[ind1]++;
                }
            }
            
            if(board[j][i]!='.')
            {
                int ind2=board[j][i]-'0'-1;
                if(visit2[ind2])
                {
                    flag++;
                    break;
                }
                else
                {
                    visit2[ind2]++;
                }
            }
            if(board[i/3*3+j/3][i%3*3+j%3]!='.')
            {
                int ind3=board[i/3*3+j/3][i%3*3+j%3]-'0'-1;
                if(visit3[ind3])
                {
                    flag++;
                    break;
                }
                else
                {
                    visit3[ind3]++;
                }
            }
        }
        if(flag)
            break;
    }
    return !flag;
}

int main()
{
    vector<vector<char>> board;
    string b[9][9]={"8","3",".",".","7",".",".",".",".",
                    "6",".",".","1","9","5",".",".",".",
                    ".","9","8",".",".",".",".","6",".",
                    "8",".",".",".","6",".",".",".","3",
                    "4",".",".","8",".","3",".",".","1",
                    "7",".",".",".","2",".",".",".","6",
                    ".","6",".",".",".",".","2","8",".",
                    ".",".",".","4","1","9",".",".","5",
                    ".",".",".",".","8",".",".","7","9"};
    for(int i=0;i<9;i++)
    {
        vector<char> temp(0);
        for(int j=0;j<9;j++)
        {
            temp.push_back(b[i][j][0]);
            //cout<<i/3*3+j/3<<" "<<i%3*3+j%3<<"  ";
        }
        board.push_back(temp);
        //cout<<endl;
    }
    cout << isValidSudoku(board);
    return 0;
}
