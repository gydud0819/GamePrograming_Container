#include "Util.h"
#define SIZE 10

// 진짜 팀플 끝나고 주말 알바 끝나고 인접 행렬 다시해야겟다 내가 어디를 모르는지 알아야 물어보지 tq
template <typename T>
class AdjacencyList // 인접행렬 리스트 
{
private:
	struct Node
	{
		T data;
		Node* next;

		Node(T _data, Node* _link = nullptr)
		{
			data = _data;		// this 대신 이렇게 써도되겟지? 
			next = _link;
		}
	};

	int size;		// 정점의 개수? 
	T vertex[SIZE];		// 이게 집합인가?  정점의 집합 V? T?
	Node* list[SIZE];	// 리스트 어케 만드냐?

public:
	AdjacencyList() : size(0)
	{
		for (int i = 0; i < SIZE; i++)
		{
			list[i] = NULL;
			vertex[i] = NULL;
		}
	}

	~AdjacencyList()
	{

		for (int i = 0; i < SIZE; i++)
		{
			Node* deleteNode = list[i];
			Node* nextNode = list[i];

			if (deleteNode == nullptr)
			{
				continue;
			}
			else
			{
				while (nextNode != nullptr)
				{
					nextNode = deleteNode->next;
					delete deleteNode;
					deleteNode = nextNode;
				}
			}
		}

	}

public:
	void push(T data)
	{
		// 1. size가 리스트를 넘어가면..? 
		if (size >= SIZE)		// size? list[SIZE] vs vertex[SIZE}
		{
			cout << "AdjacencyList is overflow" << endl;

			// return 해야하나? 안해도되네 
		}

		else
		{
			// 2. data 증가 시키기(?)
			vertex[size++] = data;

		}
	}

	void edge(int i, int j)			// 무슨 매번 어렵지않대요...머리터지겟구만ㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠ 
	{
		if (size <= 0)
		{
			cout << "AdjacencyList is empty" << endl;
		}

		else if (i >= size || j >= size)
		{
			cout << "AdjacencyList index out of Range" << endl;
		}
		else
		{
			// i에서 j로 연결 (j를 i의 리스트에 넣기)
			list[i] = new Node(vertex[j], list[i]);

			// j에서 i로도 연결 (무방향이니까)
			list[j] = new Node(vertex[i], list[j]);

		}

	}

	friend ostream& operator << (ostream& ostream, const AdjacencyList<T>& adjacencyList)
	{
		for (int i = 0; i < adjacencyList.size; i++)
		{
			ostream << adjacencyList.vertex[i] << " : ";

			typename AdjacencyList<T>::Node* currentNode = adjacencyList.list[i];

			while (currentNode != nullptr)
			{
				ostream << currentNode->data << " ";

				currentNode = currentNode->next;
			}

			ostream << endl;
		}

		return ostream;
	}


};

int main()
{
	AdjacencyList<char> adl;
	adl.push('A');
	adl.push('B');
	adl.push('C');

	adl.edge(0, 1);
	adl.edge(0, 2);

	cout << adl << endl;
	return 0;
}