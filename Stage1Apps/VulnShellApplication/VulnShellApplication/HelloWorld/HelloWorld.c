#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/ShellCEntryLib.h>
#include <Library/BaseMemoryLib.h>
#include  <Library/BaseLib.h>
#include  <Library/BaseMemoryLib.h>
#include  <stdlib.h>
#include  <string.h>
 
INTN
EFIAPI
ShellAppMain( UINTN Argc, 
              CHAR16 **Argv )
{ 
   Print (L"Hello World\n"); 
   Print (L"Goodbye World\n");   
   return EFI_SUCCESS; 
}