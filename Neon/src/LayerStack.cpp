#include "neon-pch.h"
#include "LayerStack.h"

void Neon::LayerStack::PushBack(Layer* layer)
{
	m_Layers.push_back(std::shared_ptr<Layer>(layer));
}

void Neon::LayerStack::Swap(Layer* layerToRemove, Layer* layerToInsert)
{
	//Finds the location of layerToRemove in the stack
	auto location = std::find_if(
		m_Layers.begin(),
		m_Layers.end(),
		[layerToRemove](std::shared_ptr<Layer>& layer) { return layer.get() == layerToRemove; }
	);

	//Resets the unique pointer of layerToRemove with the new layerToInsert
	if (location != m_Layers.end())
		location->reset(layerToInsert);
}

void Neon::LayerStack::PushFront(Layer* layer)
{
	m_Layers.push_front(std::shared_ptr<Layer>(layer));
}

//TODO: may want to introduce some kind of blocking
//May also want to do back to front instead of front to back
void Neon::LayerStack::OnUpdate(Timestep dt)
{
	for (auto begin : m_Layers)
	{
		begin->OnUpdate(dt);
	}
}

void Neon::LayerStack::OnEvent(const Event& e)
{
	for (auto layer : m_Layers)
	{
		layer->OnEvent(e);
	}
}
