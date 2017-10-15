#pragma once

#ifdef __APPLE__
#include <GL/glew.h>
#elif defined _WIN32 || defined _WIN64
#include <glew.h>
#endif

static const GLfloat g_vertex_buffer_data[] = {
	0.5f, -0.5f, -0.5f,        1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
	0.5f, 0.5f, -0.5f,         1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
	0.5f, -0.5f, 0.5f,         1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	0.5f, -0.5f, 0.5f,         1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	0.5f, 0.5f, -0.5f,         1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
	0.5f, 0.5f, 0.5f,          1.0f, 0.0f, 0.0f, 1.0f, 1.0f,

	0.5f, 0.5f, -0.5f,         0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
	-0.5f, 0.5f, -0.5f,        0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
	0.5f, 0.5f, 0.5f,          0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.5f,          0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
	-0.5f, 0.5f, -0.5f,        0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
	-0.5f, 0.5f, 0.5f,         0.0f, 1.0f, 0.0f, 1.0f, 1.0f,

	-0.5f, 0.5f, -0.5f,        -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,       -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
	-0.5f, 0.5f, 0.5f,         -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	-0.5f, 0.5f, 0.5f,         -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,       -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.5f,        -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,

	-0.5f, -0.5f, -0.5f,       0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
	0.5f, -0.5f, -0.5f,        0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.5f,        0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, 0.5f,        0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
	0.5f, -0.5f, -0.5f,        0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
	0.5f, -0.5f, 0.5f,         0.0f, -1.0f, 0.0f, 1.0f, 1.0f,

	0.5f, 0.5f, 0.5f,          0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
	-0.5f, 0.5f, 0.5f,         0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
	0.5f, -0.5f, 0.5f,         0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
	0.5f, -0.5f, 0.5f,         0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
	-0.5f, 0.5f, 0.5f,         0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.5f,        0.0f, 0.0f, 1.0f, 1.0f, 1.0f,

	0.5f, -0.5f, -0.5f,        0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,       0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
	0.5f, 0.5f, -0.5f,         0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
	0.5f, 0.5f, -0.5f,         0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,       0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
	-0.5f, 0.5f, -0.5f,        0.0f, 0.0f, -1.0f, 1.0f, 0.0f
};