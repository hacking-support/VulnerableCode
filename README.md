# VulnerableCode
A repository that holds the source code for all vulnerable UEFI shell applications , drivers etc.

This repository holds modifed code that was intentinally made vulnerable, the code here was modifies and does not reflect on the original code quality.

# Building instreuction:
- Place this repository inside the Vulnerable-EDK2 folder on your drive, it should look like this:
 A:\Your_Github_Folder\Vulnerable-EDK2\VulnerableCode
 
- To build , run 
  A:\Your_Github_Folder\Vulnerable-EDK2\build -p .\VulnerableCode\VulnerableCode.dsc -a X64

- Once build is done , your built files can be found at
  A:\Your_Github_Folder\Vulnerable-EDK2\Build\VulnerableCode\DEBUG_VS2019\X64
  
#Links to source locations:
https://github.com/fpmurphy/UEFI-Utilities-2019
