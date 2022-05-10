file(GLOB SourceFiles Core/Utilities/Logger/Logger.cpp Core/App/*.cpp Core/Events/*.cpp Core/EventSystem/*.cpp Core/Renderer/*.cpp Core/Utilities/Logger/*.cpp)

add_library(Engine SHARED ${SourceFiles})
target_link_libraries(Engine PRIVATE ${CMAKE_SOURCE_DIR}/Libraries/libspdlog.a)
target_link_libraries(Engine PRIVATE GL GLU glfw3 X11 Xxf86vm Xrandr pthread Xi)
target_include_directories(Engine PUBLIC ${CMAKE_SOURCE_DIR}/Libraries/include/)
