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
#define _USE_MATH_DEFINES
#include <math.h>
#include "maths/vector2.h"
namespace maths {
	
class Circle
{
public:
	Circle() = default;
	Circle(float radius, Vec2f center) : radius_(radius), center_(center) {};
	~Circle() = default;

	float area() const {
		return ( M_PI * (radius_ * radius_) );
	}
	
	void set_radius( const float radius) { radius_ = radius; }
	Vec2f center() const { return center_; }
	float radius() const { return radius_; }
		
private:
	Vec2f center_ = {};
	float radius_ = {};
};
	
} // namespace maths