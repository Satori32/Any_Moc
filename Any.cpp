#include "Any.h"

int C(char* A, char* B, size_t L) {
	return memcmp(A, B, L);
}

Any ConstructAny(Any& In) {
	Any A;
	A.P = Duplicate(In.P);
	A.S = In.S;
	return A;
}

template<class T>
Any ConstructAny(const T& In) {
	Any A;
	A.P = ConstructMemory<char>(sizeof(T) + 1);
	A.S = sizeof(T);
	Set(A.P, In);
	A.Comp = C;

	return A;
}
template<class T>
Any ConstructAny(const T& In, int (*F)(char* A, char* B, size_t L)) {
	Any A;
	A.P = ConstructMemory<char>(sizeof(T) + 1);
	A.S = sizeof(T);
	Set(A.P, In);
	A.Comp = F;

	return A;
}

bool Free(Any& In) {
	Free(In.P);
	In.S = 0;

	return true;
}

template<class T>
T* Get(Any& In) {
	if (sizeof(T) != In.S) { return NULL; }
	return (T*)GETPointer(In.P);
}
template<class T>
T Max(T A, T B) {
	return A > B ? A : B;
}
int Comp(Any& In, Any& B) {
	return In.Comp(GETPointer(In.P), GETPointer(B.P), In.S);
}
template<class T>
int Comp(Any& In, T& B) {
	return In.Comp(GETPointer(In.P), (char*)&B,in.S);
}