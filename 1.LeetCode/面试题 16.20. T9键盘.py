from typing import List

"""
DFS solution
class Solution:
    alphabet_dict = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz"
    }

    ans = []

    def getValidT9Words(self, num: str, words: List[str]) -> List[str]:
        Solution.ans.clear()
        self.__dfs(num, set(words), 0, [])
        return Solution.ans

    def __dfs(self, num: str, words: set[str], idx: int, cur_word: List[str]):
        if idx == len(num):
            word = "".join(cur_word)
            if word in words:
                Solution.ans.append(word)
            return
        saver = set()
        for c in Solution.alphabet_dict[num[idx]]:
            saver.clear()
            # exclude words that not contain c
            for word in words:
                if word[idx] != c:
                    saver.add(word)
            words = words.difference(saver)
            if len(words) != 0:
                cur_word.append(c)
                self.__dfs(num, words, idx + 1, cur_word)
                cur_word.pop()
            # recovery
            words = words.union(saver)

"""


class Solution:
    alphabet_dict = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz"
    }

    def getValidT9Words(self, num: str, words: List[str]) -> List[str]:
        words = set(words)
        saver = set()
        for idx, n in enumerate(num):
            saver.clear()
            for word in words:
                if word[idx] not in Solution.alphabet_dict[n]:
                    saver.add(word)
            words = words.difference(saver)
        return list(words)

if __name__ == '__main__':
    sol = Solution()
    num = "73328962353432379245754568346322723396359744563667"
    words = ["iujxuizfnulgrdnowzxndjakvhsqguxvnytgjujnnktmokawdp", "rfebuxncdleidbepwaijskgjotdinebaqceezoejyrhgjofnmr",
             "qddatwmceldhfafqxcikpkijovfgofabradfznejxshikneonp", "rysuauovdqmwdyorrlpjzuechbjknndfpfcwgjnptmxnixtuqm",
             "qeeauwnbdkeiecdpzbijslhjmudgmeacqcddzmdkyshikmdmns", "vqqcntpgqgxyqshdtnyyxbytzwllhxrnaqwzfsswgqnabdxawf"]
    print(sol.getValidT9Words(num, words))
