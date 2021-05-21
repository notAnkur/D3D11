#pragma once
class SwapChain
{
public:
	SwapChain();
	bool init(HWND hwnd, UINT width, UINT height);
	bool release();
	~SwapChain();

private:
	IDXGISwapChain* m_swap_chain;
};

