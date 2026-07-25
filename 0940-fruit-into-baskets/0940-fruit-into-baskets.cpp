class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,res=INT_MIN;
        unordered_map<int,int> m;
        for(int i=0;i<fruits.size();i++){
            m[fruits[i]]++;
            while(m.size()>2){
                m[fruits[l]]--;
                if(m[fruits[l]]==0)
                    m.erase(fruits[l]);
                l++;
            }
            res=max(i-l+1,res);
        }
        return res;
    }
};