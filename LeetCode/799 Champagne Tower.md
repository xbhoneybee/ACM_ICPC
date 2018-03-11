```
class Solution {
private:
    double val[105][105];
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        memset(val,0,sizeof val);
        val[0][0]=poured;
        
        for(int i=1;i<100;i++){
            for(int j=0;j<=i;j++){
                if(val[i-1][j]>1)
                val[i][j]+=(val[i-1][j]-1)/2.0;
                if(j>0&&val[i-1][j-1]>1)
                val[i][j]+=(val[i-1][j-1]-1)/2.0;
            }
        }
        if(val[query_row][query_glass]>1)
            val[query_row][query_glass]=1;
        if(val[query_row][query_glass]<0)
            val[query_row][query_glass]=0;
        return val[query_row][query_glass];
    }
};
```
