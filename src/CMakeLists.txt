file(GLOB SourceFiles Core/App/*.cpp Core/Events/*.cpp Core/EventSystem/*.cpp)

add_library(Engine SHARED ${SourceFiles})
target_link_libraries(Engine PRIVATE ${CMAKE_SOURCE_DIR}/Libraries/libspdlog.a)
target_include_directories(Engine PUBLIC ${CMAKE_SOURCE_DIR}/Libraries/include/)
