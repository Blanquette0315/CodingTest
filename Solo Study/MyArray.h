#pragma once

template<typename T>
class MyArray
{
private:
	T* _pData;
	int MaxCount;
	int iCurCount;

	//생성자 소멸자
public:
	MyArray()
		: _pData(nullptr), MaxCount(2), iCurCount(0)
	{
		_pData = new T[MaxCount];
	}

	~MyArray()
	{
		delete[_pData];
	}

	// MyArray 함수들 전방 선언
public:
	T push_back(T Data);
	void Realloc();

	// operator overloding
public:
	T& operator [](int _idx);
};

// MyArray 함수 정의

template<typename T>
void MyArray<T>::Realloc()
{
	MaxCount *= 2;
	T* p_NewData = new T[MaxCount];
	for (int i = 0; i < iCurCount; ++i)
	{
		p_NewData[i] = _pData[i];
	}
	delete[_pData];
	_pData = p_NewData;
}

template<typename T>
T MyArray<T>::push_back(T Data)
{
	if (MyArray<T>::iCurCount >= MyArray<T>::MaxCount)
	{
		Realloc()
	}
	_pData[++iCurCount] = Data;
}

