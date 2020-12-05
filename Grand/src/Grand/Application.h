#pragma once

#include "Core.h"

#include "Grand/Window.h"
#include "Grand/LayerStack.h"
#include "Grand/Events/Event.h"
#include "Grand/Events/ApplicationEvent.h"


namespace Grand
{
	class GRAND_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

		void onEvent(Event& e);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);

	private:
		bool onWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT.
	Application* createApplication();
}


