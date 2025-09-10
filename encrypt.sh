#!/bin/sh
CURR_DIR=`pwd`
HOME_DIR=`cd ~ && pwd`
#DIAMOND_DIR=${HOME_DIR}/lscc/diamond/3.14/bin/lin64
DIAMOND_DIR=${HOME_DIR}/lscc/programmer/diamond/3.14/bin/lin64
LD_PRELOAD=${CURR_DIR}/xenc.so:libcrypto.so
export LD_PRELOAD
${DIAMOND_DIR}/ddtcmd -oft bit -if in.bit -of out.bit -encryption -key -ascii "enckeyenckeyenck"
