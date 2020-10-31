#pragma once

#include "Events/Event.h"
#include "neon-pch.h"

namespace Neon
{
	class LayerStack;

	class Layer
	{
	public:
		virtual ~Layer() {  }

		virtual void OnUpdate(Timestep dt) = 0;

		virtual void OnEvent(const Event&) = 0;

		//Pushes a layer onto the back of a layer stack
		void RequestPushBack(Layer* layer);

		//Requests a swap to remove this layer and swap with another layer
		void RequestSwap(Layer* layer);

		//Requests to push a new layer to the front
		void RequestPushFront(Layer* layer);

	private:
		LayerStack* m_ParentStack;
	};
}