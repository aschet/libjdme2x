project(jdme2x_examples)

macro(add_example target_name source_name)
  add_executable(${target_name} "${source_name}")
  target_link_libraries(${target_name} PRIVATE jdme2x::jdme2x)
  set_target_properties(${target_name} PROPERTIES FOLDER "examples/${target_name}")
endmacro()

add_example(jdme2x_parsing_example Parsing.cpp)
