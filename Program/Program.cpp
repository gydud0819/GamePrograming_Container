#include "Util.h"

template <typename T>
class List
{
	int size;
	struct Node
	{
		T data;
		Node* next;
	};
	Node* head;
public:
	List() : size(0), head(nullptr) {}
	List(int _size, Node* _head) : size(_size), head(_head) {}
	~List()
	{

	}

public:
	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;

			newNode = head;

		}
		size++;
	}

	void push_front(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
		}
		else
		{
			// 하나 이상 있을 때 다름
			newNode->next = head->next;
			//head = head->next;

			head->next = newNode;
			//head = newNode;
		}
		size++;
	}

	void pop_front()
	{

		if (head == nullptr)
		{
			cout << "empty" << endl;
		}


		else
		{
			Node* deleteNode = head;
			head = head->next;

			deleteNode->next->data = head;
			head = nullptr;

			delete deleteNode;
			size--;
		}
	}

	void pop_back()

};

int main()
{
	List<int> list;

	list.push_back(10);
	list.push_back(20);
	list.push_back(30);
	list.push_back(40);

	list.push_front(1);
	list.push_front(5);
	list.push_front(10);
}