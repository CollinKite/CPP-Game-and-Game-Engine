#pragma once
#include "Input/InputSystem.h"
#include "Core\Memory.h" //header file to check for mem leak
#include "Core/File.h"
#include "Renderer/Renderer.h"
#include "Math/Random.h"
//#include "Math/MathUtils.h"

namespace crae
{
	extern InputSystem g_inputSystem;
	extern InputSystem g_renderer;
}