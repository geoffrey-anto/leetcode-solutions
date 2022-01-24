class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        broken = set(list(brokenLetters))
        res = 0
        for word in text.split(" "):
            validWord = True
            for w in word:
                if w in broken:
                    validWord = False
                    break
            if validWord:
                    res+=1
        return res