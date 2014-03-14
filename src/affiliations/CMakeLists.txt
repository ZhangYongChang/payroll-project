# Add header files in header files group
file(GLOB INCLUDE_FILES "${PROJECT_SOURCE_DIR}/include/affiliations/*.h")
file(GLOB SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/affiliations/*.cpp")

# Move the files in group.
source_group("Source Files" FILES ${SOURCE_FILES})
source_group("Header Files" FILES ${INCLUDE_FILES})

if(MSVC)
	add_definitions(-DAFFILIATIONSLIB)
else()
	# add_definitions(-D__GNUC__)
	add_definitions(-DAFFILIATIONSLIB)
endif()

# Executable file generate command.
add_library(affiliations SHARED ${SOURCE_FILES} ${INCLUDE_FILES})

target_link_libraries(affiliations core ${EXTRA_LIBS})

include_directories (${PROJECT_INCLUDE_DIR}/core ${PROJECT_INCLUDE_DIR}/affiliations)
link_directories(${EXTRA_LIB_DIR})

install (TARGETS affiliations DESTINATION bin)