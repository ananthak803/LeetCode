class Solution {
public:
    bool check(int a[],int b[]){
        for(int i=0;i<128;i++){
            if(a[i]>b[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int l=0,n=s1.size(),m=s2.size();
        int t[128],s[128];
        for(char c:s1)
            t[c]++;
        for(int i=0;i<s2.size();i++){
            s[s2[i]]++;
            int len=i-l+1;
            while(len>n){
                s[s2[l++]]--;
                len=i-l+1;
            }
            if(n==len && check(t,s))
                return true;
        }
        return false;
    }
};