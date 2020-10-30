#include "SubdivisionNode.h"
#include <ArrayMesh.hpp>
#include <InputEvent.hpp>
#include <SceneTree.hpp>



SubdivisionNode::SubdivisionNode()
{
	numSubdivisions = 0;
	redraw = true;
}

//Bind all your methods used in this class

void SubdivisionNode::_register_methods()
{

	register_method("_ready", &SubdivisionNode::_ready);
	register_method("_process", &SubdivisionNode::_process);
	//register_method("_physics_process", &SubdivisionNode::_physics_process);
	//register_method("_notification", &SubdivisionNode::_notification);
	register_method("_draw", &SubdivisionNode::_draw);
	register_method("_input", &SubdivisionNode::_input);
	//register_method("_update", &SubdivisionNode::_update);

	//register_property("Sprite Component Texture", &Entity::mSpriteComponentTexture, Ref<Texture>());

}

void SubdivisionNode::_init()
{
}

//Custom Functions
void SubdivisionNode::_ready()
{
	numTriangles = 2;
	set_process(true);
	set_process_input(true);

	//6 vertices for the two triangles 
	vertices.push_back(Vector2(0, 100));
	vertices.push_back(Vector2(100, 0));
	vertices.push_back(Vector2(0, 0));
	vertices.push_back(Vector2(0, 100));
	vertices.push_back(Vector2(100, 100));
	vertices.push_back(Vector2(100, 0));

	colors.append(Color(1, 1, 1));
	colors.append(Color(0, 1, 0));
	colors.append(Color(0, 0, 1));
	colors.append(Color(1, 0, 0));
	colors.append(Color(0, 0, 0));
	colors.append(Color(0, 1, 0));

	//Copying the data into another set
	_vertices.push_back(Vector2(0, 100));
	_vertices.push_back(Vector2(100, 0));
	_vertices.push_back(Vector2(0, 0));
	_vertices.push_back(Vector2(0, 100));
	_vertices.push_back(Vector2(100, 100));
	_vertices.push_back(Vector2(100, 0));



	_colors.append(Color(1, 1, 1));
	_colors.append(Color(0, 1, 0));
	_colors.append(Color(0, 0, 1));
	_colors.append(Color(1, 0, 0));
	_colors.append(Color(0, 0, 0));
	_colors.append(Color(0, 1, 0));

	//cout << "Subdivision Ready!!";

}

void SubdivisionNode::_update()
{	
	int _numTriangles = pow(4, numSubdivisions);
	if (_numTriangles > 1 && redraw)//no need to enter if we are using just the base mesh
	{
		_vertices.resize(0);
		_colors.resize(0);
		for (int i = 0; i < vertices.size(); i += 3)
		{
			//get the three points for each triangle
			Vector2 v0 = vertices[i];
			Vector2 v1 = vertices[i + 1];
			Vector2 v2 = vertices[i + 2];
			Color c0 = colors[i];
			Color c1 = colors[i + 1];
			Color c2 = colors[i + 2];
			//find out how many triangles one triangle will subdivide into
			//you can already see not using an half edge mesh makes it so difficult to do a simple midpoint subdivision
			float increment = 1.0 / (numSubdivisions + 1);
			float u = 0;
			float v = 0; // the algorithm uses the concept of barrycentric coordinates to do the subdivision

			int fcounter = numSubdivisions + 1;
				
				
			while(fcounter > 0)
			{
				int bcounter = 0;
				while (bcounter < fcounter)
				{
					Vector2 t0 = v0 * (1 - (u + v)) + v1 * u + v * v2;
					_vertices.push_back(t0);
					Vector2 t1 = v0 * (1 - (u + increment + v)) + v1 * (u + increment) + v * v2;
					_vertices.push_back(t1);
					Vector2 t2 = v0 * (1 - (u + v + increment)) + v1 * u + (v + increment) * v2;
					_vertices.push_back(t2);

					Color ct0 = c0 * (1 - (u + v)) + c1 * u + c2 * v;
					_colors.push_back(ct0);
					Color ct1 = c0 * (1 - (u + increment + v)) + c1 * (u + increment) + c2 * v;
					_colors.push_back(ct1);
					Color ct2 = c0 * (1 - (u + v + increment)) + c1 * (v + increment) + c2 * u;
					_colors.push_back(ct2);
					u += increment;
					bcounter++;
				}
				//reverse
				u -= increment;
				v += increment;
				bcounter = 0;
				while (bcounter<fcounter-1)
				{
					Vector2 t0 = v0 * (1 - (u + v)) + v1 * u + v * v2;
					_vertices.push_back(t0);
					Vector2 t1 = v0 * (1 - (u - increment + v)) + v1 * (u - increment) + v * v2;
					_vertices.push_back(t1);
					Vector2 t2 = v0 * (1 - (u + v - increment)) + v1 * u + (v - increment) * v2;
					_vertices.push_back(t2);

					Color ct0 = c0 * (1 - (u + v)) + c1 * u + c2 * v;
					_colors.push_back(ct0);
					Color ct1 = c0 * (1 - (u - increment + v)) + c1 * (u - increment) + c2 * v;
					_colors.push_back(ct1);
					Color ct2 = c0 * (1 - (u + v - increment)) + c1 * (v - increment) + c2 * u;
					_colors.push_back(ct2);
					u -= increment;
					bcounter++;
				}
				fcounter--;

			}
				
		}

	}

	//cout << "Subdivision Update!!";
	

}

void SubdivisionNode::_draw()
{
	if (redraw)
	{
		Ref<ArrayMesh> a = Ref<ArrayMesh>();
		Array arrays;
		arrays.resize(ArrayMesh::ARRAY_MAX);
		arrays[ArrayMesh::ARRAY_VERTEX] = _vertices; // required
		arrays[ArrayMesh::ARRAY_COLOR] = _colors;

		//optionally u can add texture coordinates and attach a texture from the editor to this arraymesh in the scene

		a->add_surface_from_arrays(Mesh::PRIMITIVE_TRIANGLES, arrays);

		if (this != NULL)
			this->set_mesh(a);
		redraw = false;
	}

	cout << "Subdivision Draw!!";
	
}

void SubdivisionNode::_input(InputEvent* e)
{
	if (e->is_action_pressed("ui_up"))
	{
		numSubdivisions += 1;
		if (numSubdivisions > 5)
			numSubdivisions = 1;
		redraw = true;

	}

	//cout << "Input Ready!!";
}

void SubdivisionNode::_notification(int p_what)
{
	switch (p_what) {
	case NOTIFICATION_DRAW:
	{
		_draw();
	}break;

	}
}

void SubdivisionNode::_process()
{
	if (Input::get_singleton()->is_action_pressed("ui_up")) {
		numSubdivisions += 1;
		if (numSubdivisions > 5)
			numSubdivisions = 1;
		redraw = true;
		get_tree()->set_input_as_handled();
	}
	_update();

	update();

	//cout << "Process Ready!!";
}

