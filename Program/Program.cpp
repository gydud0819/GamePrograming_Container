#include "Util.h"

//class String	// 문자열 == 문자들의 배열 [] <- 쓰는건가 
//{
//	// 길이? 
//	int size;		// ?
//	char* pointer;	// ???
//
//public:
//	String() : size(0), pointer(nullptr) {}
//	String(int _size, char* _pointer) : size(_size), pointer(_pointer) {}
//	~String()
//	{
//
//	}
//public:
//	void operator = (const char* word)
//	{
//		// 주석 달아도 이해안갈거 같은데 
//		size = strlen(word) + 1;		// 길이 = word의 길이에 +1 하기 ('\0' <- 포함해야해서)
//		if (pointer == nullptr)			// 아무것도 가리키지않을때
//		{
//			pointer = new char[size];	// 새로 할당하기? 문자열의 길이만큼? 
//
//			for (int i = 0; i < size; i++)
//			{
//				pointer[i] = word[i];	// 복사해서 담기(?)
//			}
//		}
//		else
//		{
//			char* temporary = new char[size];		// 이건 뭐야 
//
//			for (int i = 0; i < size; i++)	// 사이즈만큼 돌리고
//			{
//				temporary[i] = word[i];	 // 복사해서 가리키는 값을 담는다?
//			}
//			delete[] pointer;		// 재할당해야해서 지워주기 -> word의 League of Lengend 지워주기(?)
//
//			pointer = temporary;
//		}
//	}
//
//	// 문자열 길이 구하기(?)
//	const int& length()
//	{
//		return size - 1;		// '\0' <- 빼야한다? 먼소리여 
//	}
//};
template <typename T>
class Queue
{
	int front;		// 앞에 추가
	int rear;		// 뒤에 추가
	int size;		// 원소 개수
	int capacity;	// 전체 크기
	T* container;	// 데이터 저장할 배열공간

public:
	Queue(int _capacity) : front(0), rear(0), size(0), capacity(_capacity), container(nullptr)
	{
		container = new T[_capacity];
	}

	~Queue()
	{
		if (container != nullptr)
		{
			delete[] container;
		}
	}
public:
	void resize(int newSize)
	{
		T* newContainer = new T[newSize];

		for (int i = 0; i < size; i++)
		{
			newContainer[i] = container[(front + i) % capacity];
		}

		delete[] container;
		container = newContainer;

		front = 0;
		rear = size;
		capacity = newSize;
	}
	// "rear 자리에 데이터를 넣고, rear를 다음 자리로 옮긴다. 원형 구조라 배열 끝이면 0으로 돌아가야 한다."
	void enqueue(const T& data)
	{
		// 원소개수가 크기만큼 같아지면 
		if (size == capacity)
		{
			cout << "Queue is Full!" << endl;
		}
		else
		{
			container[rear] = data;		// 뒤에서 부터 하나씩 데이터 추가하기
			
			rear = (rear + 1) % capacity;	// 넣은거만큼 +1 하는 이유가 container가 가리키는 위치때문인건가? 들어간거에서 젤 뒤를 가리키고 전체 배열로 나누면 한칸씩 데이터 들어감

			size++;	// 그리고 원소개수 증가시키기
		}
	}

	void dequeue()
	{
		if (size == 0)
		{
			cout << "dequeue is empty" << endl;
		}
		else
		{
			//cout << "dequeue : " << container[front] << endl;
			front = (front + 1) % capacity;
			size--;
		}
	}

	void peek()
	{

	}

	bool isEmpty()
	{
		return size == 0;
	}

	bool isFull()
	{
		return size == capacity;
	}
};

int main()
{
	/*String message;
	message = "League of Lengend";
	message = "Adidas";
	
	cout<< message.length();*/

	Queue<int> que(6);
	que.enqueue(10);
	que.enqueue(20);
	que.enqueue(30);
	que.enqueue(40);

	que.dequeue();
	que.dequeue();
	que.dequeue();
	que.dequeue();

	return 0;
}