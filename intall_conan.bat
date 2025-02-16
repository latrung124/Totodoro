conan remote add conancenter https://center.conan.io --force
conan install . --output-folder=build --build=missing
cd build
./conanbuild.bat