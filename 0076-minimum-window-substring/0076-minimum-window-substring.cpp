class Solution {
public:
    bool check(int a[],int b[]){
        for(int i=0;i<128;i++){
            if(b[i]>a[i])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int a[128]={0},b[128]={0};
        for(char c:t)
            b[c]++;
        int l=0,idx=-1,len=INT_MAX;
        for(int i=0;i<s.size();i++){
            a[s[i]]++;
            while(check(a,b)){
                if(len>i-l+1){
                    len=i-l+1;
                    idx=l;
                }
                a[s[l++]]--;
            }
        }
        if(idx==-1)return "";
        return s.substr(idx,len);
    }
};