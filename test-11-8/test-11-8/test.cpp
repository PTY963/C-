#define _CRT_SECURE_NO_WARNINGS 1
//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x)
		:val(x)
		,next(nullptr)
	{}
};
class Sloution
{
public:
	//迭代
	ListNode* Merge1(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;

		ListNode* head = nullptr;//新链表的头
		ListNode* tail = nullptr;//新链表的尾

		while (pHead1 && pHead2)
		{
			//p - 要插入新链表的目标结点
			ListNode* p = pHead1->val > pHead2->val ? pHead2 : pHead1;
			if (p == pHead1) {
				pHead1 = pHead1->next;//在原链表中删除目标结点
			}
			else {
				pHead2 = pHead2->next;
			}

			if (head == nullptr) {
				head = tail = p;
			}
			else {
				tail->next = p;
				tail = tail->next;
			}
		}
		//跳出while循环后有三种情况
		//1、pHead1=nullptr 2、pHead2=nullptr 3、都为空
		if (pHead1 == nullptr)
			tail->next = pHead2;
		else
			tail->next = pHead1;

		return head;
	}

	//递归
	ListNode* Merge2(ListNode* pHead1, ListNode* pHead2)
	{
		//递归出口
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;

		ListNode* head = nullptr;//新链表的头

		if (pHead1->val > pHead2->val) {
			head = pHead1;
			pHead1 = pHead1->next;
		}
		else {
			head = pHead2;
			pHead2 = pHead2->next;
		}

		head->next = Merge2(pHead1, pHead2);
		return head;
	}
};


struct TreeNode
{
	int val; 
	struct TreeNode* left; 
	struct TreeNode* right; 
	TreeNode(int x)
		: val(x)
		, left(nullptr)
		, right(nullptr)
	{ }
};
class Solution2 
{
public:
	void Mirror(TreeNode* pRoot){
		if (pRoot == nullptr)
			return;

		//程序走到这里说明树不为空，交换这棵树的左右子树
		TreeNode* temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;

		Mirror(pRoot->left);
		Mirror(pRoot->right);

	}
};

