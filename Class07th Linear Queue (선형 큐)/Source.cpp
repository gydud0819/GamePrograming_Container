#include "Util.h"
#define SIZE 5		
// 선형 큐
// 또 틀렷서? ㅠ
// 선형 큐의 한계 :  공간이 NULL로 채워지기 때문에 비우고나서 다시 값을 할당할 수 없다? 
template <typename T>
class Queue
{
private:
	int front;		// 앞에 추가? 
	int rear;		// 뒤에 추가? 
	T container[SIZE];


public:
	Queue() : front(0), rear(0)
	{
		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}
	~Queue()
	{

	}
public:
	void push(T data)
	{
		if (rear >= SIZE)	// +1하면 안되구나 
		{
			cout << "Linear Queue is OverFlow" << endl;
		}
		else
		{
			container[rear++] = data;

		}
	}

	// front와 rear가 같으면 비어있음
	bool isEmpty()
	{
		return front == rear;
	}
	// 스택과 반대로 앞에서부터 NULL로 채우기(?)
	void pop()
	{
		if (isEmpty())
		{
			cout << "Linear Queue is OverFlow" << endl;
		}

		container[front++] = NULL;	// null 만들고 증가시키기(?)
		//front++ = NULL; // 얘도 되나? 
	}

	const T& Front()
	{
		if (isEmpty())
		{
			exit(1);		// 강제종료시키기
		}
		return container[front];	// front 위치 찾기? 반환하기? 
	}

	const int& size()
	{
		return rear - front;		// rear에서 front 빼야 사이즈 크기 알 수 있음 
	}
};



int main()
{
	Queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);		// 여기서 overflow 되야하는데 왜 50에서 되지

	cout << q.size() << endl;

	while (q.isEmpty() == false)
	{
		cout << q.Front() << endl;
		q.pop();
	}

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);


	return 0;
}

