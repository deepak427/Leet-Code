class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dictMap = {}
        for i in range(len(nums)):
            if (target-nums[i]) in dictMap.keys():
                if i != dictMap.get(target-nums[i]):
                    return [i, dictMap.get(target-nums[i])]
            else:
                dictMap[nums[i]] = i
        
        