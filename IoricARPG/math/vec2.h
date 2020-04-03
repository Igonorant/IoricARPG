#pragma once

class Vec2
{
public:
	// Constructors
	Vec2()
		:x(0), y(0)
	{}
	Vec2(float x, float y)
		:x(x),y(y)
	{}

	// Operations
	Vec2 operator+ (const Vec2& rhs)
	{
		Vec2 result;
		result.x = this->x + rhs.x;
		result.y = this->y + rhs.y;
		return result;
	}
	Vec2 operator- (const Vec2& rhs)
	{
		Vec2 result;
		result.x = this->x - rhs.x;
		result.y = this->y - rhs.y;
		return result;
	}
	Vec2 operator* (const float& factor)
	{
		Vec2 result;
		result.x = this->x * factor;
		result.y = this->y * factor;
		return result;
	}
	Vec2 operator* (const Vec2& rhs)
	{
		Vec2 result;
		result.x = this->x * rhs.x;
		result.y = this->y * rhs.y;
		return result;
	}
	Vec2 operator/ (const float& factor)
	{
		Vec2 result;
		result.x = this->x / factor;
		result.y = this->y / factor;
		return result;
	}

	Vec2& operator+= (const Vec2& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;
		return *this;
	}
	Vec2& operator-= (const Vec2& rhs)
	{
		this->x -= rhs.x;
		this->y -= rhs.y;
		return *this;
	}

public:
	float x;
	float y;
};