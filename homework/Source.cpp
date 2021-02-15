#include <cstdlib> 
#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class MyVector{
private:
	
	int size;
	int capacity = 15;
	T* buffer = new T[capacity];
public:
	 MyVector(int size) {
		capacity = size;
	}
	MyVector()
	{

	}
	void push_back(const T& elem) {
		if (size == capacity) {
			capacity *= 2;
			T* tmp = new T[capacity];
			for (int ix = 0; ix < size; ++ix) {
				tmp[ix] = buffer[ix];
			}
			delete[] buffer;
			buffer = tmp;
		}
		buffer[size] = elem;
		++size;
	}
	T at(int i) {
		if (i <= capacity) {
			return buffer[i];
		}
		else {
			cout << "Out of range" << endl;
		}
	}

	T& operator[](int index)
	{
		if (index >= size) {
			cout << "Array index out of bound, exiting";
		}
		return buffer[index];
	}
};
int main()
{  
	MyVector<int> v(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(3);
	//cout << v.at(5);
	cout << v[0];
}