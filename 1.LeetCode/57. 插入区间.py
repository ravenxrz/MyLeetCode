from typing import List


class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        # check is intervals is empty
        if len(intervals) == 0:
            return [newInterval]

        ans = []
        end_idx = len(intervals)
        for idx, (a, b) in enumerate(intervals):
            if newInterval[1] < a:
                end_idx = idx
                break
            # intersects with newInterval?
            if not newInterval[0] > b and not newInterval[1] < a:
                newInterval = [min(a, newInterval[0]), max(b, newInterval[1])]
            else:
                ans.append(intervals[idx])

        ans.append(newInterval)
        ans.extend(intervals[end_idx:])
        return ans


if __name__ == '__main__':
    sol = Solution()
    intervals = [[1, 3], [6, 9]]
    newIntervals = [2, 5]
    print(sol.insert(intervals, newIntervals))

    intervals = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]]
    newIntervals = [4, 8]
    print(sol.insert(intervals, newIntervals))

    intervals = []
    newIntervals = [5, 7]
    print(sol.insert(intervals, newIntervals))

    intervals = [[1, 5]]
    newIntervals = [2, 7]
    print(sol.insert(intervals, newIntervals))

    intervals = [[1, 5]]
    newIntervals = [5, 7]
    print(sol.insert(intervals, newIntervals))

    intervals = [[1, 5], [6, 8]]
    newIntervals = [5, 6]
    print(sol.insert(intervals, newIntervals))
