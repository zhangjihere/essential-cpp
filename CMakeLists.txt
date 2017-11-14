cmake_minimum_required(VERSION 2.8)
project(essential_cpp)


set(CMAKE_CXX_STANDARD 11)

# chapter1
set(CHAP1_PATH source/chapter1/chap1)
set(CHAP1_SOURCE_FILES ${CHAP1_PATH}/ch1.cpp ${CHAP1_PATH}/ch1_main.cpp)
  add_executable(ch1 ${CHAP1_SOURCE_FILES})
set(CHAP1_SOLUTION_PATH source/chapter1/ch1solutions)
set(CHAP1_SOLUTION_SOURCE_FILES ${CHAP1_SOLUTION_PATH}/main.cpp)
  add_executable(ch1_solution ${CHAP1_SOLUTION_SOURCE_FILES})

# chapter2
set(CHAP2_PATH source/chapter2/chap2)
set(CHAP2_SOURCE_FILES ${CHAP2_PATH}/c2_main.cpp)
  add_executable(ch2 ${CHAP2_SOURCE_FILES})
set(CHAP2_SOLUTION_PATH source/chapter2/ch2solutions)
set(CHAP2_SOLUTION_SOURCE_FILES ${CHAP2_SOLUTION_PATH}/ch2main.cpp)
  add_executable(ch2_solution ${CHAP2_SOLUTION_SOURCE_FILES})

# chapter3
set(CHAP3_PATH source/chapter3/chap3)
set(CHAP3_SOURCE_FILES ${CHAP3_PATH}/ch3_main.cpp)
  add_executable(ch3 ${CHAP3_SOURCE_FILES})
set(CHAP3_SOLUTION_PATH source/chapter3/ch3solutions)
set(CHAP3_SOLUTION_SOURCE_FILES ${CHAP3_SOLUTION_PATH}/ch3main.cpp)
  add_executable(ch3_solution ${CHAP3_SOLUTION_SOURCE_FILES})

# chapter4
set(CHAP4_PATH source/chapter4/chap4)
set(CHAP4_SOURCE_FILES ${CHAP4_PATH}/ch4_main.cpp)
  add_executable(ch4 ${CHAP4_SOURCE_FILES})
set(CHAP4_POLY_PATH source/chapter4/polymorphic)
set(CHAP4_POLY_SOURCE_FILES ${CHAP4_POLY_PATH}/main.cpp)
  add_executable(ch4_polymorphic ${CHAP4_POLY_SOURCE_FILES})
set(CHAP4_SOLUTION_PATH source/chapter4/ch4solutions)
set(CHAP4_SOLUTION_SOURCE_FILES ${CHAP4_SOLUTION_PATH}/ch4main.cpp)
  add_executable(ch4_solution ${CHAP4_SOLUTION_SOURCE_FILES})

# chapter5
set(CHAP5_PATH source/chapter5/chap5)
set(CHAP5_SOURCE_FILES ${CHAP5_PATH}/c5_main.cpp)
  add_executable(ch5 ${CHAP5_SOURCE_FILES})
set(CHAP5_HYBRID_PATH source/chapter5/hybrid)
set(CHAP5_HYBRID_SOURCE_FILES ${CHAP5_HYBRID_PATH}/hybrid.cpp)
  add_executable(ch5_hybrid ${CHAP5_HYBRID_SOURCE_FILES})
set(CHAP5_INHER_PATH source/chapter5/inher)
set(CHAP5_INHER_SOURCE_FILES ${CHAP5_INHER_PATH}/classes.cpp)
  add_executable(ch5_inher ${CHAP5_INHER_SOURCE_FILES})
set(CHAP5_SOLUTION_PATH source/chapter5/ch5solutions)
set(CHAP5_SOLUTION_SOURCE_FILES ${CHAP5_SOLUTION_PATH}/ch5main.cpp)
  add_executable(ch5_solution ${CHAP5_SOLUTION_SOURCE_FILES})

# chapter6
set(CHAP6_PATH source/chapter6/chap6)
set(CHAP6_SOURCE_FILES ${CHAP6_PATH}/ch6_main.cpp)
  add_executable(ch6 ${CHAP6_SOURCE_FILES})
set(CHAP6_BINARYTREE_PATH source/chapter6/binarytree)
set(CHAP6_BINARYTREE_SOURCE_FILES ${CHAP6_BINARYTREE_PATH}/btree.cpp)
  add_executable(ch6_btree ${CHAP6_BINARYTREE_SOURCE_FILES})
set(CHAP6_STRATEGY_PATH source/chapter6/strategy)
set(CHAP6_STRATEGY_SOURCE_FILES ${CHAP6_STRATEGY_PATH}/s_main.cpp)
  add_executable(ch6_strategy ${CHAP6_STRATEGY_SOURCE_FILES})
set(CHAP6_SOLUTION_PATH source/chapter6/ch6solutions)
set(CHAP6_SOLUTION_SOURCE_FILES ${CHAP6_SOLUTION_PATH}/ch6main.cpp)
  add_executable(ch6_solution ${CHAP6_SOLUTION_SOURCE_FILES})

#log4cpp demo
set(LOG_EXAMPLE_PATH source/log4cpp)
#set(CMAKE_CXX_FLAGS "-llog4cpp -pthread") #配置连接库 liblog4cpp.so，以及-pthread 多线程支持
link_libraries(log4cpp pthread)
#拷贝log4cpp配置文件
#EXEC_PROGRAM(cp ARGS ${CMAKE_CURRENT_SOURCE_DIR}/configs/* -r .
#        OUTPUT_VARIABLE LS_OUTPUT RETURN_VALUE LS_RVALUE)
#IF (LS_RVALUE)
#    MESSAGE(STATUS "Copying config files - error: " ${LS_OUTPUT})
#ELSE ()
#    MESSAGE(STATUS "Copying config files - done")
#ENDIF ()

#log4cpp example
set(LOG_EXAMPLE_SRC_FILES ${LOG_EXAMPLE_PATH}/log_example.cpp)
  add_executable(log_exmp ${LOG_EXAMPLE_SRC_FILES})
#log4cpp properties example
set(LOG_PROP_EXAMPLE_SRC_FILES ${LOG_EXAMPLE_PATH}/log_prop_example.cpp)
  add_executable(log_prop_exmp ${LOG_PROP_EXAMPLE_SRC_FILES})
set(LOG_TEST_SRC_FILES ${LOG_EXAMPLE_PATH}/log_test.cpp)
  add_executable(log_test ${LOG_TEST_SRC_FILES})
set(prop_file_path ${PROJECT_SOURCE_DIR}/configs)
#should run 'build' modified cpp or h to invoke follow add_custom_command
add_custom_command(TARGET log_test        # Adds a post-build event to MyTest
    COMMAND echo "copy configs/*.properties file..."
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
    "${prop_file_path}/cp4cc_log.properties" "${prop_file_path}/log4cpp.properties" # <--this is in-file
    $<TARGET_FILE_DIR:log_test>)                 # <--this is out-file path

