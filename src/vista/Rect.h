#ifndef __RECT_H__
#define __RECT_H__
#include <iostream>

/**
 * Clase rect, la cual delimita un area, ya sea para setar el origen de un sprite o el destino
 **/
class Rect {
public:
	
	/**
	 * Constructor
	*/
	Rect(float x, float y, float width, float height);

	/**
	 * Getters de los atributos
	*/
	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;

	/**
	 * setter de los atributos
	*/
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
