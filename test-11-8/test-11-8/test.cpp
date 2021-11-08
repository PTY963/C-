#define _CRT_SECURE_NO_WARNINGS 1
//���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
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
	//����
	ListNode* Merge1(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;

		ListNode* head = nullptr;//�������ͷ
		ListNode* tail = nullptr;//�������β

		while (pHead1 && pHead2)
		{
			//p - Ҫ�����������Ŀ����
			ListNode* p = pHead1->val > pHead2->val ? pHead2 : pHead1;
			if (p == pHead1) {
				pHead1 = pHead1->next;//��ԭ������ɾ��Ŀ����
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
		//����whileѭ�������������
		//1��pHead1=nullptr 2��pHead2=nullptr 3����Ϊ��
		if (pHead1 == nullptr)
			tail->next = pHead2;
		else
			tail->next = pHead1;

		return head;
	}

	//�ݹ�
	ListNode* Merge2(ListNode* pHead1, ListNode* pHead2)
	{
		//�ݹ����
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;

		ListNode* head = nullptr;//�������ͷ

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

		//�����ߵ�����˵������Ϊ�գ��������������������
		TreeNode* temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;

		Mirror(pRoot->left);
		Mirror(pRoot->right);

	}
};

