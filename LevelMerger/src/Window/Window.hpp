/*!**************************************************************************
\file    window.cpp

\author  Nestor Uriarte

\par     email:  nestoruriarte23@gmail.com
\date    Mon Sep 21 13:15:17 2020

\brief	 This file contains the implementation of the
window class
***************************************************************************/
#include "glm/vec2.hpp"
#include <glfw/glfw3.h>

class window
{
private:
	GLFWwindow *m_window = {};
	glm::ivec2 m_size = {};
	float mLastFrame = 0.0F;
	glm::vec2 mMousePos = glm::vec2(0.0F, 0.0F);

public:
	~window() { destroy(); };
	bool create(int w, int h, const char *window_name, bool hidden);
	bool update();
	void destroy();
	void clear();
	void handleInput();
	void setMousePos(glm::vec2 pos);
	[[nodiscard]] glm::ivec2 size() const noexcept { return m_size; }
	[[nodiscard]] GLFWwindow *handle() const noexcept { return m_window; }
};