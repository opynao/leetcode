add_test( Correctness.Test /mnt/c/vika/leetcode/strings/string_compression/__build_gcc/string_compression_tests [==[--gtest_filter=Correctness.Test]==] --gtest_also_run_disabled_tests)
set_tests_properties( Correctness.Test PROPERTIES WORKING_DIRECTORY /mnt/c/vika/leetcode/strings/string_compression/__build_gcc SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( Speed.Test_SymbolsAreRandom /mnt/c/vika/leetcode/strings/string_compression/__build_gcc/string_compression_tests [==[--gtest_filter=Speed.Test_SymbolsAreRandom]==] --gtest_also_run_disabled_tests)
set_tests_properties( Speed.Test_SymbolsAreRandom PROPERTIES WORKING_DIRECTORY /mnt/c/vika/leetcode/strings/string_compression/__build_gcc SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test( Speed.Test_SymbolIsTheSame /mnt/c/vika/leetcode/strings/string_compression/__build_gcc/string_compression_tests [==[--gtest_filter=Speed.Test_SymbolIsTheSame]==] --gtest_also_run_disabled_tests)
set_tests_properties( Speed.Test_SymbolIsTheSame PROPERTIES WORKING_DIRECTORY /mnt/c/vika/leetcode/strings/string_compression/__build_gcc SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( string_compression_tests_TESTS Correctness.Test Speed.Test_SymbolsAreRandom Speed.Test_SymbolIsTheSame)