# Simple Makefile wrapper to configure and build with CMake

BUILD_DIR := build
CMAKE := cmake
CMAKE_BUILD := cmake --build
CMAKE_FLAGS := -DCMAKE_BUILD_TYPE=Release


all: build

configure:
	@mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && $(CMAKE) .. $(CMAKE_FLAGS)

# Ensure configure runs before build. Use proper cmake --build invocation and parallel flag.
build: configure
	cd $(BUILD_DIR) && $(CMAKE_BUILD) . --parallel $(shell nproc)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all configure build clean
