import os
cwd = os.path.dirname(Dir('.').srcnode().abspath)
build_dir = os.path.join(cwd, 'build/')

print build_dir
env = Environment(CXXFLAGS='-std=c++11 -g',CPPPATH='src/')
env.VariantDir(variant_dir = 'build/common', src_dir = 'src/common', duplicate = 0)
env.VariantDir(variant_dir = 'build/dsource', src_dir = 'src/dsource', duplicate = 0)
env.VariantDir(variant_dir = 'build/nn', src_dir = 'src/nn', duplicate = 0)
env.VariantDir(variant_dir = 'build/sae', src_dir = 'src/sae', duplicate = 0)
env.VariantDir(variant_dir = 'build/dtype', src_dir = 'src/dtype', duplicate = 0)
env.VariantDir(variant_dir = 'build/utils', src_dir = 'src/utils', duplicate = 0)

src = ['dsource/Slice.cpp',
       'dsource/read.cpp',
       'nn/fbnn.cpp',
       'sae/sae.cpp',
       'utils/math.cpp',
       'utils/matlib.cpp',
       'nn/arch.cpp']


ffsrc = ['build/' + x for x in src]
env.Library(target='build/ffsae', source=ffsrc, LIBS=['matio'])
env.SharedLibrary(target='build/ffsae', source=ffsrc, LIBS=['matio'])
