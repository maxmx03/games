project('asteroids-raylib', 'cpp',
  version : '0.1',
  default_options : ['cpp_std=c++20'])

sources = [
    'src/main.cpp',
    'src/game.cpp',
    'src/controller.cpp'
]

inc = include_directories('include')
raylib = dependency('raylib')

executable('pong', sources,
           include_directories: inc,
           dependencies : raylib)
