#!/bin/bash

UEFI_IMAGE=uefi.img
UEFI_APP="../src/loader"
TMP_IMAGE=tmp.img

dd if=/dev/zero of="$UEFI_IMAGE" bs=512 count=93750

parted "$UEFI_IMAGE" -s -a minimal mklabel gpt
parted "$UEFI_IMAGE" -s -a minimal mkpart EFI FAT16 2048s 93716s
parted "$UEFI_IMAGE" -s -a minimal toggle 1 boot

dd if=/dev/zero of="$TMP_IMAGE" bs=512 count=91669

mformat -i "$TMP_IMAGE" -h 32 -t 32 -n 64 -c 1
mcopy -i "$TMP_IMAGE" "$UEFI_APP" ::
mcopy -i "$TMP_IMAGE" "test.txt" ::
dd if="$TMP_IMAGE" of="$UEFI_IMAGE" bs=512 count=91669 seek=2048 conv=notrunc
rm "$TMP_IMAGE"
