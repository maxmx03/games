project('cpp-course', 'cpp',
  version : '0.1',
  default_options : ['cpp_std=c++17'])

# 1. Encontrar as dependências da SFML
sfml_graphics_dep = dependency('raylib')

# 2. Criar uma lista com todas elas
sfml_deps = [
  sfml_graphics_dep,
]

# 3. Adicionar a lista de dependências ao executável
executable('program', 'main.cpp',
           dependencies : sfml_deps)
