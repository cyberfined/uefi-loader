#!/bin/sh
qemu-system-x86_64 -enable-kvm -cpu host \
    -drive if=pflash,format=raw,unit=0,file=./OVMF_CODE.fd,readonly=on \
    -drive if=pflash,format=raw,unit=1,file=./OVMF_VARS.fd -net none -drive if=ide,format=raw,file=uefi.img
