#include "grandpch.h"
#include "Application.h"

#include "Grand/Log.h"

#include "Glad/glad.h"

namespace Grand
{

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::create());
		m_Window->setEventCallback(BIND_EVENT_FN(Application::onEvent));
	}


	Application::~Application()
	{

	}


	void Application::pushLayer(Layer* layer)
	{
		m_LayerStack.pushLayer(layer);
	}

	void Application::pushOverlay(Layer* overlay)
	{
		m_LayerStack.pushOverlay(overlay);
	}


	void Application::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowClosed));
		GRAND_CORE_TRACE("{0}", e);

		// Go backwards through layer stack and attempt to handle event.
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->onEvent(e);
			if (e.isHandled())
			{
				break;
			}
		}
	}

	void Application::run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
			{
				layer->onUpdate();
			}

			m_Window->onUpdate();
		}
	}

	bool Application::onWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}
