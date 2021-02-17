/* ------------------------------------------------------------------|
��MATLAB�У���һ���ǳ����õĺ��� reshape�������Խ�һ����������Ϊ��һ����С��ͬ���¾��󣬵�������ԭʼ���ݡ�

����һ���ɶ�ά�����ʾ�ľ����Լ�����������r��c���ֱ��ʾ��Ҫ���ع��ľ����������������

�ع���ľ�����Ҫ��ԭʼ���������Ԫ������ͬ���б���˳����䡣

������и���������reshape�����ǿ����Һ���ģ�������µ����ܾ��󣻷������ԭʼ����

ʾ�� 1:

����:
nums =
[[1,2],
 [3,4]]
r = 1, c = 4
���:
[[1,2,3,4]]
����:
�б���nums�Ľ���� [1,2,3,4]���µľ����� 1 * 4 ����, ��֮ǰ��Ԫ��ֵһ��һ������¾���
ʾ�� 2:

����:
nums =
[[1,2],
 [3,4]]
r = 2, c = 4
���:
[[1,2],
 [3,4]]
����:
û�а취�� 2 * 2 ����ת��Ϊ 2 * 4 ���� �������ԭ����
ע�⣺

��������Ŀ�͸߷�Χ�� [1, 100]��
������ r �� c ����������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/reshape-the-matrix
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������|
-------------------------------------------------------------------*/

/*
*
*	ִ����ʱ��8 ms, ������ C++ �ύ�л�����99.55%���û�
*	�ڴ����ģ�10.3 MB, ������ C++ �ύ�л�����94.10%���û�
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    int row = nums.size();
    int col = nums[0].size();
    if (row * col != r * c) {
        return nums;
    }

    vector<vector<int>> res(r, vector<int>(c));
    //for (int x = 0; x < r * c; x++) {
    //    res[x / c][x % c] = nums[x / col][x % col];
    //}
    int p = 0;
    int q = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (q == c) {
                q = 0;
                p++;
            }
            res[p][q++] = nums[i][j];
        }
    }
    return res;
}

int main() {
    vector<vector<int>> nums = { {1,2},{3,4} };
    matrixReshape(nums, 1, 4);
}