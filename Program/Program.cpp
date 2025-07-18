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

	}
public:
	void operator = (const char* word)
	{
		// 주석 달아도 이해안갈거 같은데 
		size = strlen(word) + 1;		// 길이 = word의 길이에 +1 하기 ('\0' <- 포함해야해서)
		if (pointer == nullptr)			// 아무것도 가리키지않을때
		{
			pointer = new char[size];	// 새로 할당하기? 문자열의 길이만큼? 

			for (int i = 0; i < size; i++)
			{
				pointer[i] = word[i];	// 복사해서 담기(?)
			}
		}
		else
		{
			char* temporary = new char[size];		// 이건 뭐야 

			for (int i = 0; i < size; i++)	// 사이즈만큼 돌리고
			{
				temporary[i] = word[i];	 // 복사해서 가리키는 값을 담는다?
			}
			delete[] pointer;		// 재할당해야해서 지워주기 -> word의 League of Lengend 지워주기(?)

			pointer = temporary;
		}
	}

	// 문자열 길이 구하기(?)
	const int& length()
	{
		return size - 1;		// '\0' <- 빼야한다? 먼소리여 
	}
};

int main()
{
	String message;
	message = "League of Lengend";
	message = "Adidas";
	
	cout<< message.length();

	return 0;
}