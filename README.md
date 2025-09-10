
description:

    script helps invoking diamond deployment tool for encrypting bitstreams

prerequisites:

    linux
    installed lattice diamond or programmer standalone
    gcc
    openssl dev package

preparations:

    build shared library with make
    patch path to diamond in encrypt.sh

usage:

    go to project directory
    copy unencrypted bitstream to in.bit
    run ./encrypt.sh
    observe displayed messages to check for errors
    if everything is fine, encrypted bitstream will be in out.bit

disclaimer:

    tested only for ecp5 with diamond 3.14
    nothing is guaranteed, use at your own risk
