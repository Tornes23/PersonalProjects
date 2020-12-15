/*!**************************************************************************
\file    System.cpp

\author  Nestor Uriarte 

\par     DP email:  nestor.uriarte@digipen.edu 

\par     Course:    CS350 

\par     assignemnt 0 

\date    Mon Sep 21 13:03:11 2020

\brief	 This file containsm the implementation of the 
Systemclass

The functions included are:
- void System::create(unsigned w, unsigned h, const char* title, bool hidden);
- void System::destroy();
- void System::load_resources();
- camera& System::camera();
- window& System::window();
- shaderProgram& System::getShader();
- resources& System::resources();

***************************************************************************/

#include "pch.hpp"
//#include "mesh.hpp"
#include "opengl.hpp"
#include "System.hpp"

/**************************************************************************
*!
\fn     System::create
\brief 
Creates the needed systems for the System
\param  unsigned w
the width of the window
\param  unsigned h
the height of the window
\param  const char* title
the title for the window
\param  bool hidden
if we want to open the window or not
*
**************************************************************************/
void System::create(unsigned w, unsigned h, const char *title, bool hidden)
{
	//creating a window and if it fails return;
	if (!mWindow.create(w, h, title, hidden))
		return;
	//creating a camera
	//mCamera.create(glm::vec3(0, 0, -1), glm::ivec2(w, h));
	////initializing the shared pointers to the meshes
	//mResources.meshes.bunny = std::make_shared<mesh>();
	//mResources.meshes.cube = std::make_shared<mesh>();
	//mResources.meshes.cylinder = std::make_shared<mesh>();
	//mResources.meshes.gourd = std::make_shared<mesh>();
	//mResources.meshes.icosahedron = std::make_shared<mesh>();
	//mResources.meshes.line = std::make_shared<mesh>();
	//mResources.meshes.octohedron = std::make_shared<mesh>();
	//mResources.meshes.quad = std::make_shared<mesh>();
	//mResources.meshes.segment = std::make_shared<mesh>();
	//mResources.meshes.sphere = std::make_shared<mesh>();
	//mResources.meshes.suzanne = std::make_shared<mesh>();
	//mResources.meshes.triangle = std::make_shared<mesh>();
	////loading the resources
	//load_resources();
}
/**************************************************************************
*!
\fn     System::destroy
\brief 
destroys the window and frees the meshes
*
**************************************************************************/
void System::destroy()
{
	//destroying the window
	mWindow.destroy();
	////reseting the shared pointers
	//mResources.meshes.bunny.reset();
	//mResources.meshes.cube.reset();
	//mResources.meshes.cylinder.reset();
	//mResources.meshes.gourd.reset();
	//mResources.meshes.icosahedron.reset();
	//mResources.meshes.line.reset();
	//mResources.meshes.octohedron.reset();
	//mResources.meshes.quad.reset();
	//mResources.meshes.segment.reset();
	//mResources.meshes.sphere.reset();
	//mResources.meshes.suzanne.reset();
	//mResources.meshes.triangle.reset();
}
/**************************************************************************
*!
\fn     System::load_resources
\brief 
loads the necessary resources
*
**************************************************************************/
void System::load_resources()
{
	//loading all the meshes from the .objs
	//mResources.meshes.bunny->generate(load_obj("resources/meshes/bunny.obj"));
	//mResources.meshes.cube->generate(load_obj("resources/meshes/cube.obj"));
	//mResources.meshes.cylinder->generate(load_obj("resources/meshes/cylinder.obj"));
	//mResources.meshes.gourd->generate(load_obj("resources/meshes/gourd.obj"));
	//mResources.meshes.icosahedron->generate(load_obj("resources/meshes/icosahedron.obj"));
	//mResources.meshes.line->generate(load_obj("resources/meshes/line.obj"));
	//mResources.meshes.octohedron->generate(load_obj("resources/meshes/octohedron.obj"));
	//mResources.meshes.quad->generate(load_obj("resources/meshes/quad.obj"));
	//mResources.meshes.segment->generate(load_obj("resources/meshes/segment.obj"));
	//mResources.meshes.sphere->generate(load_obj("resources/meshes/sphere.obj"));
	//mResources.meshes.suzanne->generate(load_obj("resources/meshes/suzanne.obj"));
	//mResources.meshes.triangle->generate(load_obj("resources/meshes/triangle.obj"));
	////creating the shader program
	//mResources.shaders.color.create("resources/shaders/color.vert", "resources/shaders/color.frag");
	//mResources.shaders.raw.create("resources/shaders/raw.vert", "resources/shaders/raw.frag");
}
/**************************************************************************
*!
\fn     System::camera
\brief 
getter function for the camera
\return camera&
 reference to the camera
*
**************************************************************************/
camera &System::camera()
{
	return mCamera;
}
/**************************************************************************
*!
\fn     System::window
\brief 
getter function for the window
\return window&
 reference to the window
*
**************************************************************************/
window &System::window()
{
	return mWindow;
}
/**************************************************************************
*!
\fn     System::resources
\brief 
getter function for the resources
\return resources&
 reference to the resources
*
**************************************************************************/
resources &System::resources()
{
	return mResources;
}
//std::shared_ptr<mesh> &System::getMesh(meshType mesh)
//{
//	switch (mesh)
//	{
//	case cs350::meshType::bunny:
//		return mResources.meshes.bunny;
//		break;
//	case cs350::meshType::cube:
//		return mResources.meshes.cube;
//		break;
//	case cs350::meshType::cylinder:
//		return mResources.meshes.cylinder;
//		break;
//	case cs350::meshType::gourd:
//		return mResources.meshes.gourd;
//		break;
//	case cs350::meshType::icosahedron:
//		return mResources.meshes.icosahedron;
//		break;
//	case cs350::meshType::line:
//		return mResources.meshes.line;
//		break;
//	case cs350::meshType::octohedron:
//		return mResources.meshes.octohedron;
//		break;
//	case cs350::meshType::quad:
//		return mResources.meshes.quad;
//		break;
//	case cs350::meshType::segment:
//		return mResources.meshes.segment;
//		break;
//	case cs350::meshType::sphere:
//		return mResources.meshes.sphere;
//		break;
//	case cs350::meshType::suzzane:
//		return mResources.meshes.suzanne;
//		break;
//	case cs350::meshType::triangle:
//		return mResources.meshes.triangle;
//		break;
//	default:
//		break;
//	}
//	return mResources.meshes.bunny;
//}
