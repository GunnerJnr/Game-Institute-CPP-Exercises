// include header files
#include "vector2.h"

// Default Constructor
Vector2::Vector2() :
m_x(0.0f),
m_y(0.0f)
{

}
//-------------------------------------------------------

// Constructor
Vector2::Vector2(float x, float y) :
m_x(x),
m_y(y)
{

}
//-------------------------------------------------------

// Copy Constructor
Vector2::Vector2(const Vector2& v) :
m_x(v.GetXPos()),
m_y(v.GetYPos())
{

}
//-------------------------------------------------------

// Destructor
Vector2::~Vector2()
{

}
//-------------------------------------------------------

// Get the X Position
float Vector2::GetXPos() const
{
	// return m_x 
	return m_x;
}
//-------------------------------------------------------

// Set the X Position
void Vector2::SetXPos(const float x)
{
	// assign m_x to x
	m_x = x;
}
//-------------------------------------------------------

// Get the Y Position
float Vector2::GetYPos() const
{
	// return m_y
	return m_y;
}
//-------------------------------------------------------

// Set the Y Position
void Vector2::SetYPos(const float y)
{
	// assign m_y to y
	m_y = y;
}
//-------------------------------------------------------

// overload the += (plus-equal) operator
Vector2& Vector2::operator+=(const Vector2& v)
{
	// add the value inside the vectors we take in
	m_x += v.GetXPos();
	m_y += v.GetYPos();
	// return this instance
	return (*this);
}
//-------------------------------------------------------

// overload the -= (minus-equal) operator
Vector2& Vector2::operator-=(const Vector2& v)
{
	// subtract the values inside the vectors we take in
	m_x -= v.GetXPos();
	m_y -= v.GetYPos();
	// return this instance
	return (*this);
}
//-------------------------------------------------------

// overload the + (addition) operator
Vector2 Vector2::operator+(const Vector2& v) const
{
	// create a new instance of vector2 and init it to dereferenced instance of this
	Vector2 temp(*this);
	// utilize the above overloaded method
	temp += v;
	// return the temp to be copied over
	return temp;
}
//-------------------------------------------------------

// overload the - (subtraction) operator
Vector2 Vector2::operator-(const Vector2& v) const
{
	// create a new instance of vector2 and init it to dereferenced instance of this
	Vector2 temp(*this);
	// utilize the above overloaded method
	temp -= v;
	// return the temp to be copied over
	return temp;
}
//-------------------------------------------------------