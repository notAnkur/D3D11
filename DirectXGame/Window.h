#pragma once
#include <Windows.h>

class Window
{
public:
	Window();

	bool init();
	bool broadcast();
	bool isRunning();
	bool release();

	RECT getClientWindowRect();
	void setHWND(HWND hwnd);

	virtual void onCreate()=0;
	virtual void onUpdate();
	virtual void onDestroy();

	~Window();

protected:
	HWND m_hwnd;
	bool m_is_running;
};

