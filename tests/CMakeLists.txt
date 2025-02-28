project(jdme2x_tests)

add_executable(${PROJECT_NAME})

set(FILES_SRC
  "ArgumentTest.cpp"
  "CommandParserTest.cpp"
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

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    jdme2x::jdme2x
    Boost::unit_test_framework
)
