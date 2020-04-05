#ifndef __RECT_H__
#define __RECT_H__

#include "rtti/ObjectType.h"

struct Point2D
{
	float x;
	float y;
};

struct Point3D : Point2D
{
	float z;
};

class Rect : public rtti::ObjectType<Rect>
{
private:
	RTTI_OBJECT_TYPE_BODY;

	std::string name;
	Point3D top_left;
	Point3D bot_right;

public:
	void print() noexcept
	{
		std::clog << "Rect values:\n"
			<< "\t- name:        " << this->name << '\n'

			<< "\t- bot_right.x: " << this->bot_right.x << '\n'
			<< "\t- bot_right.y: " << this->bot_right.y << '\n'
			<< "\t- bot_right.z: " << this->bot_right.z << '\n'

			<< "\t- top_left.x:  " << this->top_left.x << '\n'
			<< "\t- top_left.y:  " << this->top_left.y << '\n'
			<< "\t- top_left.z:  " << this->top_left.z << '\n';
	}
};

#endif // !__RECT_H__