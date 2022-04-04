#pragma once

#include "Core.h"

#include "Window.h"
#include "Lapis/LayerStack.h"
#include "Lapis/Events/Event.h"
#include "Lapis/Events/ApplicationEvent.h"


namespace Lapis 
{
	class LAPIS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
