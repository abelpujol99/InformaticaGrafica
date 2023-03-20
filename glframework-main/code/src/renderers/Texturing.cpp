#include <renderers/Texturing.h>

Texturing::Texturing(int width, int height) : Renderer(width, height)
{
	float vertices[]{

		0.5f, 0.5f, 0.f, //top right
		-0.5f, 0.5f, 0.f, //top left 
		-0.5f, -0.5f, 0.f, //bottom left
		0.5f, -0.5, 0.f //bottom right
	};


	unsigned int indices[]{

		0, 1, 3, //top triangle
		1, 2, 3 //bottom triangle	
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	//Element Buffer Object
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(0);

	program = new Program("Square");
	program->compileAndAttachShader("shaders/Cube.vert", GL_VERTEX_SHADER);
	program->compileAndAttachShader("shaders/Cube.frag", GL_FRAGMENT_SHADER);

	program->bindAttribLocation(0, "in_Position");

	program->link();

	glBindVertexArray(0);

	program->unuse();

}

Texturing::~Texturing()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	delete program;
}

void Texturing::render(float dt)
{
	glBindVertexArray(VAO);
	program->use();

	color = glm::vec4(1.f, 0.3f, 0.2f, 1.f);

	objMat = glm::translate(glm::mat4(), glm::vec3(0.f, 0.f, -5.f));

	glUniformMatrix4fv(
		program->getUniform("objMat"),
		1, GL_FALSE, glm::value_ptr(objMat)
	);
	glUniformMatrix4fv(
		program->getUniform("mv_Mat"),
		1, GL_FALSE, glm::value_ptr(cam._modelView)
	);
	glUniformMatrix4fv(
		program->getUniform("mvpMat"),
		1, GL_FALSE, glm::value_ptr(cam._MVP)
	);
	glUniform4f(
		program->getUniform("color"),
		color.r, color.g, color.b, color.w
	);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	program->unuse();
	glBindVertexArray(0);
}
