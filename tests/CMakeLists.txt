project(jdme2x_tests)

add_executable(${PROJECT_NAME})

set(FILES_SRC
  "Parser/CommandLexerTest.cpp"
  "Parser/CommandParserTest.cpp"
  "Parser/ResponseLexerTest.cpp"
  "Parser/ResponseParserTest.cpp"
  "ArgumentTest.cpp"
  "CommandTest.cpp"
  "Main.cpp"
  "MethodTest.cpp"
  "PropertyTest.cpp"
  "TagTest.cpp"
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
