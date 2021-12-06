score=[0, 0, 0, 0, 0]
games=[]

t=int(input()); n=int(input())
ans=0

def dfs(ind):
    global ans
    if ind>=len(games):     # no more games
        possible=True
        for i in range(1, 5):       # check if "t" is the champion
            if i!=t and score[t]<=score[i]:
                possible=False
        
        if possible:
            ans+=1
        return

    score[games[ind][0]]+=3     # team A wins
    dfs(ind+1)
    score[games[ind][0]]-=3

    score[games[ind][1]]+=3     # team B wins
    dfs(ind+1)
    score[games[ind][1]]-=3

    score[games[ind][0]]+=1; score[games[ind][1]]+=1    # tie
    dfs(ind+1)
    score[games[ind][0]]-=1; score[games[ind][1]]-=1


played=[]
for i in range(n):
    a, b, sa, sb=input().split()
    a=int(a); b=int(b); sa=int(sa); sb=int(sb)

    if sa>sb:
        score[a]+=3
    elif sa<sb:
        score[b]+=3
    else:
        score[a]+=1;
        score[b]+=1
    played.append([a, b])

# find unplayed games
for i in range(1, 4):
    for j in range(i+1, 5):
        if [i, j] not in played:
            games.append([i, j])

# start recursion
dfs(0)

print(ans)

"""
3
3
1 3 7 5
3 4 0 8
2 4 2 2
"""