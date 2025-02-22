conan remote add conancenter https://center.conan.io --force
conan install . --output-folder=build --build=missing --remote=conancenter
cd build
./conanbuild.bat