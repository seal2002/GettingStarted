#include <MainWindow.hpp>
#include "Shader.h"

using namespace OpenGLWindow;

GLfloat vertices[] = {
    // Pos				// Color
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 
    0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
    0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
};

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

int main()
{
    Window window{ 800, 600, "Shader Uniform Transform" };

    Shader myShader("..\\Projects\\3.3.ShaderUniformTransform\\VertexShader.vs", "..\\Projects\\3.3.ShaderUniformTransform\\FragmentShader.frag");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position Attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);
    // Color Attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3* sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    while (!window.shouldClose())
    {
        window.processInput();
        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        myShader.Use();
        // Draw our first triangle
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        window.swapBuffers();
        window.pollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    return 0;
}

