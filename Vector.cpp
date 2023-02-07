#include "Vector.h"

template <class T>
Vector<T>::Vector() : size {2}, next_slot {0}, v_arr {new T[size]} {
	cout << "Default constructor is called!" << endl;
}

template <class T>
Vector<T>::Vector(int s) : size {s}, next_slot {0}, v_arr {new T[size]} {
	cout << "Parameterized constructor is called!" << endl;
}

template <class T>
Vector<T>::~Vector()
{
	cout << "Destructor is called!" << endl;
	delete[] v_arr;
}

template <class T>
Vector<T>::Vector(const Vector& rhs)
{
	cout << "Copy constructor is called!" << endl;
	size = rhs.size;
	next_slot = rhs.next_slot;
	v_arr = new T[size];
	for (int i {0}; i < next_slot; ++i)
		v_arr[i] = rhs.v_arr[i];
}

template <class T>
Vector<T>::Vector(Vector&& vec) noexcept
{
	cout << "Move constructor is called!" << endl;
	size = vec.size;
	next_slot = vec.next_slot;
	v_arr = vec.v_arr;
	vec.size = 0;
	vec.next_slot = 0;
	delete[] vec.v_arr;
	vec.v_arr = nullptr;
}

template <class T>
void	Vector<T>::swap_v(Vector& oth) noexcept
{
	swap(size, oth.size);
	swap(next_slot, oth.next_slot);
	swap(v_arr, oth.v_arr);
}

template <class T>
Vector<T>&	Vector<T>::operator=(const Vector& ve)
{
	cout << "Copy assignment operator is called!" << endl;
	Vector	temp {ve};
	swap_v(temp);
	return (*this);
}

template <class T>
Vector<T>&	Vector<T>::operator=(Vector&& v) noexcept
{
	cout << "Move assignment operator is called!" << endl;
	Vector	temp {v};
	swap_v(temp);
	return (*this);
}

template <class T>
Vector<T>& Vector<T>::operator+(const Vector& other)
{
	cout << "Overloaded operator + is called!" << endl;
	size += other.size;
	T* temp = new T[size];
	for (int i {0}; i < next_slot; ++i)
		temp[i] = v_arr[i];
	delete[] v_arr;
	v_arr = temp;
	temp = nullptr;
	for (int z {0}; z < other.next_slot; ++z)
		v_arr[next_slot++] = other.v_arr[z];
	return (*this);
}

template <class T>
void	Vector<T>::print_all()
{
	for(int i {0}; i < next_slot; ++i)
	{
		cout << v_arr[i] << " ";
	}
	cout << endl;
}

template <class T>
void	Vector<T>::push_b(T val)
{
	if (next_slot == size)
	{
		size *= 2;
		T *tmp = new T[size];
		for (int i {0}; i < next_slot; ++i)
			tmp[i] = v_arr[i];
		delete[] v_arr;
		v_arr = tmp;
		tmp = nullptr;
	}
	v_arr[next_slot++] = val;
	cout << "New number added!" << endl;
}

