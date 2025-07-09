#include "Util.h"

template<typename T>
class List		// 양방향 연결 리스트
{
private:
	int size;
	struct Node
	{
		T data;
		Node* previousNode;
		Node* next;
	};
	Node* head;
	Node* tail;
public:
	List() : size(0), head(NULL), tail(NULL) {}
	List(int _size, Node* _head, Node* _tail) : size(_size), head(_head), tail(_tail) {}

};

int main()
{
#pragma region Double Linked List
	// 양방향 연결 리스트 삽입 순서
	//newNode->prev = prev;
	//newNode->next = next;
	//prev->next = newNode;
	//next->prev = newNode;

	List<int> list;
#pragma endregion

}