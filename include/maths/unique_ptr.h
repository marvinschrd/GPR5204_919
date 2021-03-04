#pragma once
/*
MIT License

Copyright (c) 2021 SAE Institute Geneva

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <utility>
#include  <memory>

namespace Maths {

template<typename T>
class Unique_ptr
{
public:
	Unique_ptr() : ptr_(nullptr) {}
	// copy constructor
	Unique_ptr(const Unique_ptr& ptr) = delete;
	//explicit constructor
	explicit Unique_ptr(T* p) noexcept : ptr_(p) {}
	// move constructor
	Unique_ptr(Unique_ptr&& ptr) noexcept : ptr_(std::move(ptr.operator->()))
	{
		ptr.ptr_ = nullptr;
	}
	
	~Unique_ptr() // destructor
	{
		if(this != nullptr)
		{
			delete ptr_;
		}
	}
	
	// copy assignment
	Unique_ptr<T>& operator=(const Unique_ptr<T>& ptr) = delete;
	// move assignment
	Unique_ptr<T>& operator=(Unique_ptr<T>&& ptr) noexcept 
	{
		if(this != &ptr)
		{
			ptr_ = std::move(ptr.ptr_);
			ptr.ptr_ = nullptr;
		}
		return *this;
	}

	T* operator->() const { return ptr_; }
	T& operator*()  const { return *ptr_; }
	
private:
	T* ptr_;
};

template<class T, class...Args>
//std::enable_if_t<!std::is_array<T>::value, Unique_ptr<T>>
Unique_ptr<T> MakeUnique(Args&&...args) {
	return Unique_ptr<T>(new T(std::forward<Args>(args)...));
}
	
} // namespace maths
	