```
class Solution {
private:
    bool check(vector<string>& board,char ch){
       
        for(int i=0;i<3;i++)
        {
           if(board[0][i]==ch&&board[1][i]==ch&&board[2][i]==ch)
               return true;
           if(board[i][0]==ch&&board[i][1]==ch&&board[i][2]==ch)
               return true;
        }
        if(board[0][0]==ch&&board[1][1]==ch&&board[2][2]==ch)
               return true;
        if(board[0][2]==ch&&board[1][1]==ch&&board[2][0]==ch)
               return true;
        return false;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        int numx=0,numo=0;
      
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i][j]=='X')
                    numx++;
                if(board[i][j]=='O')
                    numo++;
                
            }
        }
        if(numx==numo){
            if(numx>=3){
                bool winx=false;
                //bool wino=false;
                winx=check(board,'X');
                //wino=check(board,'O');
                if(winx)
                    return false;
                else return true;
            }else return true;
        }else if(numx==numo+1){
            bool wino=false;
            wino=check(board,'O');
            if(wino)
                 return false;
            else return true;
        }else return false;
            
    }
};
```
