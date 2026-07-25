class Solution {
public:
    int maxFreq(int a[]){
        int res=INT_MIN;
        for(int i=0;i<128;i++){
            res=max(res,a[i]);
        }
        return res;
    }

    int characterReplacement(string s, int k) {
        int a[128],l=0,len=0;
        for(int i=0;i<s.size();i++){
            a[s[i]]++;
            int f=maxFreq(a),t=i-l+1;
            int dif=t-f;
            while(dif>k){
                a[s[l++]]--;
                f=maxFreq(a),t=i-l+1;
                dif=t-f;
            }
            f=maxFreq(a),t=i-l+1;
            dif=t-f;
            if(dif<=k)
                len=max(len,i-l+1);
        }
        return len;
    }
};