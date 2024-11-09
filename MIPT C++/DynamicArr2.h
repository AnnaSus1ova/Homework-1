#pragma once

#include <iostream>

template <class T>
class DynamicArr
{
	static const size_t initialCapacity_ = 2; // only one for all objects of DynamicArr
	static const double coeff_;				  // same as above

	size_t size_ = 0;
	size_t capacity_ = initialCapacity_;
	T *arr_;

public:
	DynamicArr();
	explicit DynamicArr(size_t size, T element = 0);
	DynamicArr(const DynamicArr<T> &rhs);
	DynamicArr(DynamicArr<T> &&rhs);
	~DynamicArr();
	size_t size() const;
	size_t capacity() const;
	void push_back(T elem);
	T &operator[](size_t index);
	const T &operator[](size_t index) const;
	DynamicArr<T> &operator=(const DynamicArr<T> &rhs);
	DynamicArr<T> &operator=(DynamicArr<T> &&rhs);
};

template <typename T>
std::ostream &operator<<(std::ostream &stream, const DynamicArr<T> &arr)
{
	if (arr.size() == 0)
	{
		stream << "Array is empty";
		return stream;
	}
	for (size_t i = 0; i < arr.size(); i++)
	{
		stream << arr[i] << ' ';
	}
	return stream;
}

void fun();

template <class T>
const double DynamicArr<T>::coeff_ = 2;

template <class T>
DynamicArr<T>::DynamicArr()
{
	arr_ = new T[capacity_];
}

template <class T>
DynamicArr<T>::DynamicArr(size_t size, T elem) : size_(size), capacity_(coeff_ * size_), arr_(new T[capacity_])
{
	for (size_t i = 0; i < size_; ++i)
	{
		arr_[i] = elem;
	}
}

template <class T>
DynamicArr<T>::DynamicArr(const DynamicArr<T> &rhs)
{
	size_ = rhs.size_;
	capacity_ = rhs.capacity_;
	arr_ = new T[capacity_];
	for (size_t i = 0; i < size_; ++i)
	{
		arr_[i] = rhs.arr_[i];
	}
}

template <class T>
DynamicArr<T>::DynamicArr(DynamicArr<T> &&rhs)
{
	size_ = std::move(rhs.size_);
	capacity_ = std::move(rhs.capacity_);
	arr_ = new T[capacity_];
	for (size_t i = 0; i < size_; i++)
	{
		arr_[i] = std::move(rhs.arr_[i]);
	}
}

template <class T>
DynamicArr<T>::~DynamicArr()
{
	delete[] arr_;
}

template <class T>
size_t DynamicArr<T>::size() const
{
	return size_;
}

template <class T>
size_t DynamicArr<T>::capacity() const
{
	return capacity_;
}

template <class T>
void DynamicArr<T>::push_back(T elem)
{
	if (size_ == capacity_)
	{
		capacity_ = coeff_ * capacity_;
		T *tmp = new T[capacity_];
		for (size_t i = 0; i < size_; ++i)
		{
			tmp[i] = arr_[i];
		}
		delete[] arr_;
		arr_ = tmp;
	}
	arr_[size_++] = elem;
}

template <class T>
const T &DynamicArr<T>::operator[](size_t index) const
{
	return arr_[index];
}

template <class T>
T &DynamicArr<T>::operator[](size_t index)
{
	return arr_[index];
}

template <class T>
DynamicArr<T> &DynamicArr<T>::operator=(const DynamicArr<T> &rhs)
{
	if (this == &rhs)
		return *this;
	delete[] arr_;
	arr_ = new T[rhs.capacity()];
	for (int i = 0; i < rhs.size(); ++i)
	{
		arr_[i] = rhs[i];
		std::cout << arr_[i] << " ";
	}
	return *this;
}

template <class T>
DynamicArr<T> &DynamicArr<T>::operator=(DynamicArr<T> &&rhs)
{
	if (this == &rhs)
		return *this;
	delete[] arr_;
	arr_ = new T[rhs.capacity()];
	for (int i = 0; i < rhs.size(); ++i)
	{
		arr_[i] = std::move(rhs[i]);
		std::cout << arr_[i] << " ";
	}
	return *this;
}
