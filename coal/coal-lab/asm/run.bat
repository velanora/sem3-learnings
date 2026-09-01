@echo off
REM %1 is the place holder of the file i type after run as a parameter
REM It asks the assembler nasm to convert the file nto executable file
nasm %1.asm -o %1.com
REM Runs debugger
REM and let us go through complied file instruction-by-instruction
REM It inspects registors, memory, flags etc
REM "Load the complied file and let me debug it"
afd %1.com