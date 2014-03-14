# Add header files in header files group
file(GLOB INCLUDE_FILES "${PROJECT_SOURCE_DIR}/include/schedules/*.h")
file(GLOB SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/schedules/*.cpp")

# Move the files in group.
source_group("Source Files" FILES ${SOURCE_FILES})
source_group("Header Files" FILES ${INCLUDE_FILES})

if(MSVC)
	add_definitions(-DSCHEDULESLIB)
else()
	# add_definitions(-D__GNUC__)
	add_definitions(-DSCHEDULESLIB)
endif()

# Executable file generate command.
add_library(schedules SHARED ${SOURCE_FILES} ${INCLUDE_FILES})

target_link_libraries(schedules core ${EXTRA_LIBS})

include_directories (${PROJECT_INCLUDE_DIR}/core ${PROJECT_INCLUDE_DIR}/schedules)
link_directories(${EXTRA_LIB_DIR})

install (TARGETS schedules DESTINATION bin)