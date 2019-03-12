#ifndef DEFAULT_UNIFORM_BUFFER_H
#define DEFAULT_UNIFORM_BUFFER_H
#include "UniformBuffer.h"
#include <array>

class defaultUniformBuffer// : public uniformBuffer_t
{
public:

	glm::mat4			projection;
	glm::mat4			view;
	glm::mat4			translation;
	glm::vec2			resolution;
	glm::vec2			mousePosition;
	GLfloat				deltaTime;
	GLfloat				totalTime;
	GLfloat				framesPerSec;
	GLuint				totalFrames;
	GLuint				bufferHandle;
	GLuint				uniformHandle;

	defaultUniformBuffer( glm::mat4 projection, glm::mat4 view,
			glm::mat4 translation = glm::mat4( 1 ), glm::vec2 resolution = glm::vec2(1280, 720) )
		//: uniformBuffer_t()
	{
		//BuildBuffer();
		//uniformBuffer_t();
		this->projection = projection;
		this->view = view;
		this->translation = translation;
		this->resolution = resolution;
		totalFrames = 1;
	}

	defaultUniformBuffer(camera* defaultCamera)// : uniformBuffer_t()
	{
		//uniformBuffer_t();
		//BuildBuffer();
		this->projection = defaultCamera->projection;
		this->view = defaultCamera->view;
		this->translation = defaultCamera->translation;
		this->resolution = defaultCamera->resolution;
		totalFrames = 1;
	}

	defaultUniformBuffer(){};

/*
	virtual void* GetBuffer() override
	{
		return data;
	}

	virtual void BuildBuffer() override
	{
		AppendBuffer<glm::mat4>(projection, data);
		AppendBuffer<glm::mat4>(view, data);
		AppendBuffer<glm::mat4>(translation, data);
		AppendBuffer<glm::vec2>(resolution, data);
		AppendBuffer<glm::vec2>(mousePosition, data);
		AppendBuffer<float>(deltaTime, data);
		AppendBuffer<float>(totalTime, data);
		AppendBuffer<float>(framesPerSec, data);
		printf("%i \n", dataSize);
	}*/
};
#endif