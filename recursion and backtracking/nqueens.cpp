class Solution {
public:
    vector<vector<string> > ans;
    void helper(int r,int n,vector<string> &temp,vector<bool> &occupied,vector<bool> &lower,vector<bool> &upper){
        if(r==n){
            ans.push_back(temp);
            return ;
        }
        for(int c=0;c<n;c++){
           if((!occupied[c]) && (!lower[r+c]) && (!upper[n-1+c-r])){
               lower[r+c]=true;
               upper[n-1+c-r]=true;
               occupied[c]=true;
               temp[r][c]='Q';
               helper(r+1,n,temp,occupied,lower,upper);
               lower[r+c]=false;
               upper[n-1+c-r]=false;
               occupied[c]=false;
               temp[r][c]='.';
           }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string str;
        for(int i=0;i<n;i++)
            str+='.';
        vector<string> temp(n,str);
        vector<bool> occupied(n,false),lowerdiagonal(2*n-1,false),upperdiagonal(2*n-1,false);
        helper(0,n,temp,occupied,lowerdiagonal,upperdiagonal);
        return ans;
    }
};