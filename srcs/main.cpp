
#include <QApplication>
#include <QWidget>
#include <QVulkanWindow>

int main(int argc, char *argv[]){
    QApplication app(argc,argv);
    QWidget w;
    w.resize(800,600);
    w.show();
    return app.exec();

}
