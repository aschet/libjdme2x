project(jdme2x_tests)

add_executable(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

set(FILES_SRC
  "Interfaces/Server/EndSessionTest.cpp"
  "Interfaces/Server/StartSessionTest.cpp"
  "Interfaces/Server/StopDaemonTest.cpp"
  "Parser/CommandParserTest.cpp"
  "Parser/LexerTest.cpp"
  "Parser/MethodParserTest.cpp"
  "Parser/ParserUtilsTest.cpp"
  "Parser/ResponseParserTest.cpp"
  "Types/ArgumentTest.cpp"
  "Types/CommandTest.cpp"
  "Types/DataTest.cpp"
  "Types/ErrorTest.cpp"
  "Types/MethodTest.cpp"
  "Types/NameTest.cpp"
  "Types/NumberTest.cpp"
  "Types/PropertyTest.cpp"
  "Types/ResponseTest.cpp"
  "Types/StringTest.cpp"
  "Types/TagTest.cpp"
  "Main.cpp"
  "TestUtils.h"
)

target_sources(${PROJECT_NAME}
  PRIVATE
    ${FILES_SRC}
)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${FILES_SRC})

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    jdme2x::jdme2x
    Boost::unit_test_framework
)

add_test(NAME jdme2x_tests COMMAND ${PROJECT_NAME})
