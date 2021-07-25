#include <iostream>
#include "LinkList.h"
using namespace std;


//����һ�������������� 1->2->����->size->1����㣩����ߵ�����Ϊ�ڵ��dataֵ
LinkList::LinkList(int _size){
	int i;
	LinkListNode *nowNode;

	size = _size;
	i = 0;
	nowNode = head = new LinkListNode(i+1);
	for (i = 1; i < size; ++i){
		nowNode->next = new LinkListNode(i+1);
		nowNode = nowNode->next;
	}
}

//ɾ�������ĵ�pos���ڵ㣬���ҷ��ؽڵ��data
int LinkList::delNode(int pos){
	if (pos > size || pos <= 0){
		return -1;
	}
	LinkListNode *toDelNode = head, *pre = NULL;
	int i, res;
	for (i = 1; i < pos; ++i){
		pre = toDelNode;
		toDelNode = toDelNode->next;
	}
	if (toDelNode == head){
		head = head->next;
	}else{
		pre->next = toDelNode->next;
	}
	res = toDelNode->data;
	delete toDelNode;
	size--;
	return res;
}

//��ȡ��pos���ڵ������
int LinkList::getNodeData(int pos) const{
	if (pos > size || pos <= 0){
		return -1;
	}
	LinkListNode *nowNode = head;
	int i;
	for (i = 1; i < pos; ++i){
		nowNode = nowNode->next;
	}
	return nowNode->data;
}
int LinkList::getSize() const{
	return size;
}
void LinkList::print() const{
	LinkListNode *tmp = head;
	int i;

	for (i = 0; i < size; ++i){
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
