add_rules("mode.debug", "mode.release")
add_rules("plugin.vsxmake.autoupdate")

add_requires("glm")
add_requires("boost")

target("GalaxyMath")
    set_languages("c++20")
    set_kind("binary")
    add_includedirs("include")
    add_headerfiles("include/*.h")
    add_headerfiles("include/*.inl")
    add_files("main.cpp")

    add_packages("glm")
    add_packages("boost")
target_end()