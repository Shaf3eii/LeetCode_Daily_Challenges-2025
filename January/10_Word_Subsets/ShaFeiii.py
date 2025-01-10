class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        freq = [0] * 26
        for word in words2:
            temp = self.countFreq(word)
            for i in range(26):
                freq[i] = max(freq[i], temp[i])

        universal = []
        for word in words1:
            if self.compare(freq, word):
                universal.append(word)

        return universal

    def countFreq(self, word):
        freq = [0] * 26
        for w in word:
            freq[ord(w) - ord('a')] += 1
        return freq

    def compare(self, freq, word):
        freq2 = self.countFreq(word)
        for i in range(26):
            if freq[i] > freq2[i]:
                return False
        return True