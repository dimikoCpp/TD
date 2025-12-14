#scons && bin\td.exe

env = Environment(tools = ['mingw'])
env.Program(
    target = "bin/td.exe",
    source = [
        Glob("*.cpp"),
        Glob("engine/*.cpp"),
        Glob("game/menu/*.cpp"),
        Glob("game/*.cpp"),
    ],
    LIBPATH = "SFML-3.0.2/lib",
    LIBS = [
        "sfml-graphics-d",
        "sfml-window-d",
        "sfml-system-d",
    ],
    CXXFLAGS = "-O0 -g0 -pipe",
    LINKFLAGS = "-shared-libgcc", # -mwindows 
    CPPPATH = ["SFML-3.0.2/include", "."],
)
