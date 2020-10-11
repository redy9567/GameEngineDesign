#include "LocationComponent.h"

InstanceID LocationComponent::nextInstanceID = 0;

LocationComponent::LocationComponent()
{

	mInstanceID = nextInstanceID++;
	mName = "Sprite Component " + String(mInstanceID);

}

void LocationComponent::_register_methods()
{
}

void LocationComponent::init()
{
}

void LocationComponent::editorReady()
{
}

void LocationComponent::editorProcess(float delta)
{
}

void LocationComponent::editorPhysics_process(float delta)
{
}

void LocationComponent::ready()
{
}

void LocationComponent::process(float delta)
{
}

void LocationComponent::physics_process(float delta)
{
}

void LocationComponent::draw()
{
}

void LocationComponent::registerProperties()
{
}
