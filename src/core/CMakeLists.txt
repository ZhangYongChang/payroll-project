# Add header files in header files group
file(GLOB INCLUDE_FILES "${PROJECT_SOURCE_DIR}/include/core/*.h")
file(GLOB SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/core/*.cpp")

# Move the files in group.
source_group("Source Files" FILES ${SOURCE_FILES})
source_group("Header Files" FILES ${INCLUDE_FILES})

if(MSVC)
	add_definitions(-DCORELIB)
else()
	# add_definitions(-D__GNUC__)
	add_definitions(-DCORELIB)
endif()

# Executable file generate command.
add_library(core SHARED ${SOURCE_FILES} ${INCLUDE_FILES})

target_link_libraries(core ${EXTRA_LIBS})

include_directories (${PROJECT_INCLUDE_DIR}/core)
link_directories(${EXTRA_LIB_DIR})

install (TARGETS core DESTINATION bin)