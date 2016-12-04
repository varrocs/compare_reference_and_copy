export CXX=g++
echo Running tests with $CXX
make clean && make && ./main

echo

export CXX=clang++
echo Running tests with $CXX
make clean && make && ./main
