project "Vmath"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    targetdir ("bin-int/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/bin-int/" .. outputdir .. "/%{prj.name}")
    
    
    files 
    {
        "%{prj.name}/vmath/**.h",
        "%{prj.name}/vmath/**.cpp"
    }


    includedirs
    {
        "%{prj.name}/src",
    }

    filter "system:windows"
        staticruntime "On"
        systemversion "latest"

    filter "configurations:Debug"
        symbols "On"

    filter "configurations:Release"
        optimize "On"