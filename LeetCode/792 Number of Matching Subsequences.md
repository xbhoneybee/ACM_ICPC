```
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<int>vec[26];
        int length=S.size();
        for(int i=0;i<length;i++)
        {
            vec[S[i]-'a'].push_back(i);
        }
        int ans=0;
        int num=words.size();
        for(int iw=0;iw<num;iw++)
        {
            int lenwd=words[iw].size();
            bool found=true;
            int next=0;
            for(int posinwd=0;posinwd<lenwd;posinwd++)
            {
                char ch=words[iw][posinwd];
                int fd=lower_bound(vec[ch-'a'].begin(),vec[ch-'a'].end(),next)-vec[ch-'a'].begin();
                if(fd<vec[ch-'a'].size()&&vec[ch-'a'][fd]>=next)
                    next=vec[ch-'a'][fd]+1;
                else {
                    found=false;
                    break;
                }
            }
            if(found)
                ans++;
        }
        return ans;
    }
};
```
