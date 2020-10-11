#pragma once

#include "Component.h"

class LocationComponent : public Component
{

	GODOT_CLASS(LocationComponent, Node2D);

	//Base class for all components


public:
	LocationComponent();
	~LocationComponent() {};

	static void _register_methods();

	void init();

	void editorReady() override;
	void editorProcess(float delta) override;
	void editorPhysics_process(float delta) override;
	void ready() override;
	void process(float delta) override;
	void physics_process(float delta) override;
	void draw() override;

	void registerProperties();

	friend class Entity;



private:
	int mX = 0
		, mY = 0;

	static InstanceID nextInstanceID;

};
