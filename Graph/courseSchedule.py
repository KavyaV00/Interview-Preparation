def courseSchedule(pre,num):
    visitSet=set()
    map={ i:[] for i in range(num)}
    for crs,preq in pre:
        map[crs].append(preq)
        visitSet=set()
        def dfs(crs):
            if crs in visitSet:
                return False
            if(map[crs]==True):
                return  True
            visitSet.add(crs)
            for pre in map[crs]:
                if( not dfs(pre)):
                    return False
            visitSet.remove(crs)
            map[crs]=[]
            return True
        for crs in range(num):
            if not dfs(crs):
                return False

        return True

courseSchedule([[0,1], [1,2], [0,2]],3)