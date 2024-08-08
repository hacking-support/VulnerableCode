#!/bin/bash

set -e

BuildDir="../../Build/OvmfX64/DEBUG_GCC5"

if ! test -d ${BuildDir} ; then
    echo "${BuildDir} does not exist: make sure to build OVMF first!"
fi


echo "Copying fresh OVMF"
# Copy over the OVMF
cp "${BuildDir}/FV/OVMF_VARS.fd" OVMF/OVMF_VARS.fd
cp "${BuildDir}/FV/OVMF_CODE.fd" OVMF/OVMF_CODE.fd

echo "Copying common apps"
# Copy over EnrollDefaultKeys.efi for SecureBoot setup
cp "${BuildDir}/X64/EnrollDefaultKeys.efi" CommonApps

echo "Setup Complete"
