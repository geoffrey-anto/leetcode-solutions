class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        st = set({})
        code = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        for word in words:
            trans = ""
            for char in word:
                trans=trans+code[ord(char)-97]
            st.add(trans)
        return len(st)