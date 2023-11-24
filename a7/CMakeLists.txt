cmake_minimum_required(VERSION 3.25)
project(a7)

set(CMAKE_CXX_STANDARD 17)

add_executable(a7 main.cpp tests.h repo/repo.cpp repo/repo.h service/service.cpp service/service.h ui/ui.cpp ui/ui.h domain/user.cpp domain/user.h domain/event.cpp domain/event.h valid/valid.cpp valid/valid.h valid/valid.h)
