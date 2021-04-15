#include <iostream>
#include <string>

//template<typename T>
//void Print(T value)
//{
//	std::cout << value << std::endl;
//}

template<typename T, int N>
class Array
{
private:
	T m_Array[N];
public:
	int GetSize() const { return N; }
};

bool constexpr isEven(int x) {
	return x % 2 == 0 ? true : false;
}

constexpr int count_x(const char* p, char x) {
	// count the number of occurrences of x in p
	if (p == nullptr)
		return 0;
	int count = 0;
	//for (; *p != 0; ++p) // p - 1st byte ++p - 1st byte + 1 and so on
	//	if (*p == x)
	//		++count;
	while (*p) {
		if (*p == x)
			++count;
		++p;
	}
	return count;
}

struct Vector
{
	int size;
	double* elements;
};

void init(Vector &v, int size) {
	if (size == 0)
		return;
	v.size = size;
	v.elements = new double[size];
}

void read(int length) {
	if (length == 0)
		return;
	Vector v;
	init(v, length);
	for (size_t i = 0; i != length; i++)
	{
		v.elements[i] = i;
	}
}
int main()
{
	Array<int,5> array;
	std::cout << array.GetSize() << std::endl;
	//Print<std::string>("Joshua");
	int k = 20;
	int&& j = 20;
	int m{ 0b1000 };
	std::cout << m << std::endl;

	constexpr int const_3 = 3;
	constexpr double half = 0.5;
	static_assert(half < const_3, "Yipe!");
	constexpr int test{ const_3 * 20 };
	std::cout << test << std::endl;
	std::cout << isEven(const_3) << std::endl;
	std::cout << isEven(k) << std::endl;
	constexpr auto str = "Hello";
	std::cout << "Count: " << count_x(str, str[2]) << std::endl;


	int v[] = { 0,1,2,3,4,5,6,7,8,9 };
	for (auto& x : v) {
		++x;
		std::cout << x << " ";
	}
	std::cout << std::endl;
	for (auto x : v) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	int y = 4;
	int l = 87;
	int* p = &y;
	int* d = &l;
	p = d;
	*p = 90;
	std::cout << "l = " << l;

}