# leetcode 983

def minCost(days, cost):
    dp={}

    def dfs(i):
        if(i==len(days)):
            return 0

        if i in dp:
            return dp[i]

        dp[i]=float("inf")
        for d,c in zip([1,7,30], cost):
            j=i

            while(j<len(days) and days[j]<days[i]+d):
                j=j+1
            # print(i, days[i], "\t", j, "\t", d,c)
            dp[i]=min(dp[i], c+dfs(j))


        return dp[i]

    return dfs(0)

print(minCost([1,4,5,6,7,8,20],[2,7,15]))