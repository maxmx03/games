setup:
	meson setup build --wipe
compile:
	meson compile -C build
tidy:
	clang-tidy -p=build/compile_commands.json src/*.cpp -checks='-*, performance-* ,modernize-* ,clang-analyzer-*, google-*'
run: setup tidy compile
	./build/game

