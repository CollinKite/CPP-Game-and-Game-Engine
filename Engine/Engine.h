#pragma once

#include "Core\Memory.h" //header file to check for mem leak
#include "Core/File.h"

#include "Framework/Actor.h"
#include "Framework/Scene.h"

#include "Input/InputSystem.h"

#include "Renderer/Renderer.h"
#include "Math/Random.h"
#include "Core/Time.h"
#include "Math/MathUtils.h"
#include "Audio/AudioSystem.h"


namespace crae
{
	//extern defines NOT declares
	extern InputSystem g_inputSystem;
	extern Renderer g_renderer;
	extern Time g_time;
	extern AudioSystem g_audioSystem;
}