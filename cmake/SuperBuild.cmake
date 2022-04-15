include(ExternalProject)

find_package(DLSS QUIET)
if(NOT DLSS_FOUND)
    ExternalProject_Add(
        DLSSProject
        SOURCE_DIR ${PROJECT_SOURCE_DIR}/DLSS
        BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/DLSS/build
        INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/DLSS/install
        BUILD_ALWAYS ON
        CMAKE_ARGS
            -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
    )
else()
    add_custom_target(DLSSProject)
endif()

ExternalProject_Add(
    ThisProject
    DEPENDS
        DLSSProject
    SOURCE_DIR ${PROJECT_SOURCE_DIR}
    BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}
    INSTALL_COMMAND ""
    INSTALL_DIR ${CMAKE_INSTALL_PREFIX}
    CMAKE_ARGS
        -DRTGL1_SUPERBUILD=OFF
        -DDLSS_DIR=${CMAKE_CURRENT_BINARY_DIR}/DLSS/install/lib/cmake/DLSS
)

set(RTGL1_SUPERBUILD OFF)
