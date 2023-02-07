#include <iostream>
#include <memory>
#include <string>
#include <utility>

using namespace std;

template <class T>

class Vector
{
	private:
		int	size;
		int	next_slot;
		T	*v_arr;
	public:
		Vector();
		Vector(int s);
		~Vector();
		Vector(const Vector& rhs);
		Vector(Vector&& vec) noexcept;
		Vector<T>& operator=(const Vector& ve);
		Vector& operator+(const Vector& other);
		Vector& operator=(Vector&& v) noexcept;
		void	push_b(T val);
		void	swap_v(Vector& oth) noexcept;
		void	print_all();
};
