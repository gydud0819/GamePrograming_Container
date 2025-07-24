#include "Util.h"

template <typename T>
// 우선순위의 기준이... ㅇㅅㅇ
class PriorityQueue		// 동적 배열로 만들기			// 정적이 아니라? 홀리몰리 
{
private:
	int index;			// 배열 크기? 
	int capacity;		// 메모리 공간 크기? 맞나? 아닌거 같은데 

	T* container;
public:
	PriorityQueue() : index(0), capacity(0), container(nullptr) {}
	~PriorityQueue()
	{
		// 소멸자 
		if (container != nullptr)
		{
			delete[] container;
		}
	}
public:
	void resize(int newSize)
	{
		//capacity = newSize;		// 이게 아닌거 같은데 

		// 2. 새로운 포인터 변수를 생성하고 새롭게 만들어진 메모리 공간을 가리키도록 하기
		T* newContainer = new T[newSize];

		// 3. 새로운 메모리 공간의 값 초기화하기
		for (int i = 0; i < capacity; i++)
		{
			newContainer[i] = T();	// NULL도 가능

		}

		// 4. 기존 배열에 있는 값을 복사해서 새로운 배열에 넣어주기 
		for (int i = 0; i < index; i++)
		{
			newContainer[i] = container[i];
		}

		// 5. 기존 배열의 메모리 해제하기
		if (container != nullptr)
			delete[] container;

		// 6. 기존 배열을 가리키던 포인터 변수의 값을 새로운 배열의 시작 주소로 가리키기 
		container = newContainer;
		capacity = newSize;		// capacity를 새롭게 바꿔주기
	}

	// 우와............................... 이게 무슨 말이야 
	void push(T data)
	{
		// 진짜 필요없나			// 필요하네 
		if (capacity <= 0)
		{
			resize(1);
		}

		if (index >= capacity)
		{
			resize(capacity * 2);	// 2배 증가요? 
		}

		container[index++] = data;

		int child = index - 1;		// 자식
		int parent = (child - 1) / 2;		// 부모

		// while 쓰는건가? 
		while (child > 0)
		{
			//heapify 공식 들어가는 거 같고		// 비교해서 크면 바꾸고 아니면 냅둬야하는거 같은데 
			if (container[child] > container[parent])
			{
				swap(container[child], container[parent]);
			}

			child = parent;
			parent = (child - 1) / 2;
		}

		// child 공식 : child가 [1]이 될수 있게 공식 만들기 
		// parent 공식 : (child - 1) / 2 = [0]
		// swap을 이용해서 바꿔라(?) 
	}

	const T& top()
	{
		return container[0];
	}

	const bool& isEmpty()
	{
		return index <= 0;
	}

	void pop()		// 집가서 수정하기 
	{
		if (index <= 0)
		{

			cout << "priority queue is empty" << endl;
		}

		else
		{
			container[0] = container[--index];

			int parent = 0;
			while ((parent * 2 + 1) < index)
			{
				int child = parent * 2 + 1;

				if (container[child] < container[child + 1])
				{
					child++;
				}

				if (container[child] < container[parent])
				{
					break;
				}
				else
				{
					swap(container[parent], container[child]);
					parent = child;
				}
			}
		}

		//	if (index <= 0)
		//	{
		//		return;
		//	}

		//	 //전위? --index; <-이거? 
		//	 //
		//	 //왼쪽 : parent * 2 + 1
		//	 //오른쪽 : 왼쪽 + 1

		//	int parent = 0;

		//	container[0] = container[--index];		// 이게 빠졌구나 

		//	while ((parent * 2 + 1) < index)
		//	{
		//		int leftchild = parent * 2 + 1;		// 왼쪽 오른쪽 자식 변수 있어야하나용?
		//		int rightchild = leftchild + 1;
		//		int child = parent;			// 자식 변수 초기화? 맞나 

		//		// 왼쪽 자식이 존재하고 왼쪽 자식이 부모보다 크면 왼쪽 자식으로 바꿔주기
		//		if (leftchild < index && container[leftchild] > container[child])
		//		{
		//			child = leftchild;		// 왼쪽 자식이 더 크면 왼쪽 자식으로 바꿔주기
		//		}

		//		// 오른쪽 자식이 존재하고 오른쪽 자식이 부모보다 크면 
		//		if (rightchild < index && container[rightchild] > container[child])
		//		{
		//			child = rightchild;		// 오른쪽 자식으로 바꿔주기
		//		}

		//		if (child == parent) { break; /*return;*/ }	// 자식이 안바뀌면 종료하기		// 리턴쓰는건 안되나 

		//		swap(container[child], container[parent]);

		//		parent = child;		// parent = child, child = parent 차이가 큰가? 
		//	}

	}
};
//#define SIZE 100
//
//class PriorityQueue {
//private:
//	int data[SIZE];			// 실제 데이터 저장
//	int priority[SIZE];		// 우선순위 저장
//	int count;				// 현재 큐에 있는 요소 수
//
//public:
//	PriorityQueue() : count(0) {}
//
//	// 큐가 비었는지 확인
//	bool isEmpty() {
//		return count == 0;
//	}
//
//	// 큐에 있는 요소 개수
//	int size() {
//		return count;
//	}
//
//	// 우선순위를 고려해 정렬된 위치에 삽입
//	void push(int value, int prio) {
//		if (count >= SIZE) {
//			cout << "Queue is Full" << endl;
//			return;
//		}
//
//		int i = count - 1;
//
//		// 우선순위 높은 순으로 정렬 (큰 숫자가 높은 우선순위라고 가정)
//		while (i >= 0 && priority[i] < prio) {
//			data[i + 1] = data[i];
//			priority[i + 1] = priority[i];
//			i--;
//		}
//
//		// 새 값 삽입
//		data[i + 1] = value;
//		priority[i + 1] = prio;
//		count++;
//	}
//
//	// 가장 높은 우선순위 값을 꺼냄
//	int pop() {
//		if (isEmpty()) {
//			cout << "Queue is Empty" << endl;
//			return -1;
//		}
//
//		int result = data[0];
//
//		// 하나씩 앞으로 당기기
//		for (int i = 1; i < count; i++) {
//			data[i - 1] = data[i];
//			priority[i - 1] = priority[i];
//		}
//
//		count--;
//		return result;
//	}
//
//	// 디버깅용: 큐 안에 뭐 들었는지 보기
//	void print() {
//		cout << "Queue: ";
//		for (int i = 0; i < count; i++) {
//			cout << "[" << data[i] << ", p=" << priority[i] << "] ";
//		}
//		cout << endl;
//	}
//};





int main()
{
	PriorityQueue<int> pq;

	pq.push(5);
	pq.push(3);
	pq.push(6);
	pq.push(7);
	pq.push(1);
	pq.push(9);


	//cout << pq.top() << endl;
	//pq.pop();
	//cout << pq.top() << endl;
	//cout << pq.isEmpty() << endl;

	while (pq.isEmpty() == false)
	{
		cout << pq.top() << endl;
		pq.pop();
	}


	return 0;
}


