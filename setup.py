from distutils.core import setup, Extension

dinero_hash_module = Extension('dinero_hash',
                                 sources = ['dineromodule.c',
                                            'dinero.c',
                                            'sha3/blake.c',
                                            'sha3/bmw.c',
                                            'sha3/groestl.c',
                                            'sha3/jh.c',
                                            'sha3/keccak.c',
                                            'sha3/skein.c',
                                            'sha3/cubehash.c',
                                            'sha3/echo.c',
                                            'sha3/luffa.c',
                                            'sha3/simd.c',
                                            'sha3/shavite.c'],
                               include_dirs=['.', './sha3'])

setup (name = 'dinero_hash',
       version = '1.0.0',
       description = 'Binding for Dinero NeoScrypt proof of work hashing.',
       ext_modules = [dinero_hash_module])
