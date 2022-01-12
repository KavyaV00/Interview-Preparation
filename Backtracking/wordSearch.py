def dfs(A,i,j,s):
    if(len(s)==0):
        return True
    if(i<0 or j<0 or i>=len(A) or j>=len(A[0]) or A[i][j]!=s[0]):
        return False

    A[i][j]=''
    print(i,j,s)
    if(dfs(A,i+1,j,s[1:]) or dfs(A,i,j+1,s[1:]) or dfs(A,i-1,j,s[1:]) or dfs(A,i,j-1,s[1:])):
        return True



def wordSearch(A,s):
    m=len(A)
    n=len(A[0])
    for i in range(m):
        for j in range(n):
            if(A[i][j]==s[0]):
                if(dfs(A,i,j,s)):
                    return True

    return False

A=[['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]
print(wordSearch(A,"ABCCED"))