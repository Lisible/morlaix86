project('morlaix86', 'c')

incdir = include_directories('include')
lib = library(
  'morlaix86', 
  'src/cpu.c', 
  include_directories : incdir
)

emulator_exe = executable(
  'morlaix86-emu',
  'morlaix86-emu/main.c',
  include_directories : incdir,
  link_with : lib
)

