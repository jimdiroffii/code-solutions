### 1822. Sign of the Product of an Array

There is a function signFunc(x) that returns:

```text
1 if x is positive.
-1 if x is negative.
0 if x is equal to 0.
```

You are given an integer array nums. Let product be the product of all values in the array nums.

Return signFunc(product).

**Example 1:**

```text
Input: nums = [-1,-2,-3,-4,3,2,1]
Output: 1
Explanation: The product of all values in the array is 144, and signFunc(144) = 1
```

**Example 2:**

```text
Input: nums = [1,5,0,2,-3]
Output: 0
Explanation: The product of all values in the array is 0, and signFunc(0) = 0
```

**Example 3:**

```text
Input: nums = [-1,1,-1,1,-1]
Output: -1
Explanation: The product of all values in the array is -1, and signFunc(-1) = -1
```

**Constraints:**

```text
1 <= nums.length <= 1000
-100 <= nums[i] <= 100
```
