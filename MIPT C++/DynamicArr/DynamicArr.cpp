#include "DynamicArr.h"

#include <iostream>
#include <stdexcept>

const double DynamicArr::coeff_ = 2;

DynamicArr::DynamicArr() {
	arr_ = new double[capacity_];
}

DynamicArr::DynamicArr(size_t size, double elem) : size_(size)
	,capacity_(coeff_* size_)
	,arr_(new double[capacity_]) {
	for (size_t i = 0; i < size_; ++i) {
		arr_[i] = elem;
	}
}

DynamicArr::DynamicArr(const DynamicArr& rhs) {
	size_ = rhs.size_;
	capacity_ = rhs.capacity_;
	arr_ = new double[capacity_];
	for (size_t i = 0; i < size_; ++i) {
		arr_[i] = rhs.arr_[i];
	}
}

DynamicArr::~DynamicArr() {
	delete[] arr_;
}

size_t DynamicArr::size() const {
	return size_;
}

size_t DynamicArr::capacity() const {
	return capacity_;
}

void DynamicArr::push_back(double elem) {
	if (size_ == capacity_) {
		capacity_ = coeff_ * capacity_;
		double* tmp = new double[capacity_];
		for (size_t i = 0; i < size_; ++i) {
			tmp[i] = arr_[i];
		}
		delete[] arr_;
		arr_ = tmp;
	}
	arr_[size_++] = elem;
}
double DynamicArr::operator[](const int index) const {
	if (index < 0 || index >= size())
		throw std::out_of_range("Index out of range");
	return arr_[index];
}

double& DynamicArr::operator[](int index) {
	if (index < 0 || index >= size()) {
		std::cout << size_ << " " << index;
		throw std::out_of_range("Index out of range");
	}
	return arr_[index];
}


DynamicArr &DynamicArr::operator=(const DynamicArr &rhs) {
	if (this == &rhs)
		return *this;
	size_ = rhs.size();
	delete[] arr_;
	arr_ = new double[rhs.capacity()];
	for (int i = 0; i < rhs.size(); ++i) {
		arr_[i] = rhs[i];
	}
	return *this;
}