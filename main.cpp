#include <QApplication>
#include <QScreen>
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QScreen *screen = QApplication::primaryScreen();

    if (!screen) {
        std::cerr << "No primary screen found." << std::endl;
        return 1;
    }

    double dpr = screen->devicePixelRatio();
    double logicalDpiX = screen->logicalDotsPerInchX();
    double logicalDpiY = screen->logicalDotsPerInchY();
    double physicalDpiX = screen->physicalDotsPerInchX();
    double physicalDpiY = screen->physicalDotsPerInchY();

    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "Primary screen: " << screen->name().toStdString() << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "Device pixel ratio:                           " << dpr << std::endl;
    std::cout << "Logical DPI:                                  " << logicalDpiX << " x " << logicalDpiY << std::endl;
    std::cout << "Physical DPI:                                 " << physicalDpiX << " x " << physicalDpiY << std::endl;

    std::cout << "logicalDotsPerInchX / physicalDotsPerInchX:   " << ((qreal)logicalDpiX / (qreal)physicalDpiX) << std::endl;

    return 0;
}
