def dfs(nums, count, res, perm=[]):
    if(len(perm)==len(nums)):
        res.append(perm.copy())
        return
    for n in count:
        if(count[n]>0):
            count[n]-=1
            perm.append(n)
            dfs(nums,count,res,perm)
            count[n]+=1
            perm.pop()

def permute(nums):
    res=[]
    count={ n:0 for n in nums}
    for n in nums:
        count[n]+=1
    dfs(nums, count, res)
    return res

print(permute([1,1,2]))