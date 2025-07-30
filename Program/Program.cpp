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

	}

public:
	void insert(T data)
	{
		Node* createNode(T data)
		{

		}

		// 아오 그지같네 얘도 끝나고 다시 해봐야겠다
		if (root == nullptr)
		{
			Node* newNode = root;
			size++;
			return;
		}

		// 중복되는 키값을 허용하지 않음

		// root보다 값이 작으면 왼쪽 크면 오른쪽

		else
		{
			Node* currentNode = newNode;
			while (currentNode != nullptr)		// 임시
			{
				if (data < currentNode->data)
				{
					if (currentNode->leftNode == nullptr)
					{
						currentNode->leftNode = new Node(data);
						size++;
						return;
					}
					currentNode = currentNode->leftNode;
				}
				else if (data > currentNode->data)
				{
					if (currentNode->rightNode == nullptr)
					{
						currentNode->rightNode = new Node(data);
						size++;
						return;
					}
					currentNode = currentNode->rightNode;
				}
				else
				{
					break;
				}
			}
		}




	}

	void release(Node* root)
	{
		// 재귀함수 방식으로 삭제
		if (root == nullptr)
		{
			return;
		}

		else
		{
			if (root->leftNode == nullptr)
				release(root->leftNode);

		}
		
	}

};




		// 발표를 40분씩이나 한다고? 미쳤네 도랐네 전체적인 흐름 + 어디를 어떻게 이어지게 했는지 말해야하니까 그럴수도 있겠다 
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

	return 0;
}