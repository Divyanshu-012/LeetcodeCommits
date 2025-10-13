class Solution:
    def anagram(self, words, idx):
        alpha = [0] * 26

        for ch in words[idx]:
            alpha[ord(ch) - ord('a')] += 1

        if len(words[idx - 1]) != len(words[idx]):
            return False

        for ch in words[idx - 1]:
            alpha[ord(ch) - ord('a')] -= 1

        for count in alpha:
            if count != 0:
                return False

        return True

    def removeAnagrams(self, words):
        i = len(words) - 1
        while i > 0:
            if self.anagram(words, i):
                words.pop(i)  
            i -= 1
        return words
