int knight(int A, int B, int C, int D, int E, int F) {
    int dx[]={1,2,1,2,-1,-2,-1,-2};
    int dy[]={-2,-1,2,1,-2,-1,2,1};
    
    bool vis[A+2][B+2]={};
    queue<array<int,3>> q;
    q.push({C,D,0});
    vis[C][D]=1;
    while(q.size())
    {
        auto [x,y,moves]=q.front();
        q.pop();
        
        if(x==E and y==F)
            return moves;
        
        for(int ii=0;ii<8;ii++)
        {
            int i=x+dx[ii];
            int j=y+dy[ii];
            if(i>=1 and j>=1 and i<=A and j<=B and !vis[i][j])
            {
                vis[i][j]=1;
                q.push({i,j,moves+1});
            }
        }
    }
    
    return -1;
}