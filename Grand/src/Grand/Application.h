#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Grand/Window.h"

namespace Grand
{
	class GRAND_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT.
	Application* createApplication();
}


