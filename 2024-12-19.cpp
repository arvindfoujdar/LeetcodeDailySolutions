class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]] = i;
        }
        vector<int> vis(n,0);
        int cur = -1,cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int mx = mp[i];
                int j=cur+1;
                while(j<=mx){
                    vis[arr[j]]=1;
                    mx = max(mx,mp[arr[j]]);
                    mx = max(mx,arr[j]);
                    j++;
                }
                cnt++;
                cur = mx;
            }
        }
        return cnt;
    }
};
