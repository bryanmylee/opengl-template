#include <iostream>

#include <GLFW/glfw3.h>

void ProcessInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

void ErrorCallback(int error, const char *msg) {
  std::string s;
  s = " [" + std::to_string(error) + "] " + msg + '\n';
  std::cerr << s << std::endl;
}

int main() {
  glfwSetErrorCallback(ErrorCallback);
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
  glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
  glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  // Construct the window
  GLFWwindow *window =
      glfwCreateWindow(800, 600, "OpenGL Template", nullptr, nullptr);
  if (!window) {
    std::cout << "Failed to create the GLFW window\n";
    glfwTerminate();
  }

  glfwMakeContextCurrent(window);

  // Handle view port dimensions
  glViewport(0, 0, 800, 600);
  glfwSetFramebufferSizeCallback(window,
                                 [](GLFWwindow *window, int width, int height) {
                                   glViewport(0, 0, width, height);
                                 });

  // This is the render loop
  while (!glfwWindowShouldClose(window)) {
    ProcessInput(window);

    glClearColor(1.00f, 0.49f, 0.04f, 1.00f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}