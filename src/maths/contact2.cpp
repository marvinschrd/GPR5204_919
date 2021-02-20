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

#include "maths/aabb2.h"

namespace maths {

bool Overlap(const AABB2& a, const AABB2& b) {
	const Vector2f v1 = b.bottom_left() - a.top_right();
	const Vector2f v2 = a.bottom_left() - b.top_right();

	return !(v1.x > 0 || v2.x > 0 || v1.y > 0 || v2.y > 0);
}

bool Contain(const AABB2& a, const AABB2& b) {
	const Vector2f v1 = b.bottom_left() - a.bottom_left();
	const Vector2f v2 = a.top_right() - b.top_right();

	return (v1.x >= 0 && v1.y >= 0 && v2.x >= 0 && v2.y >= 0);
}
	
}  // namespace maths