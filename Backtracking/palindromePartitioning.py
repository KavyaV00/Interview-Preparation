def isPali(s):
    return s==s[::-1]

def dfs(s, j, res, partition):
    if(len(s)==0):
        res.append(partition.copy())
        return
    for i in range(len(s)):
        if(isPali(s[0:i+1])):
            partition.append(s[0:i+1])
            dfs(s[i+1:],0, res, partition)
            partition.pop()
        

    return res


def partition(s):
    res=[]
    partition=[]
    print(dfs(s,0,res,partition))

partition("aab")