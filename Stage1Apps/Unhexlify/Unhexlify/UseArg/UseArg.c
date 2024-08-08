#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/ShellCEntryLib.h>
#include <Library/BaseMemoryLib.h>
#include  <Library/BaseLib.h>
#include  <Library/BaseMemoryLib.h>
#include  <stdlib.h>
#include  <string.h>
 
#define BUFFER_LENGTH 10

UINTN
EFIAPI
Xtoi (
  CHAR16  *Str
  )
{
  UINTN   RetVal;
  CHAR16  TempChar;
  UINTN   MaxVal;
  MaxVal = (UINTN)-1 >> 4;
  while (*Str != '\0' && *Str == ' ') {
    Str += 1;
  }
  while (*Str != '\0' && *Str == '0') {
    Str += 1;
  }
  if ((*Str != '\0') && ((*Str == 'x') || (*Str == 'X'))) {
    Str += 1;
  }
  RetVal   = 0;
  TempChar = *(Str++);
  while (TempChar != '\0') {
    if ((TempChar >= 'a') && (TempChar <= 'f')) {
      TempChar -= 'a' - 'A';
    }
    if (((TempChar >= '0') && (TempChar <= '9')) || ((TempChar >= 'A') && (TempChar <= 'F'))) {
      if (RetVal > MaxVal) {
        return (UINTN)-1;
      }

      RetVal = (RetVal << 4) | (TempChar - (TempChar >= 'A' ? 'A' - 10 : '0'));
    } else {
      break;
    }

    TempChar = *(Str++);
  }

  return RetVal;
}

INTN
EFIAPI
ShellAppMain( UINTN Argc, 
              CHAR16 **Argv )
{ 
   UINTN Index;
   
   UINTN buffer[BUFFER_LENGTH];
   
   Print (L"The arguments are:\n"); 
   for (Index = 0; Index < Argc; Index++) {
	  ZeroMem(&buffer,BUFFER_LENGTH);
	  CopyMem(&buffer,StrHexToUintn(Argv[Index]),StrLen(Argv[Index]));
	  Print (L"%s\n", buffer); 
	  
   } 
    
   return EFI_SUCCESS; 
}