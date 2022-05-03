workspace "GammaEngine"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist",
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GammaEngine"
	location "GammaEngine"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"GAMMAENGINE_PLATFORM_WINDOWS",
			"GAMMAENGINE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "GAMMAENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GAMMAENGINE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GAMMAENGINE_DIST"
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
		"GammaEngine/vendor/spdlog/include",
		"GammaEngine/src"
	}

	links
	{
		"GammaEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"GAMMAENGINE_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "GAMMAENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GAMMAENGINE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GAMMAENGINE_DIST"
		optimize "On"