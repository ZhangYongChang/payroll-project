# Add header files in header files group
file(GLOB INCLUDE_FILES "${PROJECT_SOURCE_DIR}/include/transactions/*.h")
file(GLOB SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/transactions/*.cpp")

# Move the files in group.
source_group("Source Files" FILES ${SOURCE_FILES})
source_group("Header Files" FILES ${INCLUDE_FILES})

if(MSVC)
	add_definitions(-DTRANSACTIONSLIB)
else()
	# add_definitions(-D__GNUC__)
	add_definitions(-DTRANSACTIONSLIB)
endif()

# Executable file generate command.
add_library(transactions SHARED ${SOURCE_FILES} ${INCLUDE_FILES})

target_link_libraries(transactions affiliations classifications schedules methods database core ${EXTRA_LIBS})

include_directories (
	${PROJECT_INCLUDE_DIR}/core 
	${PROJECT_INCLUDE_DIR}/transactions
	${PROJECT_INCLUDE_DIR}/affiliations
	${PROJECT_INCLUDE_DIR}/classifications
	${PROJECT_INCLUDE_DIR}/methods
	${PROJECT_INCLUDE_DIR}/schedules
	${PROJECT_INCLUDE_DIR}/database)
	
link_directories(${EXTRA_LIB_DIR})

install (TARGETS transactions DESTINATION bin)