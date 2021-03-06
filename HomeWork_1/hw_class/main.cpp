#include <iostream>
#include <cstring>
using namespace std;

class String
{
	char* str = nullptr;
	unsigned size = 0;
public:
	String(const char* s)
	{
		if (s && *s)
		{
			size = strlen(s) + 1;
			str = new char[size];
			strcpy_s(str, size, s);
		}
		else
		{
			size = strlen("Unknown") + 1;
			str = new char[size];
			strcpy_s(str, size, "Unknown");
		}

	}
	~String()
	{
		if (str)
		{
			delete[] str;
			str = nullptr;
		}
	}
	void Assign(const char*);
	void Concat(const char*);
	void Addsymbol(const char,const int);
	void Ansicode();
	char* Upperstr()
	{
		_strupr_s(str, size);
		return str;
	}
	char* Lowerstr()
	{
		_strlwr_s(str, size);
		return str;
	}

	const char* get_str()
	{
		return str;
	}
	const int get_size()
	{
		return size;
	}

};

int main()
{
	String s1("");
	cout << s1.get_str() << endl;
	cout << s1.get_size() << endl;
	s1.Assign("Hello");
	cout << s1.get_str() << endl;
	cout << s1.get_size() << endl;
	s1.Concat(" world!");
	cout << s1.get_str() << endl;
	cout << s1.get_size() << endl;
	s1.Addsymbol('A', 3);
	cout << s1.get_str() << endl;
	cout << s1.get_size() << endl;
	s1.Ansicode();
	cout << s1.Upperstr() << endl;
	cout << s1.Lowerstr() << endl;
	system("pause");

	return 0;
}
void String::Assign(const char*s)
{
	if (s && *s)
	{
		delete[] str;
		size = strlen(s) + 1;
		str = new char[size];
		strcpy_s(str, size, s);
	}

}
void String::Concat(const char*s)
{
	if (s && *s)
	{
		size += strlen(s);
		char* newstr = new char[size];
		strcpy_s(newstr, size, str);
		strcat_s(newstr, size, s);
		delete[] str;
		str = newstr;
	}


}
void String::Addsymbol(const char c, const int pos)
{
	if (c)
	{
		if (pos <= 0 || pos > size)
		{
			cout << "incorrect value" << endl;
			return;
		}
		++size;
		char* newstr = new char[size];
		for (int i = size, j = 1; i >= 0; --i)
		{
			if (i == pos - 1)
			{
				newstr[i] = c;
				--j;
				continue;
			}
			newstr[i] = str[i - j];
		}
		delete[]str;
		str = newstr;
	}
}
void String::Ansicode()
{
	for (int i = 0; i < size; ++i)
	{
		cout << str[i] << " = " << (int)str[i] << endl;
	}
}