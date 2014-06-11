
cmake_minimum_required(VERSION 2.8)


if (PLATFORM_Android)
add_subdirectory( ./android )
endif(PLATFORM_Android)

if (PLATFORM_QT)
add_subdirectory( ./qt )
endif(PLATFORM_QT)

