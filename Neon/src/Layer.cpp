#include "neon-pch.h"
#include "Layer.h"
#include "LayerStack.h"

void Neon::Layer::RequestPushBack(Layer* layer)
{
	m_ParentStack->PushBack(layer);
}

void Neon::Layer::RequestSwap(Layer* layer)
{
	m_ParentStack->Swap(this, layer);
}

void Neon::Layer::RequestPushFront(Layer* layer)
{
	m_ParentStack->PushFront(layer);
}
