project(examples)

macro(add_example target_name source_name)
  add_executable(${target_name} "${source_name}")
  target_link_libraries(${target_name} PRIVATE jdme2x::jdme2x)
  set_target_properties(${target_name} PROPERTIES FOLDER "examples")
endmacro()

add_example(building_example Building.cpp)
add_example(parsing_example Parsing.cpp)
