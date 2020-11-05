workspace "Grand"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Grand/vendor/GLFW/include"

-- This includes the premake5 file in the GLFW folder into here.
include "Grand/vendor/GLFW"

project "Grand"
	location "Grand"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "grandpch.h"
	pchsource "Grand/src/grandpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GRAND_PLATFORM_WINDOWS",
			"GRAND_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "GRAND_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GRAND_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GRAND_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Grand/vendor/spdlog/include",
		"Grand/src"
	}

	links
	{
		"Grand"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GRAND_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "GRAND_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GRAND_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GRAND_DIST"
		optimize "On"

	