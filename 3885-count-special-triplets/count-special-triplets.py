class Solution:
    def specialTriplets(self, a: List[int]) -> int:
        f = lambda a,z:[(z[v*2],z.update([v]))[0] for v in a]
        return sum(map(mul,f(a,Counter()),f(a[::-1],Counter())[::-1]))%(10**9+7)