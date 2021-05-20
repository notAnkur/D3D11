#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine()
{
}

bool GraphicsEngine::init()
{
	D3D_DRIVER_TYPE driver_types[] = {
		D3D_DRIVER_TYPE_HARDWARE, // draw calls on gpu
		D3D_DRIVER_TYPE_WARP, // draw calls on cpu
		D3D_DRIVER_TYPE_REFERENCE
	};
	UINT num_driver_types = ARRAYSIZE(driver_types);

	D3D_FEATURE_LEVEL feature_level[] = {
		D3D_FEATURE_LEVEL_11_0
	};
	UINT num_feature_levels = ARRAYSIZE(feature_level);

	HRESULT res = 0;

	for (UINT driver_index = 0; driver_index < num_driver_types; driver_index++) {
		res = D3D11CreateDevice(NULL, driver_types[driver_index], NULL, NULL, feature_level,
			num_feature_levels, D3D11_SDK_VERSION, &m_d3d_device, &m_feature_level, &m_imm_context);

		if (SUCCEEDED(res)) {
			std::cout << driver_types[driver_index] << " " << driver_index << "\n";
			break;
		}
	}

	if (FAILED(res)) {
		return false;
	}


	return true;
}

bool GraphicsEngine::release()
{
	m_imm_context->Release();
	m_d3d_device->Release();
	return true;
}

GraphicsEngine::~GraphicsEngine()
{
}

GraphicsEngine * GraphicsEngine::get()
{
	static GraphicsEngine engine;
	return &engine;
}
