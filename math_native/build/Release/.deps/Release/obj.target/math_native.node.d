cmd_Release/obj.target/math_native.node := flock ./Release/linker.lock g++ -shared -pthread -rdynamic -m32  -Wl,-soname=math_native.node -o Release/obj.target/math_native.node -Wl,--start-group Release/obj.target/math_native/src/addon.o Release/obj.target/math_native/src/Vector2.o -Wl,--end-group 