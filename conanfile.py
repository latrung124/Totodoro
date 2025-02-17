from conan import ConanFile

class ConanPackage(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"
    def requirements(self):
        self.requires("gtest/1.15.0")

    def build_requirements(self):
        self.tool_requires("cmake/3.22.6")
