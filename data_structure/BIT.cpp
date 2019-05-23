// Add(x, d) 让A(x)增加d
// Query(L, R) 计算A(L) + A(L+1) ... + A(R)
// Binary Index Tree(树状数组): 预处理: O(nlogn), add和query: O(logn)


int lowbit(x) {
    return x&-x;
}

// 前缀和
int sum(int x) {
    int ret = 0;
    while (x > 0) {
        ret += C[x];
        x -= lowbit(x);
    }
    return ret;
}

// 预处理执行n次add
int add(int x, int d) {
    while (x <= n) {
        C[x] += d;
        x += lowbit(x);
    }
}

// 包含l, r
int query(int l, int r) {
    return sum(r) - sum(l-1);
}



/*
example: leetcode 307

307. Range Sum Query - Mutable

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
1. The array is only modifiable by the update function.
2. You may assume the number of calls to update and sumRange function is distributed evenly.
*/

class NumArray {
private:
    int sz;
    vector<int> num;
    vector<int> sum;
    int lowbit(int x) {
        return x&-x;
    }

    int prefix_sum(int i) {
        int ret = 0;
        while(i > 0) {
            ret += sum[i];
            i -= lowbit(i);
        }
        return ret;
    }
public:
    NumArray(vector<int>& nums) {
        sz = nums.size();
        num = vector<int>(sz+1, 0);
        sum = vector<int>(sz+1, 0);
        for (int i = 0; i < sz; i++) {
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int cur = ++i;
        int t = num[i];
        while (i <= sz) {
            sum[i] = sum[i] - t + val;
            i += lowbit(i);
        }
        num[cur] = val;
    }
    
    int sumRange(int i, int j) {
        return prefix_sum(j+1) - prefix_sum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
