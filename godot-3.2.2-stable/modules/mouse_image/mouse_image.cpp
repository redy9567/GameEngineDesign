#include "mouse_image.h"

MouseImage::MouseImage() {

	x = 0;
	y = 0;
}

MouseImage::~MouseImage() {
}

void MouseImage::setX(int val) {
	x = val;
}

void MouseImage::setY(int val) {
	y = val;
}

int MouseImage::getX() {
	return x;
}

int MouseImage::getY() {
	return y;
}

void MouseImage::_bind_methods() {

	ClassDB::bind_method(D_METHOD("setX", "value"), &MouseImage::setX);
	ClassDB::bind_method(D_METHOD("setY", "value"), &MouseImage::setY);
	ClassDB::bind_method(D_METHOD("getX"), &MouseImage::getX);
	ClassDB::bind_method(D_METHOD("getY"), &MouseImage::getY);

}
