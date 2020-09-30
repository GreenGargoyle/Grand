#pragma once

#include "Core.h"

namespace Grand
{
	class GRAND_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// To be defined in CLIENT.
	Application* createApplication();
}


