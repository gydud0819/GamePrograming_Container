#include "Util.h"
#define SIZE 5

template<typename T>
class Stack
{
private:
	int count;		// (원소)개수가 맞나 
	int highset;	// top(제일 꼭대기)
	// 정적 배열
	T container[SIZE];	// ? 
public:
	Stack() : count(0), highset(-1)
	{
		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}
	~Stack()
	{
		// 소멸자 
	}
public:
	void push(T data)
	{
		if (highset + 1 >= SIZE) // 10부터 50까지 넣는데 50을 초과하면? 뭐가 이상한데 container[SIZE]하면 안됫네 ㅇㅅㅇ
		{
			cout << "Stack overFlow" << endl;
		}

		else
		{
			container[++highset] = data;	// ++에 data하는거랑 highset하는거랑 차이큰가?
		}
	}

	// 스택에 쌓인게 모두 비었는지 확인하는거 
	bool isEmpty()
	{
		return (highset == -1);		// 생성자 초기화할때 -1로 했으니까 비었는지 확인하려면 return으로 highset == -1 하기 
	}

	// 위에서부터 꺼내는거니까 감소해야할듯
	void pop()
	{
		if (isEmpty())
		{
			cout << "Stack is empty" << endl;
		}
		//container[--highset];
		highset--;		// 꼭대기에 있는거부터 제거해야하니까 이게 맞는듯 

	}

	const int& size()	// 사이즈 측정하는거 
	{
		return (highset + 1);
	}

	const T& top()		// 이건 용도가 뭐지 
	{
		// 이거 필요없네 
		if (isEmpty())
		{
			cout << "Stack is empty" << endl;
		}
		return container[highset];
	}
};

//class Stack 
//{
//private:
//    int top;
//    int capacity;
//    T* container;
//
//public:
//    Stack(int cap = 100) 
//    {
//        capacity = cap;
//        container = new T[capacity];
//        top = -1;
//    }
//
//    ~Stack() {
//        delete[] container;
//    }
//
//    void push(const T& data) {
//        if (top + 1 >= capacity) {
//            throw std::overflow_error("Stack is full");
//        }
//        container[++top] = data;
//    }
//
//    void pop() {
//        if (isEmpty()) {
//            throw std::underflow_error("Stack is empty");
//        }
//        top--;
//    }
//
//    T& peek() const {
//        if (isEmpty()) {
//            throw std::underflow_error("Stack is empty");
//        }
//        return container[top];
//    }
//
//    bool isEmpty() const {
//        return top == -1;
//    }
//
//    int size() const {
//        return top + 1;
//    }
//};

int main()
{
	Stack<int> stack;
	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.push(50);
	stack.push(60);

	while (stack.isEmpty() == false)
	{
		cout << stack.top() << endl;

		stack.pop();
	}

	cout << stack.size();

	return 0;
}