#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread; //���� ������ ��ũ�� �������̸� TRUE
} TreeNode;

TreeNode* find_successor(TreeNode* p)
{
	// q�� p�� ������ ������
	TreeNode* q = p->right;
	// ���� ������ �����Ͱ� NULL�̰ų� �������̸� ������ �����͸� ��ȯ
	if (q == NULL || p->is_thread == 1)
		return q;

	// ���� ������ �ڽ��̸� �ٽ� ���� ���� ���� �̵�
	while (q->left != NULL) q = q->left;
	return q;
}
void thread_inorder(TreeNode* t)
{
	TreeNode* q;
	q = t;
	while (q->left) q = q->left;// ���� ���� ���� ����.
	do
	{
		printf("%d ", q->data);// ������ ���
		q = find_successor(q); // �ļ��� �Լ� ȣ��
	} while (q);			// NULL�� �ƴϸ�
}

//		  1
//	  2		  7
//  3   6   8    9
//4   5        10 11 
TreeNode n1 = { 4, NULL, NULL,true };
TreeNode n2 = { 5, NULL, NULL,true };
TreeNode n3 = { 3, &n1, &n2,0 };
TreeNode n4 = { 6, NULL, NULL,true };
TreeNode n5 = { 2, &n3, &n4,0 };
TreeNode n6 = { 8, NULL, NULL,true };
TreeNode n7 = { 10, NULL, NULL,true };
TreeNode n8 = { 11, NULL, NULL,0 };
TreeNode n9 = { 9, &n7, &n8,true };
TreeNode n10 = { 7, &n6, &n9,0 };
TreeNode n11 = { 1, &n5, &n10,0 };
TreeNode* root = &n11;

TreeNode n1.right = &n3;
int main() {
	n1.right = &n3;
	n2.right = &n5;
	n4.right = &n11;
	n6.right = &n10;
	n9.right = &n11;
	n7.right = &n9;
	TreeNode* root = &n11;
	thread_inorder(root);
	return 0;
}