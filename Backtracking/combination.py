def dfs(n,k,res,inner,pos):
    if(k==0):
        res.append(inner.copy())
        return
    for j in range(pos,n):
        inner.append(j+1)
        pos=j
        dfs(n,k-1,res,inner,pos)
        inner.pop()

    return res


print(dfs(4,2,[],[],0))


