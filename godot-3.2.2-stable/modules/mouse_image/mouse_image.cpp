#include "mouse_image.h"

MouseImage::MouseImage() {

	x = 0;
	y = 0;
	mPath = "";
}

MouseImage::~MouseImage() {
}

int MouseImage::getX() {
	return x;
}

int MouseImage::getY() {
	return y;
}

void MouseImage::setLocation(int x, int y) {

	this->x = x;
	this->y = y;
}

void MouseImage::setImagePath(String path) {

	mPath = path;
}

String MouseImage::getPath() {
	return mPath;
}

void MouseImage::updateImage() {

	printf("Update Image");
	set_texture(ResourceLoader::load(mPath));
}

void MouseImage::_bind_methods() {

	ClassDB::bind_method(D_METHOD("getX"), &MouseImage::getX);
	ClassDB::bind_method(D_METHOD("getY"), &MouseImage::getY);
	ClassDB::bind_method(D_METHOD("setLocation", "x", "y"), &MouseImage::setLocation);
	ClassDB::bind_method(D_METHOD("setImagePath", "path"), &MouseImage::setImagePath);
	ClassDB::bind_method(D_METHOD("getPath"), &MouseImage::getPath);
	ClassDB::bind_method(D_METHOD("updateImage"), &MouseImage::getPath);
}

void MouseImage::_notification(int i) {
	if (NOTIFICATION_PROCESS == i) {
		x = get_global_mouse_position().x;
		y = get_global_mouse_position().y;

		set_global_position(Point2(x, y));

		
	}
	
	if (NOTIFICATION_READY == i) {

		mPath = "res://assassin.png";
		updateImage();

	}
}
