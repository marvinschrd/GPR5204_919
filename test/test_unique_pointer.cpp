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

#include <gtest/gtest.h>
#include "maths/unique_ptr.h"

namespace Maths {

	TEST(Maths, Unique_Pointeur_MakeUnique)
	{
		//Test MakeUnique
		Unique_ptr<int> ptr = MakeUnique<int>(5);
		EXPECT_EQ(*ptr, 5);
	}
	
	TEST(Maths, Unique_Pointeur_Constructors)
	{
		//Test default
		Unique_ptr<float> a;
		float* ptr = nullptr;
		EXPECT_EQ(a.operator->(), ptr);

		
		//Test move constructor
		Unique_ptr<int> b = MakeUnique<int>(4);
		Unique_ptr<int> c(std::move(b));
		EXPECT_EQ(*c, 4);		
	}

	TEST(Maths, Unique_Pointeur_Assignment)
	{
		//Test move assignment
		Unique_ptr<int> a = MakeUnique<int>(1);
		Unique_ptr<int> b = MakeUnique<int>(2);

		b = std::move(a);
		EXPECT_EQ(*b, 1);

		a = MakeUnique<int>(1);
		b = MakeUnique<int>(2);
		//Test move assignment with himself
		b = std::move(b);
		EXPECT_EQ(*b, 2);
	}
	
	
} // namespace maths