def dfs(i, nums, target, sum, res, inner):
    if(sum==target):
        res.append(inner.copy())
        return
    if(i>=len(nums) or sum>target):
        return
    candidate=nums[i]
    
    inner.append(candidate)
    dfs(i,nums, target, sum+candidate,res,inner)
    inner.pop()
    dfs(i+1,nums, target, sum,res,inner)


    return res

def comboSum(nums, target):
    res=[]
    inner=[]
    print(dfs(0, nums, target,0, res, inner))

comboSum([2,3,6,7,8],7)