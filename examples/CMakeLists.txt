file(GLOB OPENMP_EXAMPLES CONFIGURE_DEPENDS "*.cpp")

foreach(example_file IN LISTS OPENMP_EXAMPLES)
    get_filename_component(example ${example_file} NAME_WE)
    add_executable(${example} ${example_file})
    target_compile_features(${example} PRIVATE cxx_std_20)
    target_link_libraries(${example} PRIVATE OpenMP::OpenMP_CXX)
endforeach()