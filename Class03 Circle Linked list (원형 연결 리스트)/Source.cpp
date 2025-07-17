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
		while (head != nullptr)
		{
			pop_front();
		}
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
			Node* deleteNode = head->next;
			if (head = head->next)
			{
				head = nullptr;

			}
			else
			{
				head->next = deleteNode->next;
			}

			delete deleteNode;
			size--;
		}
	}

	// 맨뒤를 지우는건 알겠는데;;;;;;;;;;;;
	void pop_back()
	{
		if (head == nullptr)
		{
			cout << "linked list is empty" << endl;
		}

		else
		{
			Node* deleteNode = head;
			Node* currentNode = head;

			// 하나 일 때? 
			if (head == head->next)	// ?
			{
				delete head;
				head = nullptr;

			}
			else // 하나 이상
			{

				//// currentNode->next->next == head면, currentNode->next가 마지막 노드임
				//while (currentNode->next->next != head)
				//{
				//	currentNode = currentNode->next;
				//}

				//deleteNode = currentNode->next;  // 삭제할 마지막 노드
				//currentNode->next = head;        // tail 이전 노드가 head를 가리킴

				for (int i = 0; i < size - 1; i++)
				{
					currentNode = currentNode->next;
				}

				currentNode->next = head->next;
				head = currentNode;
			}

			delete deleteNode;
			size--;


		}

	}

	bool empty()
	{
		return(head == nullptr);
	}

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

	list.pop_front();
	list.pop_front();
	list.pop_front();

	list.pop_back();
	list.pop_back();
	list.pop_back();

	cout << list.empty() << endl;

	return 0;
}