#  Given an array and a target. Find number of ways to get the target by adding/ subtracting the array elements

def targetSum(nums, i, target,sum, dp={}):
    if(i==len(nums)):
        return 1 if target==sum else 0

    if( (i,sum) in dp):
        return dp[(i, sum)]

    dp[(i, sum)] = targetSum(nums, i+1, target, sum+nums[i], dp) + targetSum(nums, i+1, target, sum-nums[i], dp)
    return dp[(i,sum)]

    

print(targetSum([1,1,1,1,1],0,3,0))