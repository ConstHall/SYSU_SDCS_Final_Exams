#include <iostream>
using namespace std;

struct LinkListNode{//����ڵ�
	int data;//��ǰ�ڵ�����
	LinkListNode *next;//��һ���ڵ�

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
	//����һ�������޻��������� 1->2->����->size����ߵ�����Ϊ�ڵ��dataֵ��������sizeС��0�����
	LinkList(int _size);

	//ɾ�������޻����ĵ�pos���ڵ㣬���ҷ��ؽڵ��data�����ɾ���Ľڵ���ͷ�ڵ㣬ɾ������ͷ������Ϊ����next�ڵ�
	//pos > size || pos <= 0ʱ������-1
	//pos <= sizeʱ��ɾ����pos���ڵ㣬����������ֵ����1��ʼ����
	int delNode(int pos);

	//��ȡ��pos���ڵ������
	//pos > size || pos <= 0ʱ������-1
	//pos <= sizeʱ�����ص�pos���ڵ��ֵ����1��ʼ����
	int getNodeData(int pos) const;
	
	//��ȡ��ǰ����Ĵ�С
	int getSize() const;

	//��ӡ��ǰ����
	//����Ϊ�� ��ӡһ������
	//����Ϊ�� ����˳���ӡ�ڵ��data��ÿ��ֵ��߶��пո�����ٻ��У��磺1 2 3 4 
	void print() const;

	//�������� ����������Դ
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
	int size;//�����С
	LinkListNode *head;//ͷָ�룬����Ϊ��ʱ��head����NULL;
};