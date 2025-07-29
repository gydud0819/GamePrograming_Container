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
		if (list!=nullptr)
		{
			for (int i = 0; i < SIZE; i++)
			{

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
			list[i] = new Node(vertex[j], list[i]);
			list[j] = new Node(vertex[i], list[j]);

		}
		// 이게 뭔데 이거 맞나 효야 push back느낌이라매 
		//Node* newNode = new Node;				// () 안에 데이터랑 주소넣기? (data, &data) 이런거? 
		//newNode->data = j;
		//newNode->next = nullptr;

		//newNode->next = list[i];
		//list[i] = newNode->data;
	}

};

int main()
{
	AdjacencyList<char> adl;
	adl.push('A');
	adl.push('B');
	adl.push('C');

	adl.edge(0, 2);
	return 0;
}