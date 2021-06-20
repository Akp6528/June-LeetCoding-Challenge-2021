  class Solution {
public:
    bool vis[51][51],a[51][51];
    int n;
    int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
    void dfs(int i,int j){
        vis[i][j]=1;
        for(int r=0;r<4;r++){
            int g=i+dx[r],h=j+dy[r];
            if(g>=0 && h>=0 && g<n && h<n && a[g][h] && !vis[g][h]) dfs(g,h);
        }
    }
    int swimInWater(vector<vector<int>>& b) {
        n=b.size();
        int s=max(b[0][0],b[n-1][n-1]),e=n*n-1,mid,ans;
        while(s<=e){
            mid=(s+e)/2;
            memset(a,0,sizeof(a));
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(b[i][j]<=mid) a[i][j]=1;
                }
            }
            memset(vis,0,sizeof(vis));
            dfs(0,0);
            if(vis[n-1][n-1]){
                ans=mid;e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};
