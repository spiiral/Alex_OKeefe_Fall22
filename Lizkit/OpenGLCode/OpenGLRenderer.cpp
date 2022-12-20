#include "pch.h"

#include "LizkitWindow.h"
#include "OpenGLRenderer.h"
#include "glad/glad.h"

namespace Lizkit {
	OpenGLRenderer::OpenGLRenderer(){
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	void OpenGLRenderer::Draw(Picture& picture, int x, int y, int z, Shader& shader){
		float vertices[] = {
		(float)x, (float)y, (float)z, 0.0f, 0.0f,
		(float)(x + picture.GetWidth()), (float)y, (float)z, 1.0f, 0.0f,
		(float)x, (float)(y + picture.GetHeight()), (float)z, 0.0f, 1.0f,
		(float)(x + picture.GetWidth()), (float)(y + picture.GetHeight()), (float)z, 1.0f, 1.0f,
		};

		unsigned int indices[] = {
			0, 1, 2,
			1, 2, 3
		};

		unsigned int VBO, VAO, EBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &EBO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);


		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		picture.Activate();
		shader.Activate();

		int width{ LizkitWindow::GetWindow()->GetWidth()};
		int height{ LizkitWindow::GetWindow()->GetHeight()};

		shader.ProvideFloatValues("screenSize", { (float)width, (float)height });

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);

	}
	void OpenGLRenderer::Clear(){
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}