#pragma once

#include "neon-pch.h"
#include "Layer.h"
#include "Events/Event.h"
#include "Clock.h"

namespace Neon
{

	class LayerStack
	{
	public:

		//Pushes a layer onto the back of a layer stack
		void PushBack(Layer* layer);

		//Swaps layerToRemove with layerToInsert
		void Swap(Layer* layerToRemove, Layer* layerToInsert);

		//Pushes a layer onto the front of a stack
		void PushFront(Layer* layer);

		void OnUpdate(Timestep dt);

		void OnEvent(const Event& e);

	private:
		std::deque<std::shared_ptr<Layer>> m_Layers;
	};
}