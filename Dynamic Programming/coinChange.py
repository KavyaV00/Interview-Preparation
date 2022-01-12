def coinChange(d,target):
    dp={ n:float("inf") for n in range(target+1) }

    def dfs(i,target,n=0):
        if(i>target):
            return 0
        if(target==0):
            return n

        if(target<0):
            return 0
        if(i in dp):
            return dp[i]

        for j in d:
            dp[j]=min(dp[j],n)
            res=dfs(target-j,target-j,n+1)
            if(res<dp[i]):
                n=n+1
                dp[i]=n
        print(dp)

           
        return dp[i]

    
        

    return dfs(0,target)

print(coinChange([1,3,4,5],7))