#ifndef _VECTOR2_H
#define _VECTOR2_H

// Vector2 Class
class Vector2
{
public:
	
	Vector2();									
	Vector2(float x, float y);
	Vector2(const Vector2&);
	~Vector2();									

	float GetXPos() const;						// Get the X Position
	void SetXPos(const float x);				// Set the X Position
	float GetYPos() const;						// Get Y Position
	void SetYPos(const float y);				// Set the Y Position

	Vector2& operator+=(const Vector2& v);		// overload the += (plus-equal) operator
	Vector2& operator-=(const Vector2& v);		// overload the -= (minus-equal) operator
	Vector2 operator+(const Vector2& v) const;	// overload the + (addition) operator
	Vector2 operator-(const Vector2& v) const;	// overload the - (subtraction) operator

private:
	// private variables
	float m_x;
	float m_y;
};

#endif //!_VECTOR2_H