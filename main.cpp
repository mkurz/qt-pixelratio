#include <QApplication>
#include <QScreen>
#include <QWindow>
#include <iostream>
#include <QGuiApplication>
#include <QString>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    const QList<QScreen *> screens = QApplication::screens();
    QScreen* primary = QApplication::primaryScreen();
    const QString plat = QGuiApplication::platformName();  // e.g. "wayland", "xcb"
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "Qt platform: " << plat.toStdString()
          << (plat.startsWith("wayland") ? " (Wayland)"
              : (plat == "xcb" ? " (X11)" : "")) << std::endl;

    if (screens.isEmpty()) {
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cerr << "No screens detected." << std::endl;
        return 1;
    }

    for (int i = 0; i < screens.size(); ++i) {
        QScreen *screen = screens[i];
        QWindow window;
        window.setScreen(screen);
        bool isPrimary = (screen == primary);
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << "Screen " << i + 1 << ": "
                  << screen->name().toStdString()
                  << (isPrimary ? "  ⭐ Primary" : "")
                  << std::endl;
        std::cout << "----------------------------------------------------------------" << std::endl;
        double screenDpr = screen->devicePixelRatio();
        std::cout << "Device pixel ratio:                           " << screenDpr << std::endl;
        std::cout << "Logical DPI:                                  " << screen->logicalDotsPerInchX()
                  << " x " << screen->logicalDotsPerInchY() << std::endl;
        std::cout << "Physical DPI:                                 " << screen->physicalDotsPerInchX()
                  << " x " << screen->physicalDotsPerInchY() << std::endl;
        double windowDpr = window.devicePixelRatio();
        std::cout << "Fractional DPR:                               " << windowDpr << std::endl;
        double scaleApprox = screen->logicalDotsPerInch() / 96.0;
        std::cout << "Approx. scale factor:                         " << scaleApprox << std::endl;
        std::cout << "logicalDotsPerInchX / physicalDotsPerInchX:   " << ((qreal)screen->logicalDotsPerInchX() / (qreal)screen->physicalDotsPerInchX()) << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
