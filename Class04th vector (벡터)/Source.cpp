#include "Util.h"

template <typename T>
class Vector
{
	int count;
	int capacity;	// 메모리 공간 크기

	T* container;

public:
	Vector() : count(0), capacity(0), container(nullptr) {}
	Vector(int _size, int _capacity) : count(_size), capacity(_capacity) {}
	~Vector()
	{
		if (container != nullptr)
		{

			delete[] container;		// 다 못적어서 보류 
		}
	}

public:
	void resize(int newSize)
	{
		//for문 써야하나..?
		// 1. capacity에 새로운 size값 저장하기
		capacity = newSize;		// 이게 아닌거 같은데 

		// 2. 새로운 포인터 변수를 생성하고 새롭게 만들어진 메모리 공간을 가리키도록 하기
		T* newContainer = new T[newSize];

		// 3. 새로운 메모리 공간의 값 초기화하기
		for (int i = 0; i < capacity; i++)
		{
			newContainer[i] = T();	// NULL도 가능

		}

		// 4. 기존 배열에 있는 값을 복사해서 새로운 배열에 넣어주기 
		for (int i = 0; i < count/* && i < newSize*/; i++)
		{
			newContainer[i] = container[i];
		}

		// 5. 기존 배열의 메모리 해제하기
		if (container != nullptr)
			delete[] container;

		// 6. 기존 배열을 가리키던 포인터 변수의 값을 새로운 배열의 시작 주소로 가리키기 
		container = newContainer;

		/*if (size > newSize)
			size = newSize;*/
			// ?????????????????????????????????????????????????????????????????????
	}

	// 데이터 추가할 때
	void push_back(T data)
	{
		if (capacity < 0)
		{
			resize(1);
		}
		if (count >= capacity)
		{
			resize(capacity * 2);
		}
		container[count++] = data;

	}

	// 연산자 오버로딩(?)
	T& operator [] (const int& count)
	{
		return container[count];

	}

	const int& size()
	{
		return count;
	}

	void pop_back()
	{
		if (count <= 0)
		{
			cout << "vector is empty" << endl;
		}
		else
		{
			container[count--];
			//container[count--] = NULL;
			count = NULL;
		}
	}
};

int main()
{
	Vector<int> vector;
	vector.push_back(10);
	vector.push_back(20);
	vector.push_back(30);

	cout << vector[0] << endl;

	for (int i = 0; i < vector.size(); i++)
	{
		cout << vector[i] << endl;
	}
	return 0;
}
