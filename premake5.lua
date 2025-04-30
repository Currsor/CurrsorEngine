workspace "CurrsorEngine"
    startproject "Sandbox"
    architecture "x64"

    buildoptions { "/utf-8" }

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    group "Dependencies"
        include "Currsor/vendor/GLFW"
        include "Currsor/vendor/Glad"
        include "Currsor/vendor/imgui"

    group ""

    project "Currsor"
        location "Currsor"
        kind "SharedLib"
        language "C++"
        staticruntime "off"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        pchheader "PCH.h"
        pchsource "Currsor/src/PCH.cpp"

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp",
            "%{prj.name}/src/**.hpp",
            "%{prj.name}/src/**.c",
            "%{prj.name}/src/**.cc"
        }

        includedirs
        {
            "%{prj.name}/src",
            "%{prj.name}/vendor/spdlog/include",
            "%{prj.name}/vendor/GLFW/include",
            "%{prj.name}/vendor/Glad/include",
            "%{prj.name}/vendor/imgui",
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
                "CS_PLATFORM_WINDOWS",
                "CS_BUILD_DLL",
                "GLFW_INCLUDE_NONE"
            }
        
        postbuildcommands
        {
            "{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox\""
        }
        
        filter "configurations:Debug"
            defines { "CS_DEBUG" }
            runtime "Debug"
            symbols "On"

        filter "configurations:Release"
            defines { "CS_RELEASE" }
            runtime "Release"
            optimize "On"

        filter "configurations:Dist"    
            defines { "CS_DIST" }
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
            "%{prj.name}/src/**.cpp",
            "%{prj.name}/src/**.hpp",
            "%{prj.name}/src/**.c",
            "%{prj.name}/src/**.cc"
        }
        
        includedirs
        {
            "Currsor/vendor/spdlog/include",
            "Currsor/src",
        }
        
        filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"
        
        defines
        {
            "CS_PLATFORM_WINDOWS",
        }

        links
        {
            "Currsor"
        }
        
        filter "configurations:Debug"
        defines { "CS_DEBUG" }
        runtime "Debug"
        
        filter "configurations:Release"
        defines { "CS_RELEASE" }
        runtime "Release"
        
        filter "configurations:Dist"
        defines { "CS_DIST" } 
        runtime "Release"