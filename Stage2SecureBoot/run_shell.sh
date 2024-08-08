set -e

# We mass pass the PK ourselves
# See https://bugzilla.tianocore.org/show_bug.cgi?id=1747
pk=$(cat certs/PkKek1.oemstr)

qemu-system-x86_64 \
  -drive if=pflash,format=raw,readonly=on,file=OVMF/OVMF_CODE.fd \
  -drive if=pflash,format=raw,file=OVMF/OVMF_VARS.fd \
  -smbios type=11,value="${pk}" \
  -drive file=fat:rw:./CommonApps,media=disk,if=virtio,format=raw -net none -serial mon:stdio
