cmake_minimum_required(VERSION 3.28)

include(pico_sdk_import.cmake)

project(blink C CXX ASM)


set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

set(PICO_EXAMPLES_PATH ${PROJECT_sSOURCE_DIR})

pico_sdk_init()


add_executable(blink
        blink.cpp
        )




        pico_enable_stdio_usb(blink 1)
        pico_enable_stdio_uart(blink 0)
# pull in common dependencies
target_link_libraries(blink pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(blink)

# add url via pico_set_program_url
#example_auto_set_url(blink)
