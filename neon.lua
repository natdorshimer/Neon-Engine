workspace "Neon"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Neon/vendor/GLFW/include"
IncludeDir["spdlog"] = "Neon/vendor/spdlog/include"

include "Neon/vendor/GLFW"

project "Neon"
    location "Neon"
    kind "SharedLib"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "neonpch.h"
    pchsource "Neon/src/neonpch.cpp"

    files
    {
        "%{prj.name}/src/",
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src/",
        "%{prj.name}/src/Neon",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.spdlog}"
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
            "NEON_PLATFORM_WINDOWS",
            "NEON_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Playground/")
        }

    filter "configurations:Debug"
        defines "NEON_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "NEON_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "NEON_DIST"
        optimize "On"

    filter { "system:windows", "configurations:Release" }


project "Playground"
    location "Playground"
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
        "Neon/src/**",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.spdlog}"
    }

    links
    {
        "Neon",
        "GLFW"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "NEON_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "NEON_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "NEON_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "NEON_DIST"
        optimize "On"

    filter { "system:windows", "configurations:Release" }