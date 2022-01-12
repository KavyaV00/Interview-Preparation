
    # Find lenght of longest subarray by changing max of k characters.
    # Approach - Sliding window
    # if len(window) - max count <= k, r++
    # else, count a[l] -- and l++ till the condition is satisfied.

def findLongest(s, k):
    count = {}
    l=0
    r=0
    max_count=0
    while(l<=r and r<len(s)):
        if(s[r] in count):
            count[s[r]]+=1
        else:
            count[s[r]]=1
        window=r-l+1
        print(l, r, count)
        for i in count:
            max_count = max(max_count, count[i])
        print(max_count)
        while(window - max_count > k):
            count[s[l]]-=1
            l+=1
            window=r-l+1
            for i in count:
                max_count = max(max_count, count[i])
        
        r+=1
            
        print(window)
        
        pass
    pass

findLongest("ABABBA",2)
