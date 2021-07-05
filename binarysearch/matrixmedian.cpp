class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        long long int l=1,h=1e9;
        long long int total=r*c;
        while(l<=h){
            long long int mid=(h+l)/2;
            long long int temp=0;
            for(int i=0;i<r;i++){
                long long int low=0;
                long long int high=c-1;
                while(low<=high){
                    long long int md=(low+high)/2;
                    if(matrix[i][md]<=mid){
                        low=md+1;
                    }else{
                        high=md-1;
                    }
                }
                temp+=low;
            }
            if(temp<=total/2){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return l;
    }
};