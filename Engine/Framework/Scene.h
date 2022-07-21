#pragma once
#include "Scene.h"
#include "Actor.h"

#include <list>
#include <memory>

namespace crae
{
	//class Actor; //Forward declaration since we use a Actor ptr, tells complier to find it later | if it wasn't a ptr we would include Actor.h
	//class Renderer; //Fwd Declaration since we use a reference | we use these for optimization

	class Scene
	{
	public:
		Scene() = default;
		~Scene() = default;

		void Update();
		void Draw(Renderer& renderer);

		void Add(std::unique_ptr<Actor> actor);

		template<typename T>
		T* GetActor();

	private:
		std::list<std::unique_ptr<Actor>> m_actors;
	};
	template<typename T>
	inline T* Scene::GetActor()
	{
		dynamic_cast<T*>()

		return nullptr;
	}
}