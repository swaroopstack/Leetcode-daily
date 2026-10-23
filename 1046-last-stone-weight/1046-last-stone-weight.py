class Solution:
    def lastStoneWeight(self, stones: list[int]) -> int:
        pq =[]
        for x in stones:
            heapq.heappush(pq,-x)
        
        while len(pq)>1 :
            first=-heapq.heappop(pq)
            second=-heapq.heappop(pq)
            if first != second:
                heapq.heappush(pq,-(first-second))
        
        if len(pq)==0:
            return 0

        return -pq[0]
        