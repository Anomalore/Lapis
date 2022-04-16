workspace "Lapis"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)

IncludeDir = {}
IncludeDir["GLFW"] = "Lapis/vendor/GLFW/include"
IncludeDir["Glad"] = "Lapis/vendor/Glad/include"
IncludeDir["ImGui"] = "Lapis/vendor/imgui"

group "Dependencies"
	include "Lapis/vendor/GLFW"
	include "Lapis/vendor/Glad"
	include "Lapis/vendor/imgui"
group ""

project "Lapis"
	location "Lapis"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "lppch.h"
	pchsource "Lapis/src/lppch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"LP_PLATFORM_WINDOWS",
			"LP_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "LP_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "LP_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "LP_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"Lapis/vendor/spdlog/include",
		"Lapis/vendor",
		"Lapis/src"
	}

	links
	{
		"Lapis"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"LP_PLATFORM_WINDOWS"
		}
	

	filter "configurations:Debug"
		defines "LP_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "LP_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "LP_DIST"
		runtime "Release"
		optimize "On"