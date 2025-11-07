#include <QApplication>
#include <QScreen>
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    const QList<QScreen *> screens = QApplication::screens();

    if (screens.isEmpty()) {
        std::cerr << "No screens detected." << std::endl;
        return 1;
    }

    for (int i = 0; i < screens.size(); ++i) {
        QScreen *screen = screens[i];
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << "Screen " << i + 1 << ": " << screen->name().toStdString() << std::endl;
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << "Device pixel ratio:                           " << screen->devicePixelRatio() << std::endl;
        std::cout << "Logical DPI:                                  " << screen->logicalDotsPerInchX()
                  << " x " << screen->logicalDotsPerInchY() << std::endl;
        std::cout << "Physical DPI:                                 " << screen->physicalDotsPerInchX()
                  << " x " << screen->physicalDotsPerInchY() << std::endl;
        std::cout << "logicalDotsPerInchX / physicalDotsPerInchX:   " << ((qreal)screen->logicalDotsPerInchX() / (qreal)screen->physicalDotsPerInchX()) << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
