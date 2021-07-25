#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

//���ﶨ����StkType����Ϊchar����1004�⣬�������Ҫ�޸������char��
#define StkType char

struct StkNode{//ջ�ڵ�
	StkType data;//�ڵ�����ݣ�����Ϊdata
	StkNode *next;//�ڵ��next�ڵ�

	//Ĭ�Ϲ��캯��
	StkNode();

	//���εĹ��캯��
	StkNode(StkType _data, StkNode *_next = NULL);
};

class Stack{//ջ����
private:
	StkNode *top;//ջ��ָ�룬��ջΪ�յ�ʱ��ָ��ΪNULL
	int size;//ջ��ͷ�ڵ����Ŀ
public:
	//����һ����ջ
	Stack();

	//������һ��ջ��Ҫ���ǵ���һ��ջ�޸�ʱ����Ӱ�쵽��ջ���������ν����ƣ�
	Stack(const Stack &copyStk);

	//��������
	~Stack();

	//pushѹջʵ��
	void push(StkType newNodeData);

	//pop��ջ�����Ұ�ջ�������ݷ��أ����ջ�ǿ� ����'\0'
	StkType pop();

	//���ջ
	void clear();

	//��ȡջ�Ľڵ���Ŀ
	int getSize() const;

	//��ȡջ�������ݣ����ջ�ǿ� ����'\0'
	StkType getTop() const;

	//�ж�ջ�Ƿ�Ϊ��
	bool isEmpty() const;

	//��ӡ��ջ����ջ��
	//���磺
	//��ջ��5��Ԫ�ص�ʱ�򣬴�ӡ���ң�Stack(5): a->c->b->d->e
	//��ջû��Ԫ�ص�ʱ�򣬴�ӡ���У�Stack(0)
	void print() const;
};

StkNode::StkNode(){
	data = '\0';
	next = NULL;
}
StkNode::StkNode(StkType _data, StkNode *_next){
	data = _data;
	next = _next;
}

Stack::Stack(){
	top = NULL;
	size = 0;
}

Stack::Stack(const Stack &copyStk){
	top = NULL;
	StkNode *copyTop = copyStk.top, *now;

	size = copyStk.size;
	while (copyTop != NULL){
		if (top == NULL){
			top = now = new StkNode(copyTop->data);
		}else{
			now->next = new StkNode(copyTop->data);
			now = now->next;
		}
		copyTop = copyTop->next;
	}
}
Stack::~Stack(){
	clear();
}

void Stack::clear(){
	StkNode *tmp;
	while (top != NULL){
		tmp = top;
		top = top->next;
		delete tmp;
	}
	top = NULL;
	size = 0;
}
void Stack::push(StkType newNodeData){
	if (top == NULL){
		top = new StkNode(newNodeData);
	}else{
		top = new StkNode(newNodeData, top);
	}
	size++;
}

StkType Stack::pop(){
	if (top == NULL){
		return '\0';
	}
	StkNode *tmp = top;
	StkType res = tmp->data;
	top = top->next;
	size--;
	delete tmp;
	tmp = NULL;
	return res;
}
int Stack::getSize() const{//��ȡջ�Ľڵ���Ŀ
	return size;
}

StkType Stack::getTop() const{
	return (top == NULL) ? '\0' : top->data;
}

bool Stack::isEmpty() const{
	return top == NULL;
}

void Stack::print() const{
	StkNode *tmp = top;
	bool isFirst = true;
	cout << "Stack(" << size << ")"; 
	while (tmp != NULL){
		if (!isFirst){
			cout << "->";
		}else{
			cout << ":";
		}
		cout << tmp->data;
		tmp = tmp->next;
		isFirst = false;
	}
	cout << endl;
}

int main(){
	char str[200];
	int i, n;

	while (scanf("%s", str) != EOF){
		Stack stk;
		n = strlen(str);
		for (i = 0; i < n; ++i){
			if (str[i] == '('){
				stk.push(str[i]);
			}else if (str[i] == ')'){
				if (!stk.isEmpty() && stk.getTop() == '('){
					stk.pop();
				}else{
					stk.push(str[i]);
					break;
				}
			}
		}

		printf("%s\n", (stk.isEmpty() ? "Yes" : "No"));
	}
	return 0;
}