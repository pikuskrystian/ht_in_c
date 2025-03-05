cmake_minimum_required(VERSION 3.5)

project(ht_in_c LANGUAGES C)

add_executable(ht_in_c main.c

    prime.h
    hash_table.c
    hash_table.h
    prime.c)

include(GNUInstallDirs)
install(TARGETS ht_in_c
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
