
def findPerm( A, B):
    res=[1]

    def dfs(s,n,res,l=[1]):
        if(s==""):
            print(l)
            return True
        # print(l)
        if(s[0]=='I'):
            j=l[-1]
            if(j+1>n or j+1 in l):
                return False
            # print(l.append(j+1))
            l.append(j+1)
            while(not dfs(s[1:],n,l)):
                l[-1]+=1
            return True

        else:
            j=l[-1]
            if(j-1<0 or j-1 in l):
                return False
            l.append(j-1)
            while(not dfs(s[1:],n,l)):
                l[-1]-=1
            # print(l)
            return True
            

    ans=dfs(A,B,res)

print(findPerm("ID",3))
