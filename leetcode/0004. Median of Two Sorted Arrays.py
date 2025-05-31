class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m = len(nums1)
        n = len(nums2)
        # Merge sort
        def merge():
            # Make new array to hold merged result
            merged = []
            # Make pointers for both arrays
            i, j = 0, 0
            # Merge until one of the arrays is exhausted
            while i < m and j < n:
                if nums1[i] < nums2[j]:
                    merged.append(nums1[i])
                    i += 1
                else:
                    merged.append(nums2[j])
                    j += 1
            # Append remaining elements from either array
            while i < m:
                merged.append(nums1[i])
                i += 1
            while j < n:
                merged.append(nums2[j])
                j += 1
            return merged
        merged = merge()
        total_length = m + n
        if total_length % 2 == 0:
            mid1 = total_length // 2 - 1
            mid2 = total_length // 2
            return (merged[mid1] + merged[mid2]) / 2.0
        else:
            mid = total_length // 2
            return merged[mid]
        