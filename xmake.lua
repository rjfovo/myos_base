target("sqlite_test")
    set_kind("binary")
    add_includedirs("internal_include/sqlite/")

    add_files("third_part/sqlite/*.cc") 
    add_files("main/sqlite_test.cc") 

    add_links("gmock");
    add_links("gmock_main");
    add_links("gtest");
    add_links("gtest_main");
    add_links("sqlite3");