#include <iostream>
#include <string.h>
using namespace std;

template<class T>
bool gt(const T& a, const T& b){
	return a > b;
}

template<class T>
bool gt(const T* a, const T* b){
	return *a > *b;
}

template<class T>
bool gt(T* a, T* b){
	return *a > *b;
}

template<>
bool gt(const char* a, const char* b){
	return strcmp(a, b) > 0;
}