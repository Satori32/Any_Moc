#pragma once
#include <stdio.h>

#include "MemoryAllocator.h"

struct Any {
	Memory<char> P;
	size_t S = 0;

	int (*Comp)(char*, char*, size_t);
};

template<class T> Any ConstructAny(const T& In);
template<class T> Any ConstructAny(const T& In, int (*F)(char* A, char* B, size_t L));
bool Free(Any& In);
template<class T> T* Get(Any& In);