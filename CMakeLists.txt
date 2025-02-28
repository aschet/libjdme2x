cmake_minimum_required(VERSION 3.10)

project(jdme2x
  VERSION 0.1.0
  DESCRIPTION "An implementation of the I++ DME interface version 2.5 as defined in VDMA 8722"
  LANGUAGES CXX
)

cmake_policy(SET CMP0167 NEW)

if(MSVC)
  set(CMAKE_DEBUG_POSTFIX "d")
endif()

find_package(Boost 1.80.0 CONFIG REQUIRED COMPONENTS headers spirit unit_test_framework)

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
  "include/jdme2x/Parser/CommandLexer.h"
  "include/jdme2x/Parser/CommandParser.h"
  "include/jdme2x/Parser/ResponseLexer.h"
  "include/jdme2x/Parser/ResponseParser.h"
  "include/jdme2x/Parser/TokenID.h"
  "include/jdme2x/API.h"
  "include/jdme2x/Argument.h"
  "include/jdme2x/Command.h"
  "include/jdme2x/Method.h"
  "include/jdme2x/Property.h"
  "include/jdme2x/Serializeable.h"
  "include/jdme2x/Tag.h"
)

set(FILES_SRC
  "src/Parser/CommandLexer.cpp"
  "src/Parser/CommandLexerDefinition.cpp"
  "src/Parser/CommandLexerDefinition.h"
  "src/Parser/CommandParser.cpp"
  "src/Parser/CommandParserStates.cpp"
  "src/Parser/CommandParserStates.h"
  "src/Parser/ResponseLexer.cpp"
  "src/Parser/ResponseParser.cpp"
  "src/Argument.cpp"
  "src/Command.cpp"
  "src/Method.cpp"
  "src/Property.cpp"
  "src/Serializeable.cpp"
  "src/Tag.cpp"
)

target_sources(${PROJECT_NAME}
  PRIVATE
    ${FILES_INCLUDE}
    ${FILES_SRC}
)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${FILES_INCLUDE} ${FILES_SRC})

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    jdme2x::jdme2x
    Boost::headers
    Boost::spirit
)

add_subdirectory(tests)
