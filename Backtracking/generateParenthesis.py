def generateParenthesis(n):
    res=[]
    inner=""
    
    def dfs(n,res,inner,count):
        if(n==0 and count==0):
            res.append(inner)
            # print(inner)
            inner=""
            return
        # if(n==count):
        #     return
        print(inner)
        if(count<0):
            return
        if(count<n):
            dfs(n,res,inner+"(",count+1)

        dfs(n-1,res,inner+")",count-1)
        
        
        return res
    return dfs(n,res,inner,0)


print(generateParenthesis(3))