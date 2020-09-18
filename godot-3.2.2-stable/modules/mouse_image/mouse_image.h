#pragma once

using namespace std;

#include <string>
#include "scene/2d/sprite.h"

class MouseImage : public Sprite {
	GDCLASS(MouseImage, Sprite);

private:
	int x, y;
	String mPath;

protected:
	static void _bind_methods();
	void MouseImage::_notification(int i);

public:
	int getX();
	int getY();

	void setLocation(int x, int y);
	void setImagePath(String path);

	String getPath();

	void updateImage();

	MouseImage();
	~MouseImage();

};
