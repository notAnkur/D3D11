#include "AppWindow.h"
#include <iostream>

AppWindow::AppWindow() {

}

void AppWindow::onCreate() {
	std::cout << "onCreate\n";
}

void AppWindow::onUpdate()
{
}

void AppWindow::onDestroy() {
	Window::onDestroy();
}

AppWindow::~AppWindow() {

}
