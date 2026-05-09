project('bird', 'cpp',
  version : '0.1',
  default_options : ['cpp_std=c++20', 'warning_level=3'])

sources = [
    'src/main.cpp',
    'src/game.cpp',
    'src/player.cpp',
    'src/controller.cpp'
]

inc = include_directories('include')
raylib = dependency('raylib')

executable('game', sources,
           include_directories: inc,
           dependencies : raylib)
