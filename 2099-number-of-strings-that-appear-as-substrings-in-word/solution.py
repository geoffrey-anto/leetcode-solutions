class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        c=0
        for pattern in patterns:
            for i in range(len(word)-len(pattern)+1):
                if word[i:i+len(pattern)] == pattern:
                    c+=1
                    break
                
        return c
