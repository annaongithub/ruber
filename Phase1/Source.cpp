#define __Windows__
#include "../../includes465/include465.hpp"
#include "MoveableObj3D.h"

//Objects
const int TOTAL_OBJ = 10;
MoveableObj3D * Obj3D[TOTAL_OBJ];

//Model for Objects

//display state and "state strings" for title display
//window title strings
char* titleString = "Comp 465: Project 1 - Phase 1";

GLuint vao;	//Vertex Array Object
GLuint buffer;
GLuint shaderProgram;
char* vertexShaderFile;
char* fragmentShaderFile;
GLuint MVP;	//ModelViewProjection matrix's handle
glm::mat4 projectionMatrix;	//set in reshape()
glm::mat4 modelMatrix;	//set in shape[i]-->updateDraw()
glm::mat4 viewMatrix;	//set in keyboard()
glm::mat4 ModelViewProjectionMatrix;	//set in display()

//vectors for "model"
glm::vec4 vertex[nVertices];
glm::vec3 normal[nVertices];
glm::vec4 diffuseColorMaterial[nVertices];

//rotation variables
glm::mat4 identity(1.0f);
int timerDelay = 40, framecount = 0;
double currentTime, lastTime, intervalTimer;

void init(void) {
	shaderProgram = loadShaders(vertexShaderFile, fragmentShaderFile);
	glUseProgram(shaderProgram);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//Create and initialize a buffer object
	//GLuint buffer
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) + sizeof(diffuseColorMaterial) + sizeof(normal),
				 NULL,  GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertex), vertex);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertex), sizeof(diffuseColorMaterial), diffuseColorMaterial);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertex) + sizeof(diffuseColorMaterial), sizeof(normal), normal);

	//setup vertex arrays (after shaders are loaded)
	GLuint vPosition = glGetAttribLocation(shaderProgram, "vPosition");
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//update model matrix, set MVP, draw
	for (int i = 0; i < 0; i++) {
		
	}
}

void update(MoveableObj3D* updateObjects[]) {
	
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'esc': exit(EXIT_SUCCESS);
	case 'w' : 
		break;
	case 'a' :
		break;
	case 's' :
		break;
	case 'd' :
		break;
	}
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutCreateWindow("Phase 1");
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err)
		printf("GLEW Error: %s \n", glewGetErrorString(err));
	else {
		printf("Using GLEW %s \n", glewGetString(GLEW_VERSION));
		printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION),
			    glGetString(GL_SHADING_LANGUAGE_VERSION));
	}
	//initialize scene
	init();

	//set glut callback functions
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(NULL);	//start with interval timer
	glutTimerFunc(timerDelay, intervalTimer, 1);
	glutMainLoop();
	printf("done\n");
	return 0;
}