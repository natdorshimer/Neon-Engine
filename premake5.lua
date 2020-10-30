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
IncludeDir["GLEW"] = "Neon/vendor/GLEW/include"
IncludeDir["glm"] = "Neon/vendor/glm/"
IncludeDir["spdlog"] = "Neon/vendor/spdlog/include"
IncludeDir["entt"] = "Neon/vendor/entt/include"

project "Neon"
    location "Neon"
    kind "SharedLib"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "neon-pch.h"
    pchsource "%{prj.name}/src/neon-pch.cpp"

    files
    {
        "%{prj.name}/src/",
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src/",
        "%{prj.name}/vendor/",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLEW}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.entt}"
    }

    libdirs 
    { 
        "%{prj.name}/vendor/GLEW/lib/Release/x64",
        "%{prj.name}/vendor/GLFW/lib"
    }

    links
    {
        "glfw3dll.lib", 
        "opengl32.lib",
        "glew32s.lib",
        "glew32.lib", 
        "glu32.lib", 
    }

    defines
    {
        "NEON_DLL"
    }


    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "NEON_PLATFORM_WINDOWS",
        }

        prebuildcommands
        {
            "{COPY} vendor/GLFW/lib/glfw3.dll ../bin/" .. outputdir .. "/%{prj.name}/",
            "{COPY} vendor/GLEW/bin/Release/x64/glew32.dll ../bin/" .. outputdir .. "/%{prj.name}/"
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
        "Neon/src/",
        "Neon/vendor/GLFW/include",
        "%{prj.name}/src/",
        "%{prj.name}/vendor/",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLEW}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.entt}"
    }

    links
    {
        "Neon"
    }

    prebuildcommands
    {
        "{COPY} ../Neon/vendor/GLFW/lib/glfw3.dll ../bin/" .. outputdir .. "/%{prj.name}/",
        "{COPY} ../Neon/vendor/GLEW/bin/Release/x64/glew32.dll ../bin/" .. outputdir .. "/%{prj.name}/"
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