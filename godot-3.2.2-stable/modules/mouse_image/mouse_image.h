#pragma once

#include "core/reference.h"

class MouseImage : public Reference {
	GDCLASS(MouseImage, Reference);

private:
	int x, y;

protected:
	static void _bind_methods();

public:
	void setX(int);
	void setY(int);

	int getX();
	int getY();

	MouseImage();
	~MouseImage();

};
