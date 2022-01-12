def unique(p, n,l, found=False):
    if(n==0):
        if(p not in l and not found):
            return p
        return
    res=unique(p+"0",n-1,l)
    if(res):
        return res
    res=unique(p+"1",n-1,l)
    if(res):
        return res

print(unique("",2,["00","10"]))