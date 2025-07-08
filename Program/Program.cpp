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
	//List(int size, Node* head) : size(0), head(nullptr) {}		// 이니셜라이저 초기화는 다시 해봐야겟다
	List()
	{
		size = 0;
		head = nullptr;
	}
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
		// 그림 보면서 다시해봐야겟다 그림ㅇ르 지웟네? ;;;;;;
		Node* deleteNode;

		if (head == nullptr)
		{
			Node* deleteNode = head;
		}
		else
		{
			// 안비워져있으면 
			head = deleteNode->next;			// 헤더는 삭제노도의 다음?이 맞나 이게아닌가 이게 위에 저렇게한거라고 한거 
			head = head->next;					// 헤더는 그 다음 헤더를 가리키는거 이게 맞는거 같은데
			//deleteNode->next = nullptr;			// 삭제노드가 다음으로 가리키는게 nullptr 얜 맞는듯

			while (deleteNode->next != nullptr)	// 조건도 이게 아닌거같은데 
			{
				head = deleteNode->data;
			}
			Node* previousNode = deleteNode->next;	// 얘랑
			Node* previousNode = head;				// 얘랑같은의미 아닌가 위에 저렇게 햇으면 
			delete deleteNode;
			size--;		// 감소 
		}

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

	return 0;
}