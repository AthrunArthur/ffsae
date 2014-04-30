import os
cwd = os.path.dirname(Dir('.').srcnode().abspath)
build_dir = os.path.join(cwd, 'build/')

print build_dir
env = Environment(CXXFLAGS='-std=c++11',CPPPATH='src/')
env.VariantDir(variant_dir = 'build/common', src_dir = 'src/common', duplicate = 0)
env.VariantDir(variant_dir = 'build/dsource', src_dir = 'src/dsource', duplicate = 0)

src = ['dsource/Slice.cpp']


ffsrc = ['build/' + x for x in src]
env.Library(target='build/ffsae', source=ffsrc, LIBS=['matio'])
env.SharedLibrary(target='build/ffsae', source=ffsrc, LIBS=['matio'])
