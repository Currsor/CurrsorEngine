workspace "CurrsorEngine"
    architecture "x64"

    buildoptions { "/utf-8" }

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    
    -- 包含相对于根文件夹的目录（解决方案目录）
    include "Currsor/vendor/GLFW"
    include "Currsor/vendor/Glad"

    project "Currsor"
        location "Currsor"
        kind "SharedLib"
        language "C++"

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
        }

        links
        {
            "GLFW",
            "Glad",
            "opengl32.lib"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

            defines
            {
                "CS_PLATFORM_WINDOWS",
                "CS_BUILD_DLL",
                "GLFW_INCLUDE_NONE"
            }
        
        postbuildcommands
        {
            "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
        }
        
        filter "configurations:Debug"
            defines { "CS_DEBUG" }
            buildoptions { "/MDd" }
            symbols "On"

        filter "configurations:Release"
            defines { "CS_RELEASE" }
            buildoptions { "/MD" }
            optimize "On"

        filter "configurations:Dist"    
            defines { "CS_DIST" }
            buildoptions { "/MD" }
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
        staticruntime "On"
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
        buildoptions { "/MDd" }
        
        filter "configurations:Release"
        defines { "CS_RELEASE" }
        buildoptions { "/MD" }
        
        filter "configurations:Dist"
        defines { "CS_DIST" } 
        buildoptions { "/MD" }