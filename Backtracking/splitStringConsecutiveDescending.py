# Not correct

def dfs(s,res,partition):
    if(len(s)==0):
        return True
    k=0
    for i in range(len(s)):
        if(s[i]==0):
            k+=1
            continue
        num=int(s[k:i])
        # print(type(num))
        if(len(partition)==0 or partition[-1]==num+1):
            partition.append(num)
            dfs(s[i+1:],res,partition)
            partition.pop()
        else: 
            continue


    return False

def split(s):
    res=[]
    partition=[]

    print(dfs(s,res,partition))

split("4321")
print(int("432")+1)

