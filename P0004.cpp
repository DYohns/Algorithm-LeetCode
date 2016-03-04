/*
ID: 4 Median of Two Sorted Arrays
Problem: ��������������飬�ҳ����Ǻϲ������ֵ��Ҫ��ʱ�临�Ӷ�O(log(m+n))
Tips: 
	1. O(m+n): ��ֵ�ڵ�kλ����ͨ����ͷ��β���ϱȽ�˫������Ԫ�ش�С��С����ֵ��Ϊ�����飬ֱ�������鵽���Kλ
	2. O(log(m+n)): ������ת��Ϊ���kλ����ֵ�������������鳤�Ⱦ�����k/2����ȡa[k/2]��b[k/2]���бȽϣ�
		��a[k/2]<b[k/2]��������a��ǰk/2λ�������������Ƚϣ�ͬ��a[k/2]>b[k/2]��������b��ǰk/2λ����������
		��a[k/2]=b[k/2]����ȡa[k/2]��b[k/2]���ɡ�
		ϸ���л����ж�����������������һ�����鳤��С��k/2�ȡ�
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
	*	m,n: ����a,b��Ч�Ƚϵ���ʼλ������
	*	k: �����kλ����ֵ����0��ʼ
	*/
	int findKth(int m, int n, vector<int> nums1, vector<int> nums2, int k) {
		int size_a = nums1.size() - m;
		int size_b = nums2.size() - n;
		if (size_a > size_b) { // ʼ�ձ�֤����a�ĳ���С������b�ĳ���
			return findKth(n, m, nums2, nums1, k);
		}
		if (size_a == 0) {	// ����aԪ��ȫ��С������b��ֻ��Ҫȡ������b�еĵ�kλ����ֵ����
			return nums2[n + k];
		}
		if (k == 0) {	// ʣ��һλ��ֻҪ����������ĵ�һλ���бȽ��������
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
		else { // ���ʱ�迼��ɾ���������鲻���Ƚϵĳ��Ⱥ��Ƿ�ʣ��һ��Ԫ��
			if (k - index - u - 1 == 0) {
				return val_a;
			}
			else {
				return findKth(m + index + 1, n + u + 1, nums1, nums2, k - index - u - 2);
			}
		}
	}
};