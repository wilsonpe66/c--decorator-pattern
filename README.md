# C++20 Decorator Pattern Using concepts

## Build debug

1. For the first time.
   - [ -d debug ] || mkdir debug
   - pushd debug
   - cmake -DCMAKE_BUILD_TYPE=Debug ..
   - make
   - popd
   - ls -la debug/bin

2. For the second time.
   - pushd debug
   - make
   - popd
   - ls -la debug/bin


## Build release

1. For the First time.
   - [ -d release ] || mkdir release
   - pushd release
   - cmake -DCMAKE_BUILD_TYPE=Release ..
   - make build-release
   - popd
   - ls -la release/bin

2. For the Second time.
   - pushd release
   - make build-release
   - popd

3. Install
   - pushd release
   - sudo make install
   - popd

