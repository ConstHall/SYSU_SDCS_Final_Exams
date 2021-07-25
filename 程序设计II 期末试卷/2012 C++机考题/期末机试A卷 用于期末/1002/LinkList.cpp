#include <iostream>
#include "LinkList.h"
using namespace std;


//构建一个环形链，例如 1->2->……->size->1（起点），左边的数字为节点的data值
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

//删除环链的第pos个节点，并且返回节点的data
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

//获取第pos个节点的数据
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
