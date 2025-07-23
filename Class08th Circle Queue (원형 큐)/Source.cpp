#include "Util.h"
#define SIZE 4

// 내일 원형 큐, priority Queue? 예정 
template <typename T>
class Queue
{
private:
	int front;	// [3]에서 front가 시작함 (?) 
	int rear;
	T container[SIZE];
public:
	Queue() : front(SIZE - 1), rear(SIZE - 1)		//[3]에서 front, rear이 시작하니까 SIZE - 1이 맞겠네 
	{
		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}

public:
	// 이건 쪼끔 어려운거 같은데 이게 대체 무슨말이야 
	void push(T data)
	{
		if ((rear + 1) % SIZE == front)		// if ((rear + 1) % SIZE == front)		// 이게 원형 큐에서 rear가 front랑 같으면 꽉 찬거니까
		{
			cout << "Queue is Full " << endl;
			//return;		// 이게 없으면 계속 진행되니까 return 해줘야함
		}

		rear = (rear + 1) % SIZE;		// rear가 0부터 시작하니까 0, 1, 2, 3, 0, 1, 2, 3 이런식으로 계속 반복되는듯
		container[rear] = data;			// rear이 먼저 가리키	는 자리에 데이터를 넣는다.

	}

	bool isEmpty()
	{
		return rear == front;		// rear가 front랑 같으면 비어있는거니까 반환하기 
	}

	void pop()
	{
		if (isEmpty())
		{
			cout << "Circle Queue is Empty" << endl;
			return;
		}
		front = (front + 1) % SIZE;
		container[front] = NULL;		// front가 가리키는 자리를 비워준다?
	}

	// 선형이랑 다르게 계속 도는? 느낌이니까			// 이ㅓㄱ ㅏ아닌거같은데 front가 앞에서 추출인가 
	const T& Front()
	{
		if (isEmpty())
		{
			exit(1);			// 얘도 예외로 강종을 만들어줘야하구나 
		}
		return container[(front + 1) % SIZE];			// 이건 더 아닌거같은데 

	}


};

// stack, 선형 큐, 원형 큐 예정
//template <typename T>
//class Queue
//{
//	int front;		// 앞에 추가
//	int rear;		// 뒤에 추가
//	int size;		// 원소 개수
//	int capacity;	// 전체 크기
//	T* container;	// 데이터 저장할 배열공간
//
//public:
//	Queue(int _capacity) : front(0), rear(0), size(0), capacity(_capacity), container(nullptr)
//	{
//		container = new T[_capacity];
//	}
//
//	~Queue()
//	{
//		if (container != nullptr)
//		{
//			delete[] container;
//		}
//	}
//public:
//	void resize(int newSize)
//	{
//		T* newContainer = new T[newSize];
//
//		for (int i = 0; i < size; i++)
//		{
//			newContainer[i] = container[(front + i) % capacity];
//		}
//
//		delete[] container;
//		container = newContainer;
//
//		front = 0;
//		rear = size;
//		capacity = newSize;
//	}
//	// rear 자리에 데이터를 넣고, rear를 다음 자리로 옮긴다. 원형 구조라 배열 끝이면 0으로 돌아가야 한다.
//	void enqueue(const T& data)
//	{
//		// 원소개수가 크기만큼 같아지면 
//		if (size == capacity)
//		{
//			cout << "Queue is Full!" << endl;
//		}
//		else
//		{
//			container[rear] = data;		// 뒤에서 부터 하나씩 데이터 추가하기
//
//			rear = (rear + 1) % capacity;	// 넣은거만큼 +1 하는 이유가 container가 가리키는 위치때문인건가? 들어간거에서 젤 뒤를 가리키고 전체 배열로 나누면 한칸씩 데이터 들어감
//
//			size++;	// 그리고 원소개수 증가시키기
//		}
//	}
//
//	void dequeue()
//	{
//		if (size == 0)
//		{
//			cout << "dequeue is empty" << endl;
//		}
//		else
//		{
//			//cout << "dequeue : " << container[front] << endl;
//			front = (front + 1) % capacity;
//			size--;		// 삭제니까 감소하기 
//		}
//	}
//
//	void peek()
//	{
//
//	}
//
//	bool isEmpty()
//	{
//		return size == 0;
//	}
//
//	bool isFull()
//	{
//		return size == capacity;
//	}
//};

int main()
{
	Queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	//q.push(40);		// 공간 하나를 비워야해서 40부터 터지는게 맞다 
	//q.push(50);	// 이거는 꽉 찼으니까 안들어가는게 맞는데 40까진 들어가야하는거같은데 왜 40에서부터 터지냐 미친듯

	while (q.isEmpty() == false)
	{
		cout << q.Front() << endl;
		q.pop();

	}

	q.push(1);
	q.push(2);
	q.push(3);



	return 0;

	//PriorityQueue pq;
	//
	//pq.push(30, 1);		// 데이터: 30, 우선순위: 1
	//pq.push(10, 3);		// 데이터: 10, 우선순위: 3
	//pq.push(20, 2);		// 데이터: 20, 우선순위: 2
	//
	//pq.print();			// [10, p=3] [20, p=2] [30, p=1]
	//
	//cout << "Pop: " << pq.pop() << endl; // 10
	//cout << "Pop: " << pq.pop() << endl; // 20
	//cout << "Pop: " << pq.pop() << endl; // 30
	//cout << "Pop: " << pq.pop() << endl; // Queue is Empty
	//
	//return 0;
}