# Fill a large tile of size 2XW using tiles of size 1X2 or 2X1

def tileWays(w):
    if(w<=2):
        return w
    
    return(tileWays(w-1)+tileWays(w-2))


print(tileWays(3))
    