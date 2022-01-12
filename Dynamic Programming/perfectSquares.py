# Find minimum number of steps to get sum of given number,by choosing only perfect squares.

def findPerfect(n):
    dp=[]
    dp.append(0)
    dp.append(1)
    for i in range(2,n+1):
        temp=1000000
        for j in range(1,i+1):
            if(j*j<=i):
                temp=min(temp,1+dp[i-j*j])

        dp.append(temp)

    print(dp)
    return dp[n]

print(findPerfect(12))
    