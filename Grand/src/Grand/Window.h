#pragma once

#include "grandpch.h"

#include "Grand/Core.h"
#include "Grand/Events//Event.h"

namespace Grand
{
	struct WindowProps
	{
		std::string title;
		unsigned int height;
		unsigned int width;

		WindowProps(const std::string& title = "Grand Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: title(title), width(width), height(height)
		{
			// Empty.
		}
	};

	// Interface representing a desktop system based Window.
	class GRAND_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		// Window attributes.
		virtual void setEventCallback(const EventCallbackFn& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		static Window* create(const WindowProps& props = WindowProps());
	};
}