add_rules("mode.debug", "mode.release")
add_rules("plugin.vsxmake.autoupdate")

target("GalaxyMath")
    set_languages("c++20")
    set_kind("static")
    add_includedirs("include")
    add_files("src/*.cpp")
    add_headerfiles("include/*.h")
    add_headerfiles("include/*.inl")
target_end()