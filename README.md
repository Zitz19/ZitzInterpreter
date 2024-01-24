# Task
You can find task in pdf in directory 'Task'. The number of my task is 62.

# Building project
You can easily build the project using cmake.\
For example (in project main directory):
```
mkdir build
cd build
cmake ..
make
```
It is important to run program from subdirectory!

# Project structure
1. In 'Maps' dir you can find 3 maps in .json format for testing robot-in-maze algorithm. \
For example:\
0_map.json - map #0\
0_robot.json - robot starting position\
0_commans.txt - log file which contains rotation/moving actions during the exit search program

2. In 'Programs' dir you can find my different test programs and two robot-maze algorithms.\
Files `ParserTest_\*.ztz` are using for auto testing. The `ParserTest_\*.ztz` is the program, `ParserResult_\*.txt` is the program prints and `ParserResult_\*_TEST.txt` is the correct sample of prints.

3. In 'include' dir you can find the main interpreter .h file, which contains all classes and methods and Niels Lohmann json-lib .h file.

# Run
You can run `./build/ZitzInterpreter` with `--debug` flag for bison debug prints or with `--test` flag for auto testing.
