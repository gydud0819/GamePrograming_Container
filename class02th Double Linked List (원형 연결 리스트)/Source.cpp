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
	~List()
	{
		while (head != nullptr)
		{
			pop_front();
		}
	}

public:
	void push_front(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;
		newNode->previousNode = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			head->previousNode = newNode;
			newNode->next = head;

			head = newNode;
		}
		size++;

	}

	void pop_front()
	{
		// 먼차이여 
		if (head == nullptr)
		{
			cout << "empty" << endl;
		}
		else
		{

			Node* deleteNode = head;
			head = head->next;
			if (head == tail)
			{
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				deleteNode->next->previousNode = nullptr;

				head = head->next;
			}

			delete deleteNode;
			size--;
		}

		/*if (head == nullptr)
		{
			cout << "empty" << endl;
		}


		if (head != nullptr)
		{
			Node* deleteNode = head;
			head = head->next;
			head->previousNode = nullptr;
		}
		else
		{
			head = nullptr;
			tail = nullptr;
		}

		delete deleteNode;
		size--;*/

	}

	void push_back(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;
		newNode->previousNode = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			//tail = newNode;
		}
		else
		{
			while (head->next != nullptr)
			{
				tail->next = newNode;
				newNode->previousNode = tail;
				tail = newNode;

			}

			size++;
		}
	}

	void pop_back()
	{
		if (tail == nullptr)
		{
			cout << "node empty" << endl;
			return;
		}

		else
		{
			Node* deleteNode = tail;
			if (tail == head)
			{
				tail = nullptr;
				head = nullptr;

			}
			else
			{
				tail->previousNode->next = nullptr;
				tail = tail->next;
			}

			delete deleteNode;
			size--;
		}
	}

	bool empty()
	{
		return(head == nullptr);
	}

	void Remove(T data)
	{
		if (head == nullptr)
		{
			return;
		}
		// ? 젤 앞이랑 뒤 삭제? ???????

		Node* deleteNode = head;
		Node* nextNode = nullptr;

		// 중간과정을 추상해서 해야하니까 어렵네 ㅇㅅㅇ 

		while (deleteNode != nullptr)
		{
			if (deleteNode->data == data)
			{
				if (deleteNode == head)
				{
					delelteNode = deleteNode->next;

					pop_front();
				}
				else if (deleteNode == tail)
				{
					pop_back();

					deleteNode = nullptr;
				}
				else
				{
					deleteNode->previousNode->next = deleteNode->next;
					deleteNode->next->previousNode = deleteNode->previousNode;
					nextNode = deleteNode->next;
					delete deleteNode;
					deleteNode = nextNode;
					size--;
				}
			}
			else
			{
				deleteNode = deleteNode->data;

			}

		}

	}

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

	list.push_front(4);
	list.push_front(7);

	list.pop_front();
	list.pop_back();

	list.push_back(10);
	list.push_back(20);

	list.pop_front();
	list.pop_front();

	list.pop_back();
	list.pop_back();

	cout << list.empty() << endl;
#pragma endregion

}