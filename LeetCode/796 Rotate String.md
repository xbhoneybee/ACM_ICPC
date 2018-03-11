```
class Solution {
public:
    bool rotateString(string A, string B) {
        for(int ia=0;ia<A.size();ia++)
        {
            string suba=A.substr(ia)+A.substr(0,ia);
            if(suba==B)
                return true;
        }
        return false;
    }
};
```
