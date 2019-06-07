#ifndef __RECT_H__
#define __RECT_H__
#include <iostream>
class Rect
{
public:
	Rect(float x, float y, float width, float height);
	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;
	void set(float x, float y, float width, float height);
	void prfloat()
	{
		std::cout << "x " << this->x << std::endl;
		std::cout << "y " << this->y << std::endl;
		std::cout << "w " << this->width << std::endl;
		std::cout << "h " << this->height << std::endl;
	}

private:
	float x, y;
	float width, height;
};

#endif
