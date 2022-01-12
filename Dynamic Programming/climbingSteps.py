#  Find number of reach final step in steps of 1 or 2

def climbSteps(n, dp={}):
    if(n<=2):
        return n

    if(n in dp):
        return dp[n]

    dp[n]=climbSteps(n-1)+climbSteps(n-2)

    return dp[n]

print(climbSteps(5))