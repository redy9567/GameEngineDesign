#pragma once
#include "Common.h"
#include <Node2D.hpp>
#include <vector>
#include "Component.h"

typedef unsigned int EntityID;

class Entity : public Node2D
{

	GODOT_CLASS(Entity, Node2D);

	//Component* components; OR MAYBE A VECTOR?
	
	

public:
	static void _register_methods();
	void _init();

	void _notification(int p_what);
	void _ready();
	void _process(float delta);
	void _physics_process(float delta);
	void _draw();

	int getID();

private:
	EntityID mID;
	vector<Component*> components;

	Ref<Texture> mSpriteComponentTexture;


	//SpriteComponentData that is only used to display in Godot editor (Passes on data to component)
	
};
