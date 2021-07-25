#include <iostream>
using namespace std;

#ifndef LIST
#define LIST
struct LinkListNode{//链表节点
	int data;//当前节点数据
	LinkListNode *next;//下一个节点

	LinkListNode(int _data){
		data = _data;
		next = NULL;
	}

	LinkListNode(int _data, LinkListNode *_next){
		data = _data;
		next = _next;
	}
};

class LinkList{
public:
	//构建一个单向无环链，例如 1->2->……->size，左边的数字为节点的data值，不考虑size小于0的情况
	LinkList(int _size);

	//删除单向无环链的第pos个节点，并且返回节点的data，如果删除的节点是头节点，删除后，则头结点更新为它的next节点
	//pos > size || pos <= 0时，返回-1
	//pos <= size时，删除第pos个节点，并返回它的值，从1开始计数
	int delNode(int pos);

	//获取第pos个节点的数据
	//pos > size || pos <= 0时，返回-1
	//pos <= size时，返回第pos个节点的值，从1开始计数
	int getNodeData(int pos) const;
	
	//获取当前链表的大小
	int getSize() const;

	//打印当前链表，
	//链表为空 打印一个空行
	//链表不为空 按照顺序打印节点的data，每个值后边都有空格，最后再换行，如：1 2 3 4 
	void print() const;

	//析构函数 用于销毁资源
	~LinkList(){
		LinkListNode *tmp;
		while (head != NULL){
			tmp = head;
			head = head->next;
			delete tmp;
		}
		size = 0;
		head = NULL;
	}
private:
	int size;//链表大小
	LinkListNode *head;//头指针，链表为空时，head等于NULL;
};
#endif


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
