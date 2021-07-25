#include <stdio.h>

bool DFS(int a[], int d){
	if (d == 1){
		return a[0] == 24;
	}

	int* b = new int[d-1];
	int _max, _min, c;
	for (int i = 0; i < d; ++i){
		for (int j = 0; j < d; ++j){
			if (i == j)
				continue;

			c = 0;
			for (int k = 0; k < d; ++k){
				if (k != i && k != j)
					b[c++] = a[k];
			}

			_max = a[i] > a[j] ? a[i] : a[j];
			_min = a[i] <= a[j] ? a[i] : a[j];

			//加法
			b[d-2] = _max + _min;
			if (DFS(b, d-1))
				return true;
			
			//减法
			b[d-2] = _max - _min;
			if (DFS(b, d-1))
				return true;
			
			//乘法
			b[d-2] = _max * _min;
			if (DFS(b, d-1))
				return true;

			//除法
			if (_min != 0 && _max % _min == 0){
				b[d-2] = _max / _min;
				if (DFS(b, d-1))
					return true;
			}
		}
	}
	delete[] b;

	return false;
}

int main(){
	int a[4];
	while (scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]) != EOF){
	
		if (DFS(a, 4)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}