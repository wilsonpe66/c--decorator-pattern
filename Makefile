NUM_TREADS=16

build-both: build-debug build-release

build-debug:
	[ -d debug ] || mkdir debug && cd debug && cmake -DCMAKE_BUILD_TYPE=Debug ..
	cd debug && make -j$(NUM_TREADS)

build-release:
	[ -d release ] || mkdir release && cd release && cmake -DCMAKE_BUILD_TYPE=Release ..
	cd release && make -j$(NUM_TREADS)

install: build-release
	cd release && make -j$(NUM_TREADS) build-release && echo "Installing" && sudo make install

uninstall:
	cd release && sudo make uninstall

clean:
	[ -d debug ] && rm -rfv debug
	[ -d release ] && rm -rfv release
