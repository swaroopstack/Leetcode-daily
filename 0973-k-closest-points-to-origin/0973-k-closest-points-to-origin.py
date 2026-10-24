class Solution:
    def kClosest(self, points: list[list[int]], k: int) -> list[list[int]]:
        ans=[]
        pq=[]
        mp={}
        for row in points:
            dist=((row[0]-0)*(row[0]-0))+((row[1]-0)*(row[1]-0))
            dist=sqrt(dist)
            heapq.heappush(pq,dist)
            if dist not in mp:
                mp[dist]=[]
            mp[dist].append([row[0],row[1]])

        while k:
            dist=heapq.heappop(pq)
            k-=1
            ans.append(mp[dist].pop())
            
        return ans