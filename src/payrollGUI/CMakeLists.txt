# Add header files in header files group
file(GLOB INCLUDE_FILES "*.h")
file(GLOB SOURCE_FILES "*.cpp")
file(GLOB GUI_FILES "*.ui")

# Move the files in group.
source_group("Source Files" FILES ${SOURCE_FILES})
source_group("Header Files" FILES ${INCLUDE_FILES})
source_group("GUI Files" FILES ${GUI_FILES})

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

set(qt_UI ${GUI_FILES})

set(QOBJ_HDRS mainwindow.h 
	addcommisionedemployeedialog.h
	addhourlyemployeedialog.h
	addsalariedemployeedialog.h
	addsalesreceiptsdialog.h
	addtimecarddialog.h
	changascommisioneddialog.h
	changashourlyemployeedialog.h
	changassalarieddialog.h
	changeemployeeaddressdialog.h
	changenamedialog.h
	deleteemployeebyiddialog.h
	employeelistdialog.h)

qt4_wrap_ui(QTUICs ${qt_UI})
qt4_wrap_cpp(MOCSrcs ${QOBJ_HDRS})


if(MSVC) # Check if we are using the Visual Studio compiler
    install(FILES  ${QT_LIBRARY_DIR}/QtCore4.dll DESTINATION bin)
	install(FILES  ${QT_LIBRARY_DIR}/QtGui4.dll DESTINATION bin)
else()
	install(FILES  ${QT_LIBRARY_DIR}/QtCore4.so DESTINATION bin)
	install(FILES  ${QT_LIBRARY_DIR}/QtGui4.so DESTINATION bin)
endif()

set(LINK_LIBRARIES "")
set(PROJECT_INCLUDE_DIR 
	${PROJECT_INCLUDE_DIR}/core 
	${PROJECT_INCLUDE_DIR}/transactions)

# Executable file generate command.
add_executable(payrollGUI ${SOURCE_FILES} ${INCLUDE_FILES} ${MOCSrcs} ${QTUICs})

include_directories (${PROJECT_INCLUDE_DIR} ${QT_INCLUDES} ${PROJECT_BINARY_DIR}/src/payrollGUI)
link_directories(${EXTRA_LIB_DIR})

target_link_libraries(payrollGUI transactions core ${LINK_LIBRARIES} ${QT_QTMAIN_LIBRARY} ${QT_LIBRARIES})

install (TARGETS payrollGUI DESTINATION bin)

# Qt use GUI
IF(WIN32) # Check if we are on Windows
  if(MSVC) # Check if we are using the Visual Studio compiler
    set_target_properties(payrollGUI PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
  elseif(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")
    # SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows") # Not tested
  else()
    message(SEND_ERROR "You are using an unsupported Windows compiler! (Not MSVC or GCC)")
  endif()
elseif(UNIX)
  # Nothing special required
else()
  message(SEND_ERROR "You are on an unsupported platform! (Not Win32 or Unix)")
ENDIF()