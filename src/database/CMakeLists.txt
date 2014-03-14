# Add header files in header files group
file(GLOB INCLUDE_FILES "${PROJECT_SOURCE_DIR}/include/database/*.h")
file(GLOB SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/database/*.cpp")

# Move the files in group.
source_group("Source Files" FILES ${SOURCE_FILES})
source_group("Header Files" FILES ${INCLUDE_FILES})

if(MSVC)
	add_definitions(-DDATABASELIB)
else()
	# add_definitions(-D__GNUC__)
	add_definitions(-DDATABASELIB)
endif()

# Executable file generate command.
add_library(database SHARED ${SOURCE_FILES} ${INCLUDE_FILES})

target_link_libraries(database methods classifications affiliations schedules core ${EXTRA_LIBS})

include_directories (
	${PROJECT_INCLUDE_DIR}/core 
	${PROJECT_INCLUDE_DIR}/database 
	${PROJECT_INCLUDE_DIR}/affiliations
	${PROJECT_INCLUDE_DIR}/schedules
	${PROJECT_INCLUDE_DIR}/classifications
	${PROJECT_INCLUDE_DIR}/methods)
	
link_directories(${EXTRA_LIB_DIR})

install (TARGETS database DESTINATION bin)