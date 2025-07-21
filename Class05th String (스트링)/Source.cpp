#include "Util.h"

class String	// 문자열 == 문자들의 배열 [] <- 쓰는건가 
{
	// 길이? 
	int size;		// ?
	char* pointer;	// ???

public:
	String() : size(0), pointer(nullptr) {}
	String(int _size, char* _pointer) : size(_size), pointer(_pointer) {}
	~String()
	{
		delete[] pointer;
	}
public:
	void operator = (const char* word)
	{
		// 주석 달아도 이해안갈거 같은데 
		size = strlen(word) + 1;		// 길이 = word의 길이에 +1 하기 ('\0' <- 포함해야해서)
		if (pointer == nullptr)
		{
			pointer = new char[size];
			// word의 문자열을 포인터 배열에 그대로 복사 (깊은복사임)
			for (int i = 0; i < size; i++)
				pointer[i] = word[i];
		}
		else
		{
			// 
			char* temporary = new char[size];
			for (int i = 0; i < size; i++)
				temporary[i] = word[i];
			delete[] pointer;
			pointer = temporary;
		}

	}

	// 문자열 길이 구하기(?)
	const int& length()
	{
		return size - 1;		// '\0' <- 빼야한다? 먼소리여 
	}

	const char& operator [] (const int& index)
	{
		return pointer[index];
	}

	// 덧붙이다? 추가하다? 
	void append(const char* word)	// word ex) ace
	{
		int privousSize = size;		// adidas + \0
		size = size + strlen(word) + 1; // size 더해주기 

		// 분기문 써야하나 while? 

		// 이걸 해줘야하는건가 안해도 될거같은데 새로있는거 아닌가 
		// 한번밖에 안돌아가면 while 써야하나 아예 쓰면 안되는건가 

		// 음 한계다 어떡하지 모르겟다 

		// 문자열의 길이만큼 채워준다? heap에? 
		char* container = new char[size];

		for (int i = 0; i < privousSize; i++)
		{
			container[i] = pointer[i];
		}

		for (int i = 0; i < strlen(word); i++)
		{
			container[privousSize + i] = word[i]; // 기존 문자에서 더해야하니까 
		}
		delete[] pointer;
		pointer = container;


	}

	// 문자열 매칭하기 
	unsigned long long find(const char* word)
	{
		int length = size;
		size = strlen(word);		// ? 

		// 매칭했을 때 안맞으면 넘기기 
		// 4번만 돌리면 된다는데 ㅓ................
		int i = 0;
		int j = 0;

		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < strlen(word); j++)
			{
				if (pointer[i + j] != word[j])
				{

					break;
				}
			}

			if (j == strlen(word))
			{
				return i;
			}
		}
		return 18446744073709551615;	// ? ??????
	}

};



int main()
{
	String message;
	message = "LoL";
	message = "Adidas";
	for (int i = 0; i < message.length(); i++)
	{
		cout << message[i];
	}
	message.append(" NewBalance");

	cout << endl;

	for (int i = 0; i < message.length(); i++)
	{
		cout << message[i];
	}
	cout << endl;
	cout << message.find("Adi");

	/*Queue<int> que(6);
	que.enqueue(10);
	que.enqueue(20);
	que.enqueue(30);
	que.enqueue(40);

	que.dequeue();
	que.dequeue();
	que.dequeue();
	que.dequeue();*/

	return 0;
}