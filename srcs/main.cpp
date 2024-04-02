#include <GLFW/glfw3.h>

int main() {
    // 初始化 GLFW
    if (!glfwInit()) {
        // 初始化失败，退出程序
        return -1;
    }

    // 创建一个窗口，参数为：窗口宽度、窗口高度、窗口标题、窗口监视器（NULL 表示主监视器）、窗口共享标志（NULL 表示不共享）
    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
    if (!window) {
        // 窗口创建失败，清理并退出
        glfwTerminate();
        return -1;
    }

    // 设置窗口的上下文为当前线程的主上下文
    glfwMakeContextCurrent(window);

    // 主循环，直到用户关闭窗口
    while (!glfwWindowShouldClose(window)) {
        // 这里可以添加渲染代码

        // 交换前后缓冲区，使得渲染的内容显示在屏幕上
        glfwSwapBuffers(window);

        // 处理所有事件，如键盘输入、鼠标移动等
        glfwPollEvents();
    }

    // 清理并退出
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
