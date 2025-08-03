#include "Util.h"

template <typename T>
class Set
{
private:
	// 이진 탐색 트리 노드 구조
	struct Node
	{
		T data;                // 노드에 저장될 값
		Node* leftNode;        // 왼쪽 자식
		Node* rightNode;       // 오른쪽 자식

		Node() : data(0), leftNode(nullptr), rightNode(nullptr) {}
	};

	int size;                // 트리 전체 노드 수
	Node* root;              // 트리의 루트 노드

public:
	Set() : size(0), root(nullptr) {}

	~Set()
	{
		release(root);        // 소멸자에서 전체 트리 삭제
	}

	// 노드 생성 함수 (강사님이 따로 함수 만들라 한 부분)
	Node* createNode(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->leftNode = nullptr;
		newNode->rightNode = nullptr;
		return newNode;
	}

	// 값 삽입
	void insert(T data)
	{
		if (root == nullptr)
		{
			root = createNode(data);   // 루트가 없으면 최초 삽입
		}
		else
		{
			Node* currentNode = root;

			while (currentNode != nullptr)
			{
				// 중복 값은 삽입하지 않음
				if (currentNode->data == data)
				{
					return;
				}
				else if (currentNode->data > data)
				{
					// 왼쪽 자식이 비어 있으면 삽입
					if (currentNode->leftNode == nullptr)
					{
						currentNode->leftNode = createNode(data);
						return;
					}
					else
					{
						currentNode = currentNode->leftNode;
					}
				}
				else
				{
					// 오른쪽 자식이 비어 있으면 삽입
					if (currentNode->rightNode == nullptr)
					{
						currentNode->rightNode = createNode(data);
						return;
					}
					else
					{
						currentNode = currentNode->rightNode;
					}
				}
			}
		}
	}

	// 메모리 해제 (후위 순회 방식)
	void release(Node* root)
	{
		if (root != nullptr)
		{
			release(root->leftNode);
			release(root->rightNode);
			delete root;
		}
	}

	// 값 삭제 함수
	void erase(T data)
	{
		Node* currentNode = root;
		Node* parentNode = nullptr;

		// 1. 삭제할 노드를 먼저 탐색
		while (currentNode != nullptr && currentNode->data != data)
		{
			parentNode = currentNode;

			if (currentNode->data > data)
				currentNode = currentNode->leftNode;
			else
				currentNode = currentNode->rightNode;
		}

		if (currentNode == nullptr)
		{
			cout << "the data does not exist" << endl;
			return;
		}

		// 2-1. 자식이 없는 노드 삭제
		else if (currentNode->leftNode == nullptr && currentNode->rightNode == nullptr)
		{
			if (parentNode != nullptr)
			{
				if (parentNode->leftNode == currentNode)
					parentNode->leftNode = nullptr;
				else
					parentNode->rightNode = nullptr;
			}
			else
			{
				root = nullptr;  // 루트 자체였던 경우
			}
		}

		// 2-2. 자식이 하나만 있는 노드 삭제
		else if (currentNode->leftNode == nullptr || currentNode->rightNode == nullptr)
		{
			Node* child = (currentNode->leftNode != nullptr) ? currentNode->leftNode : currentNode->rightNode;

			if (parentNode != nullptr)
			{
				if (parentNode->leftNode == currentNode)
					parentNode->leftNode = child;
				else
					parentNode->rightNode = child;
			}
			else
			{
				root = child;  // 루트였을 때
			}
		}

		// 2-3. 자식이 둘 다 있는 노드 삭제
		else
		{
			// 오른쪽 서브트리에서 최소값 찾기
			Node* childNode = currentNode->rightNode;
			Node* traceNode = currentNode;

			while (childNode->leftNode != nullptr)
			{
				traceNode = childNode;
				childNode = childNode->leftNode;
			}

			// 최소값으로 현재 노드 값 교체
			currentNode->data = childNode->data;

			// 최소값 노드 삭제 처리
			if (traceNode == currentNode)
				traceNode->rightNode = childNode->rightNode;
			else
				traceNode->leftNode = childNode->rightNode;

			delete childNode;
			return;
		}

		// 마지막 delete는 자식 없는 노드나 자식 한 개일 때 해당
		delete currentNode;
	}

	// 중위 순회 호출 (외부 인터페이스)
	void inorder()
	{
		inorder(root);
	}

	// 중위 순회 (왼쪽 → 현재 → 오른쪽)
	void inorder(Node* root)
	{
		if (root != nullptr)
		{
			inorder(root->leftNode);
			cout << root->data << " ";
			inorder(root->rightNode);
		}
	}
};



int main()
{
	Set<int> set;
	set.insert(5);
	set.insert(8);
	set.insert(2);
	set.insert(1);
	set.insert(9);
	set.insert(10);
	set.insert(14);
	set.insert(6);

	set.erase(6);

	return 0;
}