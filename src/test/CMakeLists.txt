# Add header files in header files group
file(GLOB INCLUDE_FILES "${PROJECT_SOURCE_DIR}/include/test/*.h")
file(GLOB SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/test/*.cpp")

# Move the files in group.
source_group("Source Files" FILES ${SOURCE_FILES})
source_group("Header Files" FILES ${INCLUDE_FILES})

# Find GTest library.
find_package(GTest REQUIRED)

set(GTEST_MAIN_INSTALL ${GTEST_MAIN_LIBRARIES})
set(GTEST_INSTALL ${GTEST_LIBRARIES})
	
# install gtest dll library.
if(MSVC)
	string(REGEX REPLACE "gtest_main.lib" "gtest_main.dll" GTEST_MAIN_INSTALL ${GTEST_MAIN_INSTALL})
	string(REGEX REPLACE "gtest\\.lib" "gtest.dll" GTEST_INSTALL ${GTEST_INSTALL})
endif()

install(FILES ${GTEST_MAIN_INSTALL} ${} DESTINATION bin)
install(FILES ${GTEST_INSTALL} ${} DESTINATION bin)

set(LINK_LIBRARIES "")
set(PROJECT_INCLUDE_DIR 
	${PROJECT_INCLUDE_DIR}/core 
	${PROJECT_INCLUDE_DIR}/affiliations
	${PROJECT_INCLUDE_DIR}/schedules
	${PROJECT_INCLUDE_DIR}/classifications
	${PROJECT_INCLUDE_DIR}/test
	${PROJECT_INCLUDE_DIR}/methods
	${PROJECT_INCLUDE_DIR}/transactions)

if (GTEST_FOUND)
	set (PROJECT_INCLUDE_DIR ${PROJECT_INCLUDE_DIR} ${GTEST_INCLUDE_DIRS})
	set (LINK_LIBRARIES ${LINK_LIBRARIES} ${GTEST_BOTH_LIBRARIES})
endif (GTEST_FOUND)

# Executable file generate command.
add_executable(test ${SOURCE_FILES} ${INCLUDE_FILES})

include_directories (${PROJECT_INCLUDE_DIR})
link_directories(${EXTRA_LIB_DIR})

target_link_libraries(test transactions core affiliations schedules classifications methods ${LINK_LIBRARIES})

install (TARGETS test DESTINATION bin)