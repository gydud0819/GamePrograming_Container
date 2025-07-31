#include "Util.h"

template <typename T>
class Set
{
	// 부모 노드(루트), 왼쪽자식, 오른쪽 자식 노드 필요
private:
	struct Node
	{
		T data;		// ? 이거 맞나 
		Node* leftNode;
		Node* rightNode;

		Node() : data(0), leftNode(nullptr), rightNode(nullptr) {}
	};

	int size;
	Node* root;

	// 데이터 없어도되나? 얘가 루트인가 

public:
	Set() : size(0), root(nullptr) {}
	~Set()
	{
		release(root);
	}

public:
	//void insert(T data)
	//{
	//	Node* createNode(T data)
	//	{
	//
	//	}
	//
	//	// 아오 그지같네 얘도 끝나고 다시 해봐야겠다
	//	if (root == nullptr)
	//	{
	//		Node* newNode = root;
	//		size++;
	//		return;
	//	}
	//
	//	// 중복되는 키값을 허용하지 않음
	//
	//	// root보다 값이 작으면 왼쪽 크면 오른쪽
	//
	//	else
	//	{
	//		Node* currentNode = newNode;
	//		while (currentNode != nullptr)		// 임시
	//		{
	//			if (data < currentNode->data)
	//			{
	//				if (currentNode->leftNode == nullptr)
	//				{
	//					currentNode->leftNode = new Node(data);
	//					size++;
	//					return;
	//				}
	//				currentNode = currentNode->leftNode;
	//			}
	//			else if (data > currentNode->data)
	//			{
	//				if (currentNode->rightNode == nullptr)
	//				{
	//					currentNode->rightNode = new Node(data);
	//					size++;
	//					return;
	//				}
	//				currentNode = currentNode->rightNode;
	//			}
	//			else
	//			{
	//				break;
	//			}
	//		}
	//	}
	//}

	void release(Node* root)
	{
		// 재귀함수 방식으로 삭제
		if (root != nullptr)
		{
			release(root->leftNode);

			release(root->rightNode);

			delete root;
		}

	}

	// 지우는거
	void erase(T data)		
	{
		// root로 접근하기 
		Node* currentNode = root;		// ?????????? 
		Node* parentNode = nullptr;
		Node* child = nullptr;			// 얘도 nullptr? 
		// current가 찾고자 하는 자식이 더 크면 왼쪽으로 간다?

		// 삭제할 때 조건

		// 1. 자식 노드가 없을 때
		// 2. 자식 노드가 1개 있을 때
		// 3. 자식 노드가 2개 있을 때

		// while 안에 모든게 지금 다들어가있는거 같은데 뭐야 이거 
		while (currentNode != nullptr && currentNode->data != data)
		{
			if (currentNode->data > data)
			{
				parentNode = currentNode;
				currentNode = currentNode->leftNode;
			}
			else
			{
				currentNode = currentNode->rightNode;
			}

			// current가 nullptr이면 없다고 출력하기(?)
			if (currentNode == nullptr)
			{
				cout << "data is not found" << endl;
			}

			else if (currentNode->leftNode == nullptr && currentNode->rightNode == nullptr)
			{
				// 아니 어디다 쓰라는거야
				child = nullptr;
				if (child->leftNode == nullptr)
				{
					child->rightNode = data;
				}

				else if (child->rightNode == nullptr)
				{
					child->leftNode = data;
				}

				if (parentNode != nullptr)
				{
					if (parentNode->leftNode == currentNode)
					{
						parentNode->leftNode = nullptr;
					}
					else
					{
						parentNode->rightNode = nullptr;
					}
				}
				root = nullptr;
			}
		}
		delete currentNode;
	


	}
};




// 발표를 40분씩이나 한다고? 미쳤네 도랐네 전체적인 흐름 + 어디를 어떻게 이어지게 했는지 말해야하니까 그럴수도 있겠다 
int main()
{
	Set<int> set;
	//set.insert(5);
	//set.insert(8);
	//set.insert(2);
	//set.insert(1);
	//set.insert(9);
	//set.insert(10);
	//set.insert(14);
	//set.insert(6);

	set.erase(6);

	return 0;
}