# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/richard/esp/v5.2.1/esp-idf/components/bootloader/subproject"
  "/Users/richard/Documents/2024電機營/sample_code/DIY2/build/bootloader"
  "/Users/richard/Documents/2024電機營/sample_code/DIY2/build/bootloader-prefix"
  "/Users/richard/Documents/2024電機營/sample_code/DIY2/build/bootloader-prefix/tmp"
  "/Users/richard/Documents/2024電機營/sample_code/DIY2/build/bootloader-prefix/src/bootloader-stamp"
  "/Users/richard/Documents/2024電機營/sample_code/DIY2/build/bootloader-prefix/src"
  "/Users/richard/Documents/2024電機營/sample_code/DIY2/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/richard/Documents/2024電機營/sample_code/DIY2/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/richard/Documents/2024電機營/sample_code/DIY2/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
