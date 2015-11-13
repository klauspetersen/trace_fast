#!python


VariantDir('build', 'src', duplicate=0)

# directly when constructing your Environment
env = Environment(
                CC = 'clang',
                CCFLAGS = ' `pkg-config --cflags glib-2.0 libusb-1.0` ',
                CXX = 'clang++',
                CXXFLAGS = '-std=c++11 -stdlib=libstdc++ `pkg-config --cflags glib-2.0` ',
                LINKFLAGS = '-stdlib=libstdc++ `pkg-config --libs glib-2.0 libusb-1.0` ',
                LIBS = ['glib-2.0'] )

includes = Split(
"""
src/extern/
src/extern/include
src/extern/hardware/saleae-logic16
""")


sources = Split(
"""
build/main.cpp
build/extern/std.c
build/extern/log.c
build/extern/session.c
build/extern/device.c
build/extern/hwdriver.c
build/extern/error.c
build/extern/usb.c
build/extern/ezusb.c
build/extern/resource.c
build/extern/hardware/saleae-logic16/api.c
build/extern/hardware/saleae-logic16/protocol.c
""")

# Include paths
env.Append(CPPPATH=includes)

env.Program(target='build/trace_fast', source=sources)
