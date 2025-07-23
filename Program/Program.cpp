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
			return;		// 비어있으면 그냥 리턴하기
		}
		// 전위? --index; <-이거? 

		// 왼쪽 : parent * 2 + 1
		// 오른쪽 : 왼쪽 + 1

		int parent = 0;

		while ((parent * 2 + 1) < index)
		{
		int leftchild = parent * 2 + 1;		// 왼쪽 오른쪽 자식 변수 있어야하나용?
		int rightchild = leftchild + 1;
		int child = parent;			// 자식 변수 초기화? 맞나 
		
			// 왼쪽 자식이 존재하고 왼쪽 자식이 부모보다 크면 왼쪽 자식으로 바꿔주기
			if (leftchild < index && container[leftchild] > container[child])
			{
				child = leftchild;		// 왼쪽 자식이 더 크면 왼쪽 자식으로 바꿔주기
			}

			// 오른쪽 자식이 존재하고 오른쪽 자식이 부모보다 크면 
			if (rightchild < index && container[rightchild] > container[child])
			{
				child = rightchild;		// 오른쪽 자식이 더 크면 오른쪽 자식으로 바꿔주기
			}

			if (child == parent) { break; }	// 자식이 안바뀌면 종료하기
				
			swap(container[child], container[parent]);

			parent = child;		// parent = child, child = parent 차이가 큰가? 
		}
	
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


// 내일 해시테이블 예정 
#pragma region MyRegion
//template <typename K, typename V>
//class HashTable
//{
//private:
//	struct Node {
//		K key;
//		V value;
//		Node* next;
//
//		Node(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
//	};
//
//	Node** table;      // 버킷 배열 (체이닝용)
//	int capacity;      // 버킷 개수
//	int size;          // 저장된 총 개수
//
//	// 해시 함수 (기본 버전)
//	int hashFunc(const K& key) const {
//		return std::hash<K>{}(key) % capacity;
//	}
//
//public:
//	HashTable(int cap = 10) : capacity(cap), size(0) {
//		table = new Node * [capacity];
//		for (int i = 0; i < capacity; i++)
//			table[i] = nullptr;
//	}
//
//	~HashTable() {
//		for (int i = 0; i < capacity; i++) {
//			Node* curr = table[i];
//			while (curr) {
//				Node* temp = curr;
//				curr = curr->next;
//				delete temp;
//			}
//		}
//		delete[] table;
//	}
//
//	// 삽입 or 수정
//	void insert(const K& key, const V& value) {
//		int idx = hashFunc(key);
//		Node* curr = table[idx];
//
//		while (curr) {
//			if (curr->key == key) {
//				curr->value = value; // 수정
//				return;
//			}
//			curr = curr->next;
//		}
//
//		// 맨 앞에 삽입
//		Node* newNode = new Node(key, value);
//		newNode->next = table[idx];
//		table[idx] = newNode;
//		size++;
//	}
//
//	// 탐색
//	V* find(const K& key) {
//		int idx = hashFunc(key);
//		Node* curr = table[idx];
//		while (curr) {
//			if (curr->key == key)
//				return &(curr->value);
//			curr = curr->next;
//		}
//		return nullptr;
//	}
//
//	// 삭제
//	void remove(const K& key) {
//		int idx = hashFunc(key);
//		Node* curr = table[idx];
//		Node* prev = nullptr;
//
//		while (curr) {
//			if (curr->key == key) {
//				if (prev)
//					prev->next = curr->next;
//				else
//					table[idx] = curr->next;
//
//				delete curr;
//				size--;
//				return;
//			}
//			prev = curr;
//			curr = curr->next;
//		}
//	}
//
//	// 디버깅용 출력
//	void printTable() const {
//		cout << "[HashTable 상태]" << endl;
//		for (int i = 0; i < capacity; i++) {
//			cout << "[" << i << "]: ";
//			Node* curr = table[i];
//			while (curr) {
//				cout << "(" << curr->key << ", " << curr->value << ") -> ";
//				curr = curr->next;
//			}
//			cout << "nullptr" << endl;
//		}
//	}
//};
#pragma endregion


int main()
{
	PriorityQueue<int> pq;

	pq.push(5);
	pq.push(3);
	pq.push(6);
	pq.push(7);
	pq.push(1);
	pq.push(9);

	cout << pq.top() << endl;
	pq.pop();
	cout << pq.top() << endl;
	pq.pop();
	cout << pq.top() << endl;
	cout << pq.isEmpty() << endl;


	return 0;
}



