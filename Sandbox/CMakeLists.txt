cmake_minimum_required(VERSION 3.28)
project(Sandbox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include the Asura project
add_subdirectory(../Asura AsuraBuild)

# Add Sandbox source files
set(SANDBOX_SRC
    Application.cpp
)

# Create the Sandbox executable
add_executable(Sandbox ${SANDBOX_SRC})

# Link with the Asura library (choose static or shared)
target_link_libraries(Sandbox PRIVATE AsuraStatic)
# Or, if you prefer the shared library:
# target_link_libraries(Sandbox PRIVATE AsuraShared)

# Include Asura's public headers
target_include_directories(Sandbox PRIVATE ../Asura/include)
