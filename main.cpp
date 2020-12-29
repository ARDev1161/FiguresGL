#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    // Когда пользователь нажимает ESC, мы устанавливаем свойство WindowShouldClose в true,
    // и приложение после этого закроется
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main()
{
    // Window dimensions
    const GLuint WIDTH = 800, HEIGHT = 600;

    std::cout << "Starting GLFW context" << std::endl;
    //Инициализация GLFW
    glfwInit();

    //Настройка GLFW
    //Задается минимальная требуемая версия OpenGL.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    //Установка профайла для которого создается контекст
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //Выключение возможности изменения размера окна
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Figures", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    glfwSetKeyCallback(window, key_callback);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    while(!glfwWindowShouldClose(window))
    {
        // Проверяем события и вызываем функции обратного вызова.
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
        // Команды отрисовки здесь

        // Меняем буферы местами
        glfwSwapBuffers(window);
    }

    glfwTerminate();

    return 0;
}
