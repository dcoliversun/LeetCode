# @LeetCode两数相加--Add Two Numbers[C++]
# 问题描述
给出两个**非空**的链表用来表示两个非负的整数。其中，它们各自的位数是按照**逆序**的方式存储的，并且它们的每个节点只能存储**一位**数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字0之外，这两个数都不会以0开头。

**示例：**

> **输入：** (2 -> 4 -> 3) + (5 -> 6 -> 4)
> **输出：** 7 -> 0 -> 8
> **原因：** 342 + 465 = 807
# 解题方法及复杂度分析 
## 问题分析
加法涉及到两种情况，一是加数的位数**相同**，二是加数的位数**不同**。在链表中，加数的最高位结点之后的结点是个**空结点**，这意味着必须**两个链表均访问到尾部的空结点**加法才可以停止。

同时，我们需要使用变量来跟踪进位。

![位数相同的加数相加示意图](https://img-blog.csdnimg.cn/20190103224252571.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzM0MDk0Mw==,size_16,color_FFFFFF,t_70)
<div align=center>图1-1 位数相同的加数相加示意图</div>

![位数不同的加数相加示意图](https://img-blog.csdnimg.cn/20190103231215903.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MzM0MDk0Mw==,size_16,color_FFFFFF,t_70)
<div align=center>图1-2 位数不同的加数相加示意图</div>

## 伪代码
- 将当前结点初始化为返回列表的哑结点。
- 将进位 carry 初始化为0。
- 遍历列表 l1 和 l2 直至到达它们的尾端。
-- 将 x 设为 l1 列表中结点的值。如果 l1 已经到达末尾，则将其值设置为0。
-- 将 y 设为 l2 列表中结点的值。如果 l2 已经到达末尾，则将其值设置为0。
-- 设定 sum = x + y + carry。
-- 更新进位的值，carry = sum / 10。
-- 创建一个数值为 (sum mod 10) 的新结点，并将其设置为当前结点的下一个结点，然后将当前结点前进到下一个结点。
-- 同时，将 l1 和 l2 前进到下一个结点。
- 检查 carry = 1 是否成立，如果成立，则向返回列表追加一个含有数字1的新结点。
- 返回哑结点的下一个结点。

## 程序实现

```cpp
	/**
 	* Definition for singly-linked list.
 	* struct ListNode {
 	*     int val;
 	*     ListNode *next;
 	*     ListNode(int x) : val(x), next(NULL) {}
 	* };
 	*/
	class Solution {
	public:
	    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	        ListNode* p = new ListNode(0);
	        ListNode* q = p;
	        int carry = 0;
	        while (l1 != NULL || l2 != NULL) {
	            int x = (l1 != NULL) ? l1->val : 0;
	            int y = (l2 != NULL) ? l2->val : 0;
	            int sum = x + y + carry;
	            carry = sum / 10;
	            p->next = new ListNode(sum % 10);
	            p = p->next;
	            if (l1 != NULL) l1 = l1->next;
	            if (l2 != NULL) l2 = l2->next;
	        }
	        if (carry) p->next = new ListNode(carry);
	        return q->next;
	    }
	};
```
## 复杂度分析
### 时间复杂度
O(max(m,n))，假设 m 和 n 分别表示 l1 和 l2 的长度，上面的算法最多重复 max(m,n) 次。
### 空间复杂度
O(max(m,n))， 新列表的长度最多为 max⁡(m,n)+1。

@北京·怀柔 2019.01.04
