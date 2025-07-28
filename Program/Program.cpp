#include "Util.h"

// 그래프 구현 예정
#pragma region 그래프 (Graph)
/*
* 정점과 간선으로 구성 (Vertex, Edge)
* 방향 그래프 : 특정한 방향으로 연결
* 무뱡향 그래프 : 점이 2개 연결된거야 선이 2개 연결된거야 (2개가 연결되어있는 구조)
* 진출 차수 : 어떤 지점으로부터 나가는 거(?)
* 진입 차수 : 어떤 지점으로부터 들어오는 거(?)
* 그래프의 표현 방법
* 인접 행렬 - 인접 리스트 (단일 연결 리스트로 연결(?)
* 2차원 배열 - 포인터 배열
*
*
*
*
*
*
*
*
*
*
*
*
*/

#pragma endregion

template <typename T>
class AdjacencyMatrix
{
private:
	// 정점의 개수
	int size;

	int** matrix;
	int matrixCount;
	// 정접의 집합
	T* vertex;				// 나중에 벡터로 해봐야할듯
	// 인접 행렬의 최대 용량
	int capacity;
	// 인접 행렬

public:
	AdjacencyMatrix() : size(0), vertex(nullptr), capacity(0) {}		// 초기화 어케함 
	~AdjacencyMatrix()
	{

	}
public:
	void resize(int newSize)		// 벡터 resize 갖고 와서 써도된다는겅가 
	{
		// 1. capacity에 새로운 size값 저장하기
		capacity = newSize;		// 이게 아닌거 같은데 

		// 2. 새로운 포인터 변수를 생성하고 새롭게 만들어진 메모리 공간을 가리키도록 하기
		T* newContainer = new T[capacity];

		// 3. 새로운 메모리 공간의 값 초기화하기
		for (int i = 0; i < capacity; i++)
		{
			newContainer[i] = T();	// NULL도 가능

		}

		// 4. 기존 배열에 있는 값을 복사해서 새로운 배열에 넣어주기 
		for (int i = 0; i < size; i++)
		{
			newContainer[i] = vertex[i];
		}

		// 5. 기존 배열의 메모리 해제하기
		if (vertex != nullptr)
			delete[] vertex;

		// 6. 기존 배열을 가리키던 포인터 변수의 값을 새로운 배열의 시작 주소로 가리키기 
		vertex = newContainer;

	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}

		else if (size >= capacity)
		{
			resize(capacity * 2);
		}

		vertex[size++] = data;
	}

	// 인접 행렬의 메모리를 새로 생성하는 함수 
	void resize()
	{
		int** newMatrix = new int* [size];
		// 1. 기존에 있던 matrix 데이터 옮기기 (어디로 옮기는거임 newMatrix?)
		for (int i = 0; i < size; i++)
		{
			newMatrix[i] = new int[size] {0};		// 행 초기화
		}

		for (int i = 0; i < matrixCount; i++)
		{
			for (int j = 0; j < matrixCount; j++)
			{
				newMatrix[i][j] = matrix[i][j];
			}
		}

		// 2. 기존에 있던 행렬 해제하기
		if (matrix != nullptr)
		{
			for (int i = 0; i < matrixCount; i++)
			{
				delete[] matrix[i];

			}

			delete[] matrix;
		}

		// 3. matrix 포인터가 새로 만들어진 행렬을 가리키게 한 다음 행렬의 크기 다시 설정하기
		matrix = newMatrix;
		matrixCount = size;
	}

	void edge(int i, int j)		// i = 행, j = 열
	{

		// 1. vetex가 없는 상태에서 연결하면 인접 행렬이 없다고 출력로그 띄우기
		if (size == 0)
		{
			cout << "AdjacencyMatrix is empty" << endl;
		}

		// 2. vertex의 크기 범위를 벗어나게 되면 연결이 되지 않도록 하기 (else if 써야하는 듯)
		else if (i >= size || j >= size)
		{
			cout << "Unconnected" << endl;
		}

		// 3. 인접 행렬이 없을 때 정점의 크기만큼 인접 행렬 생성하기 
		else
		{
			if (matrix == nullptr)
			{
				matrixCount = size;
				matrix = new int* [size];

				for (int i = 0; i < size; i++)
				{
					matrix[i] = new int[size];
				}

				for (int i = 0; i < size; i++)
				{
					for (int j = 0; j < size; j++)
					{
						matrix[i][j] = 0;
					}
				}
			}
			else if (matrixCount < size)
			{
				resize();
			}

			// 여따가 하나보네 이거 맞나

		}
		
		// ㅏ? 
	}

};

// 내일 인접 리스트 한다구용..? 
int main()
{
	AdjacencyMatrix<int> adm;
	adm.push(1);
	adm.push(5);
	adm.push(9);

	adm.edge(0,1);
	// 멀 하라고 했던거 같은데 그게 머엿지			 

	//ostream & operator <<(ostream, const AdjacencyMatrix &)
	
	return 0;
}