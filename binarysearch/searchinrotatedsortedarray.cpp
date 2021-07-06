class Solution {
public:
    int search(vector<int>& a, int target) {
        int n=a.size();
        int l=0,h=n;
        while(l<=h-1){
            int mid=(l+h)/2;
            cout<<mid<<endl;
            if(a[mid]>=a[l]){
                if(target>a[mid]){
                    l=mid+1;
                }else{
                    if(target>=a[l]){
                        if(target==a[l])
                            return l;
                        h=mid;
                    }else{
                        l=mid+1;
                    }
                }
            }else{
                if(target<=a[mid]){
                    if(target==a[mid])
                        return mid;
                    h=mid;
                }else{
                    if(target>a[h-1])
                        h=mid;
                    else{
                        if(target==a[h-1])
                            return h-1;
                        l=mid+1;
                    }
                }
            }
        }
        if(l>=n || l<0)
            return -1;
        return a[l]==target?l:-1;
    }
};