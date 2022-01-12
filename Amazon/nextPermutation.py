def nextPerm(nums):

    def swap(l, i, j):
        temp=l[i]
        l[i]=l[j]
        l[j]=temp
    if(len(nums)==0):
        return 

    for i in range(len(nums)-1, -1,-1):
        if(nums[i]>nums[i-1]):
            pos=i
            break
    print(pos)
    if(i==-1):
        nums.sort()
        print(nums)
        return

    prev=pos-1
    index=pos
    print(prev, index)
    for i in range(pos+1, len(nums)):
        if(nums[i]>nums[prev] and nums[i]<nums[pos]):
            index=i
    # print(index, nums[index])
    swap(nums,prev,index)
    # print(sorted(nums[index+1:]))
    nums=nums[:index]+sorted(nums[index:])
    # print(nums)
    return

nextPerm([1,2,3,4,3,2,3,4,2])
l=[4,3,2,1]
l.sort()
# print(l)
# 