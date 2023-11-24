cmake_minimum_required(VERSION 3.25)
project(a45_clion)

set(CMAKE_CXX_STANDARD 17)

add_executable(a45_clion main.cpp d-arr/d-arr.cpp d-arr/d-arr.h domain/event.cpp domain/event.h service/old_service.cpp service/old_service.h ui/ui.cpp ui/ui.h repo/repo.cpp repo/repo.h d-arr/temp-dyn.h domain/user.cpp domain/user.h service/service.cpp service/service.h d-arr/temp-dyn.h tests.h)
