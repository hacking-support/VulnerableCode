qemu-system-x86_64 \
  -drive if=pflash,format=raw,readonly=on,file=../OVMF/OVMF_CODE.fd \
  -drive if=pflash,format=raw,file=../OVMF/OVMF_VARS.fd \
  -drive file=fat:rw:./MountedDrive,media=disk,if=virtio,format=raw -net none -serial mon:stdio
