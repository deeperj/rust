cmake_minimum_required(VERSION 3.13)

project(qtmcu LANGUAGES CXX)
find_package(Qul)

add_executable(qtmcu)

target_include_directories(qtmcu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(qtmcu PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

qul_register_types(qtmcu led_wrapper.h)
qul_add_qml(qtmcu main.qml)

target_sources(qtmcu
    PRIVATE
        led.h
        led_wrapper.h
        led_stm32f769.cpp
)

target_link_libraries(qtmcu Qul::QuickUltralite Qul::QuickUltraliteControlsStyleDefault)
