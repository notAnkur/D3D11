#include "Window.h"

Window* window = NULL;

Window::Window() {

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	switch (msg) {
		case WM_CREATE: {
			window->onCreate();
			break;
		}
		case WM_DESTROY: {
			window->onDestroy();
			PostQuitMessage(0);
			break;
		}
		default:
			return DefWindowProc(hwnd, msg, wparam, lparam);
	}

	return NULL;
}

bool Window::init()
{
	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = "MyWindowClass";
	wc.lpszMenuName = "";
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = &WndProc;


	if (!RegisterClassEx(&wc)) {
		return false;
	}

	if (!window) {
		window = this;
	}

	m_hwnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "MyWindowClass", "DirectX Application", WS_EX_OVERLAPPEDWINDOW | WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION,
		CW_USEDEFAULT, CW_USEDEFAULT, 600, 400, NULL, NULL, NULL, NULL);

	if (!m_hwnd) {
		return false;
	}

	ShowWindow(m_hwnd, SW_SHOW);
	UpdateWindow(m_hwnd);

	m_is_running = true;
	return true;
}

bool Window::broadcast() {

	MSG msg;

	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	window->onUpdate();

	Sleep(0);

	return true;
}

bool Window::isRunning() {
	return m_is_running;
}

bool Window::release()
{
	//Destroy window
	if (!DestroyWindow(m_hwnd)) {
		return false;
	}

	return true;
}

void Window::onDestroy()
{
	m_is_running = false;
}

Window::~Window() {

}
