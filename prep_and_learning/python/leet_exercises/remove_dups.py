


class Solution:
    def removeDuplicates(self, nums:list) -> int:
        number_of_deletions = 0
        length = len(nums)
        i = 0

        while i < length:
            if i+1 < length and nums[i] == nums[i+1]:
                # we have a duplicate now
                # find more duplicates for the same value
                j = i+1
                while j < length and nums[i] == nums[j]:
                    nums.pop(j)
                    length-=1

            i+=1
        return length


if __name__ == "__main__":

    input_data = [1,1,2,3,3,3,4,5,5,5,5,6,6,7,8,9,9,10,10]
    print(input_data)
    Solution().removeDuplicates(input_data)
    print(input_data)