#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

//这里定义了StkType类型为char，在1004题，你可能需要修改这里的char型
#define StkType char

struct StkNode{//栈节点
	StkType data;//节点的数据，这里为data
	StkNode *next;//节点的next节点

	//默认构造函数
	StkNode();

	//带参的构造函数
	StkNode(StkType _data, StkNode *_next = NULL);
};

class Stack{//栈声明
private:
	StkNode *top;//栈顶指针，当栈为空的时候，指针为NULL
	int size;//栈里头节点的数目
public:
	//产生一个空栈
	Stack();

	//拷贝另一个栈，要求是当另一个栈修改时不会影响到本栈（这就是所谓的深复制）
	Stack(const Stack &copyStk);

	//析构函数
	~Stack();

	//push压栈实现
	void push(StkType newNodeData);

	//pop出栈，并且把栈顶的数据返回，如果栈是空 返回'\0'
	StkType pop();

	//清空栈
	void clear();

	//获取栈的节点数目
	int getSize() const;

	//获取栈顶的数据，如果栈是空 返回'\0'
	StkType getTop() const;

	//判断栈是否为空
	bool isEmpty() const;

	//打印从栈顶到栈底
	//例如：
	//当栈有5个元素的时候，打印如右：Stack(5): a->c->b->d->e
	//当栈没有元素的时候，打印如有：Stack(0)
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
int Stack::getSize() const{//获取栈的节点数目
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