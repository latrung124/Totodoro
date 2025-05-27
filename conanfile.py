from conan import ConanFile

class ConanPackage(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("gtest/1.15.0")
        self.requires("protobuf/5.27.0")
        self.requires("yaml-cpp/0.8.0")
        self.requires("cpp-httplib/0.18.0")
        self.requires("sqlitecpp/3.3.2")
        self.requires("zlib/1.3.1")
        self.requires("openssl/3.2.0")
        self.requires("nlohmann_json/3.11.3")

    def build_requirements(self):
        self.tool_requires("cmake/3.22.6")
