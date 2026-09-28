#include <vector>

class Solution {
public:
    int reversePairs(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        return mergesort(nums, 0, nums.size() - 1);
    }

    int merger(std::vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int ans = 0;

        std::vector<int> leftVec(n1), rightVec(n2);

        for (int i = 0; i < n1; i++) {
            leftVec[i] = nums[left + i];
        }
        for (int j = 0; j < n2; j++) {
            rightVec[j] = nums[mid + 1 + j];
        }

       
        int j = 0;
        for (int i = 0; i < n1; i++) {
            while (j < n2 && (long long)leftVec[i] > 2LL * rightVec[j]) {
                j++;
            }
            ans += j;
        }

        int i = 0;
        j = 0;
        int k = left;

        while (i < n1 && j < n2) {
            if (leftVec[i] <= rightVec[j]) {
                nums[k++] = leftVec[i++];
            } else {
                nums[k++] = rightVec[j++];
            }
        }

        while (i < n1) {
            nums[k++] = leftVec[i++];
        }
        while (j < n2) {
            nums[k++] = rightVec[j++];
        }

        return ans;
    }

    int mergesort(std::vector<int>& nums, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        int ans = 0;

        ans += mergesort(nums, left, mid);
        ans += mergesort(nums, mid + 1, right);
        ans += merger(nums, left, mid, right);

        return ans;
    }
};