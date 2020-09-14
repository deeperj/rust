#include "Point2D.h"

Point2D::Point2D(int y, int x)
{
	mx = x;
	my = y;
}

int Point2D::getX()
{
	return mx;
}

int Point2D::getY()
{
	return my;
}