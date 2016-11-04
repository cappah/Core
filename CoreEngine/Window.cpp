/*
Core engine

Aaro Per�maa
2016
*/

#include "Window.h"
#include "RenderingEngine.h"

#include <assert.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


Window::Window(RenderingEngine *renderer, uint32_t width, uint32_t height, std::string title, bool vsyncRequested)
{
	m_surfaceSizeX = width;
	m_surfaceSizeY = height;


#if BUILD_WITH_RENDERING_BACKEND == RENDERING_BACKEND_VULKAN
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); //Dont create a gl context
	glfwWindowHint(GLFW_RESIZABLE,  GLFW_FALSE);
#endif

	m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
}



bool Window::update()
{
	glfwPollEvents();


	return !glfwWindowShouldClose(m_window);
}

uint32_t Window::getWidth()
{
	return m_surfaceSizeX;
}

uint32_t Window::getHeight()
{
	return m_surfaceSizeY;
}

bool Window::getVSync()
{
	return m_vsyncRequested;
}

Window::~Window()
{
	
}