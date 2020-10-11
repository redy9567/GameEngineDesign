#include "Entity.h"
#include "SpriteComponent.h";
#include "LocationComponent.h";
#include <Engine.hpp>

void Entity::_register_methods()
{

	register_method("_ready", &Entity::_ready);
	register_method("_process", &Entity::_process);
	register_method("_physics_process", &Entity::_physics_process);
	register_method("_notification", &Entity::_notification);
	register_method("_draw", &Entity::_draw);

	register_property("Sprite Component Texture", &Entity::mSpriteComponentTexture, Ref<Texture>());
	
}

void Entity::_init()
{

	cout << "Entity Init! Adding Sprite Component!" << endl;
	SpriteComponent* spriteComponent = new SpriteComponent();

	spriteComponent->mX = 50;
	spriteComponent->mY = 50;

	components.push_back(spriteComponent);


	LocationComponent* locationComponent = new LocationComponent();

	locationComponent->mX = 150;
	locationComponent->mY = 250;

	components.push_back(locationComponent);
	
	
	spriteComponent->registerProperties();
}

void Entity::_notification(int p_what)
{
	//cout << "Notify!";
}

void Entity::_ready()
{
	//cout << "Ready!";
}

void Entity::_process(float delta)
{
	if (Engine::get_singleton()->is_editor_hint())
	{
		
		for (Component* c : components)
		{
			c->editorProcess(delta);

		}
	}
	else
	{
		for (Component* c : components)
		{
			c->process(delta);

		}
	}

	for (Component* c : components)
	{
		if (typeid(*c) == typeid(SpriteComponent))
		{
			//cout << "update sprite";
			((SpriteComponent*)c)->mSprite = mSpriteComponentTexture;
		}
		

	}
}

void Entity::_physics_process(float delta)
{
}

void Entity::_draw()
{

	for (Component* c : components)
	{
		c->draw();

	}

}

int Entity::getID()
{
	return mID;
}
