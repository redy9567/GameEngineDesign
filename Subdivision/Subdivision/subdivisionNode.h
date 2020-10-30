//insert the Headername here
#ifndef SUBDIVISIONNODE_H
#define SUBDIVISIONNODE_H

#include "Common.h"
#include <Node2D.hpp>
#include <MeshInstance2D.hpp>
#include <Mesh.hpp>
#include <TriangleMesh.hpp>
#include <Input.hpp>

class SubdivisionNode : public MeshInstance2D {
	GODOT_CLASS(SubdivisionNode, MeshInstance2D);

protected:
	int numSubdivisions;
	int numTriangles;
	//original
	PoolVector2Array vertices;
	PoolColorArray colors;

	//updated
	PoolVector2Array _vertices;
	PoolColorArray _colors;
	bool redraw;
public:
	SubdivisionNode();

	static void _register_methods();
	void _init();

	void _notification(int p_what);
	void _process();
	void _update();
	void _ready();
	void _draw();
	void _input(InputEvent* e);

};

#endif
