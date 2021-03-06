/*
题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        std::vector<int> v;
        int n = array.size();

        for (int i = 0; i < n; ++i) {
        	if ((array[i] & 0x1) == 1) {
        		v.push_back(array[i]);
        	}
        }

        for (int i = 0; i < n; ++i) {
        	if ((array[i] & 0x1) == 0) {
        		v.push_back(array[i]);
        	}
        }

        array = v;
    }
};