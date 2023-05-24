
add_executable(test_sm
    servicemanager/bctest.c
    )
target_link_libraries(test_sm ${DEPS})
