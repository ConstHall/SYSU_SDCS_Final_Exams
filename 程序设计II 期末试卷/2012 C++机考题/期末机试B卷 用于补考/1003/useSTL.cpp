#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;


int main(){
	char str[200];
	int i, n;

	while (scanf("%s", str) != EOF){
		stack<char> stk;
		n = strlen(str);
		for (i = 0; i < n; ++i){
			if (str[i] == '('){
				stk.push(str[i]);
			}else if (str[i] == ')'){
				if (!stk.empty() && stk.top() == '('){
					stk.pop();
				}else{
					stk.push(str[i]);
					break;
				}
			}
		}

		printf("%s\n", (stk.empty() ? "Yes" : "No"));
	}
	return 0;
}