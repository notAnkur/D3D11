#include "AppWindow.h"
#include <iostream>

AppWindow::AppWindow() {

}

void AppWindow::onCreate() {
	std::cout << "onCreate\n";
	Window::onCreate();
	GraphicsEngine::get()->init();
}

void AppWindow::onUpdate()
{
}

void AppWindow::onDestroy() {
	Window::onDestroy();
	GraphicsEngine::get()->release();
}

AppWindow::~AppWindow() {

}
