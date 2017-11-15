#COMPILER
Compiler =g++

Compiling_options=-Wall


links= -lmingw32 -lSDL2main -lSDL2 -mwindows -lSDL2_image

output_path=../bin/
output=teste

objects=*cc

include_path=-I"C:\SDL2pack\include"

lib_path=-L"C:\SDL2pack\lib"

compile:
	$(Compiler) $(Compiling_options) $(objects) $(include_path) $(lib_path) $(links) -o $(output_path)$(output)

debug:
	$(Compiler) $(Compiling_options) -g  $(objects) $(include_path) $(lib_path) $(links) -o $(output_path)$(output)
run:
	$(output_path)$(output)
