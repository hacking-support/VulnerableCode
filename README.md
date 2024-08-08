# VulnerableCode
A repository that holds the source code for all vulnerable UEFI shell applications, drivers etc, for all 3 stages of DVUEFI.

This repository holds modified code that was intestinally made vulnerable, the code here was modifies and does not reflect on the original code quality.

# Building Instructions:
- Place this repository inside the Vulnerable-EDK2 folder on your drive, it should look like this:
  DVUEFI/vuln-edk2/VulnerableCode

- To build , run
  Your_Github_Folder/vuln-edk2/VulnerableCode
  DVUEFI\Vulnerable-EDK2\build -p .\VulnerableCode\VulnerableCode.dsc -a X64

- Once build is done , your built files can be found at
  DVUEFI\Vulnerable-EDK2\Build\VulnerableCode\DEBUG_GCC5\X64

# Links original source:
https://github.com/fpmurphy/UEFI-Utilities-2019
