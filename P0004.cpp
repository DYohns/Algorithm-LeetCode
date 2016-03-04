/*
ID: 4 Median of Two Sorted Arrays
Problem: 两个有序递增数组，找出它们合并后的中值，要求时间复杂度O(log(m+n))
Tips: 
	1. O(m+n): 中值在第k位，则通过从头到尾不断比较双方数组元素大小，小的数值归为新数组，直到新数组到达第K位
	2. O(log(m+n)): 将问题转化为求第k位的数值，假设两个数组长度均大于k/2，则取a[k/2]与b[k/2]进行比较，
		若a[k/2]<b[k/2]，则数组a中前k/2位可以抛弃不做比较，同理a[k/2]>b[k/2]，则数组b中前k/2位可以抛弃，
		若a[k/2]=b[k/2]，则取a[k/2]或b[k/2]即可。
		细节中还需判断其他条件，如其中一个数组长度小于k/2等。
*/
#include <iostream>
#include <vector>
#define min(x, y) x < y ? x : y
using namespace std;

class Solution {
private:
	int mid_a, mid_b;
	vector<int> nums1, nums2;

public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int k = (nums1.size() + nums2.size() - 1) / 2;
		cout << k << endl;
		int mid1 = findKth(0, 0, nums1, nums2, k);
		int mid2 = mid1;
		if ((nums1.size() + nums2.size()) % 2 == 0) {
			mid2 = findKth(0, 0, nums1, nums2, k + 1);
		}
		return (mid1 + mid2) * 1.0 / 2;
	}
	/*
	*	m,n: 数组a,b有效比较的起始位的索引
	*	k: 求出第k位的数值，从0开始
	*/
	int findKth(int m, int n, vector<int> nums1, vector<int> nums2, int k) {
		int size_a = nums1.size() - m;
		int size_b = nums2.size() - n;
		if (size_a > size_b) { // 始终保证数组a的长度小于数组b的长度
			return findKth(n, m, nums2, nums1, k);
		}
		if (size_a == 0) {	// 数组a元素全部小于数组b，只需要取出数组b中的第k位的数值即可
			return nums2[n + k];
		}
		if (k == 0) {	// 剩下一位，只要对两个数组的第一位进行比较输出即可
			return min(nums1[m], nums2[n]);
		}
		int u = (k - 1) / 2;

		int index = min(size_a - 1, u);
		int val_a = nums1[m + index];
		int val_b = nums2[n + u];
		if (val_a > val_b) {
			return findKth(m, n + u + 1, nums1, nums2, k - u - 1);
		}
		else if (val_a < val_b) {
			return findKth(m + index + 1, n, nums1, nums2, k - index - 1);
		}
		else { // 相等时需考虑删除两个数组不做比较的长度后是否还剩下一个元素
			if (k - index - u - 1 == 0) {
				return val_a;
			}
			else {
				return findKth(m + index + 1, n + u + 1, nums1, nums2, k - index - u - 2);
			}
		}
	}
};