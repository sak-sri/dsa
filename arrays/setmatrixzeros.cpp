class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int firstRow=0,firstCol=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0)
                firstCol=1;
        }
        for(int j=0;j<m;j++){
            if(matrix[0][j]==0){
                firstRow=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>=1 && j>=1){
                    if(matrix[i][j]==0){
                        matrix[i][0]=0;
                        matrix[0][j]=0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>=1 && j>=1){
                    if(matrix[i][0]==0 || matrix[0][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(firstCol==1){
                matrix[i][0]=0;
            }
        }
        for(int j=0;j<m;j++){
            if(firstRow==1){
                matrix[0][j]=0;
            }
        }
    }
};