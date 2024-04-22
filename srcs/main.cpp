#include <QGuiApplication>
#include <iostream>
#include <QWindow>
#include "tcontext.hpp"
#include <QVulkanInstance>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    //QWindow window;
    
    // 创建一个窗口
    QWindow window;

    // 设置窗口的标题和大小
    // window.setWindowTitle("My Window");
    window.resize(800, 600);

    QVulkanInstance qvkinstance;

    auto tc = tw::TContext::getTContext();

    qvkinstance.setVkInstance(tc.instance);
    
    window.setVulkanInstance(&qvkinstance);
    // 显示窗口
    window.show();

    return  app.exec();

}
