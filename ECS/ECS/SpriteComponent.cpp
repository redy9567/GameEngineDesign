#include "SpriteComponent.h"
#include <string>

InstanceID SpriteComponent::nextInstanceID = 0;

SpriteComponent::SpriteComponent()
{
	mInstanceID = nextInstanceID++;
	mName = "Sprite Component " + String(mInstanceID);
}

void SpriteComponent::_register_methods()
{

	cout << "Registering Sprite Properties";
	register_property("x_position", &SpriteComponent::mX, 0);
	register_property("y_position", &SpriteComponent::mY, 0);
	//register_property("sprite_texture", &SpriteComponent::mSprite, Ref<Texture>());

}

void SpriteComponent::init()
{
}

void SpriteComponent::editorReady()
{
}

void SpriteComponent::editorProcess(float delta)
{
}

void SpriteComponent::editorPhysics_process(float delta)
{
}

void SpriteComponent::ready()
{
}

void SpriteComponent::process(float delta)
{
	//cout << "[" << mX << ", " << mY << "] ";
	//draw();
}

void SpriteComponent::physics_process(float delta)
{
}

void SpriteComponent::draw()
{
	
	//draw_texture(mSprite, Vector2(mX, mY));
	
	//Drawing a blank texture causes Godot to crash?
	

}

void SpriteComponent::registerProperties()
{
	
}
