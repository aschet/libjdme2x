cmake_minimum_required(VERSION 3.10)

project(jdme2x
  VERSION 0.1.0
  DESCRIPTION "An implementation of the I++ DME interface version 2.5 as defined in VDMA 8722"
  LANGUAGES CXX
)

if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
  set(CMAKE_DEBUG_POSTFIX "d")
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra)
endif()

find_package(Boost 1.70.0 CONFIG REQUIRED COMPONENTS headers unit_test_framework)

add_library(${PROJECT_NAME})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME}
  PUBLIC
    cxx_std_17
) 

target_include_directories(${PROJECT_NAME}
  PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

if(BUILD_SHARED_LIBS)
  target_compile_definitions(${PROJECT_NAME}
    PUBLIC
      JDME2X_DLL
    PRIVATE
      JDME2X_EXPORT
  )
endif()

set(FILES_INCLUDE
  "include/jdme2x/Client/MethodBuilder.h"
  "include/jdme2x/Parser/CommandParser.h"
  "include/jdme2x/Parser/Lexer.h"
  "include/jdme2x/Parser/MethodParser.h"
  "include/jdme2x/Parser/ParserUtils.h"
  "include/jdme2x/Parser/ResponseParser.h"
  "include/jdme2x/Types/Acknowledge.h"
  "include/jdme2x/Types/Argument.h"
  "include/jdme2x/Types/Command.h"
  "include/jdme2x/Types/Data.h"
  "include/jdme2x/Types/Done.h"
  "include/jdme2x/Types/Error.h"
  "include/jdme2x/Types/Errors.h"
  "include/jdme2x/Types/Method.h"
  "include/jdme2x/Types/Name.h"
  "include/jdme2x/Types/Number.h"
  "include/jdme2x/Types/Response.h"
  "include/jdme2x/Types/String.h"
  "include/jdme2x/Types/Property.h"
  "include/jdme2x/Types/Tag.h"
  "include/jdme2x/API.h"
  "include/jdme2x/MethodNames.h"
)

set(FILES_SRC
  "src/Client/MethodBuilder.cpp"
  "src/Parser/CommandParser.cpp"
  "src/Parser/CommandParserStates.cpp"
  "src/Parser/CommandParserStates.h"
  "src/Parser/Lexer.cpp"
  "src/Parser/MethodParser.cpp"
  "src/Parser/MethodParserStates.cpp"
  "src/Parser/MethodParserStates.h"
  "src/Parser/ParserState.h"
  "src/Parser/ParserUtils.cpp"
  "src/Parser/PropertyParserStates.cpp"
  "src/Parser/PropertyParserStates.h"
  "src/Parser/ResponseParser.cpp"
  "src/Parser/ResponseParserStates.cpp"
  "src/Parser/ResponseParserStates.h"
  "src/Types/Acknowledge.cpp"
  "src/Types/Argument.cpp"
  "src/Types/Command.cpp"
  "src/Types/Data.cpp"
  "src/Types/Done.cpp"
  "src/Types/Error.cpp"
  "src/Types/Method.cpp"
  "src/Types/Name.cpp"
  "src/Types/Number.cpp"
  "src/Types/Property.cpp"
  "src/Types/StreamUtils.h"
  "src/Types/Response.cpp"
  "src/Types/String.cpp"
  "src/Types/Tag.cpp"
)

target_sources(${PROJECT_NAME}
  PRIVATE
    ${FILES_INCLUDE}
    ${FILES_SRC}
)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${FILES_INCLUDE} ${FILES_SRC})

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    Boost::headers
)

include(CTest)
add_subdirectory(tests)
add_subdirectory(examples)
