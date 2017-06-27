#include <MainWindow.hpp>

using namespace OpenGLWindow;
int main()
{
	Window window{800, 600, "Hello Window!"};

	while (!window.shouldClose())
	{
		window.processInput();
		window.pollEvents();

		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		window.swapBuffers();
	}

	return 0;
}