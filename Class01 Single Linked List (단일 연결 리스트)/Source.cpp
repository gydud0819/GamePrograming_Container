#include "Util.h"

template <typename T>
class List
{
private:
	int size;

	struct Node
	{
		T data;
		Node* next;
	};
	// 리스트의 시작 위치를 가리키는 포인터
	Node* head;
public:		// 생성자 소멸자
	List() : size(0), head(nullptr) {}
	List(int _size, Node* _head) : size(_size), head(_head) {}		// 이니셜라이저 초기화는 다시 해봐야겟다
	/*List()
	{
		size = 0;
		head = nullptr;
	}*/
	~List()
	{
		// 날먹코드네 
		//while (head != nullptr)
		//{
		//	pop_front();
		//}
	}
public:		// 함수라인
	void push_front(T data)
	{
		// Node* newNode ({ data, head});
		Node* newNode = new Node;
		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;
			newNode->next = nullptr;

		}
		else
		{
			newNode->next = head;
			head = newNode;
		}

		size++;

	}

	// 앞의 데이터 빼는 거
	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "empty" << endl;	// 리스트가 비어있으면 메시지 출력
		}
		else
		{
			Node* deleteNode = head; // 삭제할 노드를 백업해두고
			head = head->next;        // head는 한 칸 앞으로 이동
			delete deleteNode;        // 기존 head 메모리 해제
			size--;								// 사이즈 감소

		}
	}

	void push_back(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;

		if (head == nullptr)		// 비워져있으면
		{
			head = newNode;			// 헤더가 곧 노드

		}
		else
		{
			// 안비워져있으면 
			// head부터 시작해서 next를 따라가기
			Node* currentNode = head;		// 현재 노드가 헤더

			while (currentNode->next != nullptr)	// 노드가 가리키는게 nullptr이 아니면
			{
				currentNode = currentNode->next;	// 현재노드는 그 다음을 가리킨다.
			}
			currentNode->next = newNode;			//

		}
		size++;
	}

	void pop_back()
	{
		// [10] [20] [30]			[nullptr] -> [10] [20] [nullptr]
		//	↑	     ↑				↑
		//  head     previousNode	deleteNode

		if (head == nullptr)
		{
			cout << "empty" << endl;
		}

		else if (head->next == nullptr)
		{
			delete head;	// 시작점이니까 지우기
			head = nullptr;
		}
		else
		{
			Node* previousNode = head;
			Node* deleteNode = head->next;

			while (deleteNode->next != nullptr)
			{
				previousNode = deleteNode;		// 이전노드가 삭제노드여야하고
				deleteNode = deleteNode->next;	// 삭제노드는 본인이 가리키고 잇던 다음을 가리킨다
			}
			delete deleteNode;				// 다됏으면 삭제노드 지우기(?)
			size--;			// 여기서 해도 되잖아
		}
	}

	bool Empty()		// 함수 자체가 0 아님 1 반환하는거니까 if문 쓸필요가 없겠네 
	{
		return head == nullptr;
	}

	void Remove(T data)
	{
		// 필요한 거
		// head, previousNode, deleteNode (data, next는 클래스에 내장)
		//		  ↑--------------------------------------------↓
		// heap → [10] - - - - -[20이었던 것]- - - - - - - - - -[30]- - - - - - -[20]
		//		   ↑previousNode						       ↑deleteNode
		// 10을 지워야할땐 head를 deleteNode의 다음을 가리키게 옮겨줘야한다 ex) deleteNode->next= head; 이건가 

		if (head == nullptr)
		{
			return;
		}

		// 이게 잇음 안되나  잇어도되나 
		//else if (head->next == nullptr)
		//{
		//	delete head; // 헤더를 지워야ㅕㅏㅎ나? 아닌거 같은ㄷ 
		//	head = nullptr;
		//}

		else
		{
			Node* deleteNode = head;						// 왜 둘다 헤드가 된다는거지 
			Node* previousNode = head;

			while (deleteNode != nullptr)
			{
				if (deleteNode->data == data)
				{
					if (deleteNode == head)
					{
						head = deleteNode->next;
					}
					else
					{
						previousNode->next = deleteNode->next;

					}
					delete deleteNode;
					size--;
					deleteNode = head;
				}
				previousNode = deleteNode;
				deleteNode = deleteNode->next;
			}
		}

		// 내가 한거 
		//else
		//{
		//	
		//	//Node* previousNode = head;						// 이전노드가 아니라 왜 삭제노드가 헤드로 가지 헤드가 삭제되면 안되서 그런가 
		//	//Node* deleteNode = previousNode->next;
		//
		//	
		//
		//	while (deleteNode->next != nullptr)
		//	{
		//		previousNode = deleteNode;
		//		deleteNode = deleteNode->next;
		//	}
		//	delete deleteNode;
		//	size--;
		//}


	}

};

int main()
{
	List<int> list;

	list.push_front(5);
	list.push_front(10);

	list.push_back(20);
	list.push_back(30);

	list.pop_front();

	cout << list.Empty() << endl;

	return 0;


}