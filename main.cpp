class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,char value)
    {
        int n=board.size();
        //row check
        for(int i=0;i<n;i++)
        {
            if(board[row][i]==value)
            {
                return false;
            }
        }

        //col check
        for(int i=0;i<n;i++)
        {
            if(board[i][col]==value)
            {
                return false;
            }
        }        

        //3*3 block check
        for(int i=0;i<n;i++)
        {
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==value)
            {
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        int n=board.size();
        for(int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                //check for empty cell;
                if(board[i][j]=='.')
                {
                    //fill all values from 1-9:
                    for(char val ='1';val<='9';val++)
                    {
                        //check for safety:
                        if(isSafe(board,i,j,val))
                        {
                            //insert
                            board[i][j]=val;
                            //baki recurrsion sambhal lega
                            bool aageKaSolution=solve(board);
                            if(aageKaSolution==true)
                            {
                                return true;      //because we only need one solution for a cell thats why return true
                            }
                            else
                            {
                                //backtracking
                                board[i][j]='.';
                            }
                        }
                    }
                    // that maeans 1-9 tak koi bhi value satisfy nahi ki
                    return false;
                }
            }
        }
        //al cells filled
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
