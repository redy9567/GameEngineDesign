#pragma once
#include "Component.h"
#include <Texture.hpp>

class SpriteComponent : public Component
{

	GODOT_CLASS(SpriteComponent, Node2D);

	//Base class for all components


public:
	SpriteComponent();
	~SpriteComponent() {};

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
	Ref<Texture> mSprite = Ref<Texture>();
	int mX = 0
		, mY = 0;

	static InstanceID nextInstanceID;

};
