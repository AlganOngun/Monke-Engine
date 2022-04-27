file(GLOB SourceFiles Core/App/*.cpp Core/Utilities/Logger/*.cpp Core/Utilities/Logger/Logger.h)

add_library(Engine SHARED ${SourceFiles})
target_link_libraries(Engine PRIVATE ${CMAKE_SOURCE_DIR}/Libraries/libspdlog.a)
target_include_directories(Engine PRIVATE ${CMAKE_SOURCE_DIR}/Libraries/include/)
