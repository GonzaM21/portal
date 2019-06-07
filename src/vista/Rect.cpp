#include "Rect.h"

Rect::Rect(float x, float y, float width, float height) {
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
}

float Rect::getX() const
{
	return this->x;
}
float Rect::getY() const
{
	return this->y;
}
float Rect::getWidth() const
{
	return this->width;
}
float Rect::getHeight() const
{
	return this->height;
}

void Rect::set(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}