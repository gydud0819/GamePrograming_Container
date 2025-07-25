#include "Util.h"
#define SIZE 6

// 내일 eraser 예정 
// 정적 배열로 설계 동적으로 공부햇는데 홀리몰리 
template <typename K, typename V>		// K = Key, V = Value
class HashTable
{
	// 또결리스트 ㅇㅅㅇ (단일 연결)
	struct Node
	{
		K key;
		V value;
		Node* next;

	};

	// 구조체 배열 만들기
	struct Bucket
	{
		int count;
		Node* head;
	};
	Bucket bucket[SIZE];


public:
	HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
	}

	// 소멸자 
	~HashTable()
	{
		// bucket 비우기 
		for (int i = 0; i < SIZE; i++)
		{
			if (bucket[i].head != nullptr)
			{
				Node* deleteNode = bucket[i].head;	// 현재 노드 저장
				while (deleteNode != nullptr)
				{
					Node* nextNode = deleteNode->next;		// 다음 노드 저장
					delete deleteNode;				// 현재 노드 삭제
					deleteNode = nextNode;			// 다음 노드로 이동
				}
				bucket[i].head = nullptr;	// 현재 버킷의 head를 nullptr로 초기화
				bucket[i].count = 0;		// 현재 버킷의 count를 0으로 초기화
			}
		}
		// 버킷 배열 자체는 동적 할당이 아니므로 별도로 delete할 필요 없다
	}

public:
	template <typename T>
	// 해쉬값 
	const unsigned int& hash_function(T key)
	{
		// 양수만 저장할 수 있는 자료형? = key 값이 0 ~ 5까지 나올수있도록 하고 return 하기 나눠야하나 
		return  (unsigned)key % SIZE;
	}

	Node* create_node(K key, V value)
	{
		Node* newNode = new Node;
		// newNode에 key, value 넣기? 
		newNode->key = key;			// 이건 또 뭐야 
		newNode->value = value;
		newNode = nullptr;

		// 음 하라는 대로 했는데 이게 머지 

		return newNode;				// 이게뭐야 
	}

	void insert(K key, V value)
	{
		// 1. 해시함수를 통해서 값을 받는 임시 변수 만들기 
		int hashindex = hash_function(key);		// ? 
		// 2. 새로운 노드 생성하기 
		Node* newNode = create_node(key, value);		// ? 이게 뭐야 

		// 노드가 1개라도 존재하지 않는다면
		if (bucket[hashindex].count == 0)
		{
			bucket[hashindex].head = newNode;

		}
		else
		{
			newNode->next = bucket[hashindex].head;
			bucket[hashindex].head = newNode;
		}


		bucket[hashindex].count++;



		// 참조하라구요? 

	}

	void erase(K key)
	{
		int hashindex = hash_function(key);
		Node* currnetNode = bucket[hashindex].head;
		Node* previousNode = nullptr;

		// while써야하나 
		if (currnetNode == nullptr)
		{
			cout << "Not key found" << endl;
			return;
		}

		while (currnetNode != nullptr)
		{
			if (currnetNode->key == key)
			{
				if (currnetNode == bucket[hashindex].head)
				{
					bucket[hashindex].head = currnetNode->next;
				}
				else
				{
					previousNode->next = currnetNode->next;
				}
				bucket[hashindex].count--;		// 이게 어디로 가야하는거지 이게 맞나 
				delete currnetNode; // delete를 어디서 해야하ㅣ지 -> 여기서 함
				return;
			}
			else
			{
				previousNode = currnetNode;
				currnetNode = currnetNode->next;
			}

		}
		// 음 한계인거 같음 ㅠ
		cout << "Not key found" << endl;
	}

	//bool erase(K key)
	//{
	//	int index = hash_function(key);  // 해시 함수로 인덱스 찾기
	//	Node* currentNode = bucket[index].head;
	//	Node* previousNode = nullptr;
	//
	//	while (currentNode != nullptr)
	//	{
	//		if (currentNode->key == key) // 삭제 대상 발견
	//		{
	//			if (previousNode == nullptr)
	//			{
	//				// 첫 번째 노드를 삭제할 경우
	//				bucket[index].head = currentNode->next;
	//			}
	//			else
	//			{
	//				// 중간 또는 끝 노드 삭제
	//				previousNode->next = currentNode->next;
	//			}
	//
	//			delete currentNode;
	//			bucket[index].count--; // 카운트 감소
	//			return true; // 삭제 성공
	//		}
	//
	//		previousNode = currentNode;
	//		currentNode = currentNode->next;
	//	}
	//
	//	return false; // key 못 찾았음
	//}

};

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
	HashTable<float, int> ht;
	HashTable<int, int> ht2;
	HashTable<const char*, int> ht3;

	//cout << ht.hash_function(3.141592);
	//cout << ht2.hash_function(23);
	//cout << ht3.hash_function("Dinos");
	//ht.insert(2.3f, 3);
	ht3.insert("I want to go home", 2);
	ht3.erase("I want to go home");


	return 0;
}