add_rules("mode.debug", "mode.release")
add_rules("plugin.vsxmake.autoupdate")

add_requires("glm")

target("GalaxyMath")
    set_languages("c++20")
    set_kind("binary")
    add_includedirs("include")
    add_headerfiles("include/*.h")
    add_headerfiles("include/*.inl")
    add_files("main.cpp")

    add_packages("glm")
target_end()