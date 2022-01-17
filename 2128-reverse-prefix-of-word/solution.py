class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        pt=0
        for idx,i in enumerate(word):
            if i == ch:
                pt=idx
                break
        return "".join(reversed(word[:pt+1]))+word[pt+1:]
