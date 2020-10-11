#pragma once
#include "Common.h"
#include <Node2D.hpp>

typedef unsigned int InstanceID;

class Component : public Node2D
{

	GODOT_CLASS(Component, Node2D);

	//Base class for all components


public:
	Component() {};
	~Component() {};

	void init();

	static void _register_methods();

	virtual void editorReady();
	virtual void editorProcess(float delta);
	virtual void editorPhysics_process(float delta);
	virtual void ready();
	virtual void process(float delta);
	virtual void physics_process(float delta);
	virtual void draw();

	String getName() { return mName; }
	InstanceID getInstanceID() {return mInstanceID;}


protected:
	String mName = "";
	InstanceID mInstanceID = 0;
	
};
