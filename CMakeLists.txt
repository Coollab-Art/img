cmake_minimum_required(VERSION 3.8)

add_library(img)
add_library(img::img ALIAS img)
target_compile_features(img PRIVATE cxx_std_17)

# Set warning level
if(MSVC)
    target_compile_options(img PRIVATE /W4)
else()
    target_compile_options(img PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors -Wconversion -Wsign-conversion)
endif()

# Maybe enable warnings as errors
set(WARNINGS_AS_ERRORS_FOR_IMG OFF CACHE BOOL "ON iff you want to treat warnings as errors")
if(WARNINGS_AS_ERRORS_FOR_IMG)
    if(MSVC)
        target_compile_options(img PRIVATE /WX)
    else()
        target_compile_options(img PRIVATE -Werror)
    endif()
endif()

# ---Add stb_image---
add_library(stb_image "lib/stb_image/stb_image.cpp"
                      "lib/stb_image/stb_image_write.cpp")
target_link_libraries(img PUBLIC stb_image)

# ---Add source files---
target_include_directories(img INTERFACE include)
target_include_directories(img PUBLIC lib)
target_sources(img PRIVATE
    src/Save.cpp
    src/Load.cpp
)