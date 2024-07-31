#define _CRT_SECURE_NO_WARNINGS

#include <Uefi.h>
#include <Library/UefiLib.h>
//#include <Library/UefiApplicationEntryPoint.h>
#include <Library/ShellCEntryLib.h>
#include <Library/BaseMemoryLib.h>
#include  <Library/BaseLib.h>
#include  <Library/BaseMemoryLib.h>


#define UTILITY_VERSION L"2022"


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
  //
  // skip preceeding white space
  //
  while (*Str != '\0' && *Str == ' ') {
    Str += 1;
  }

  //
  // skip preceeding zeros
  //
  while (*Str != '\0' && *Str == '0') {
    Str += 1;
  }

  //
  // skip preceeding white space
  //
  if ((*Str != '\0') && ((*Str == 'x') || (*Str == 'X'))) {
    Str += 1;
  }

  //
  // convert hex digits
  //
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

VOID
Usage( CHAR16 *Str,
       BOOLEAN ErrorMsg )
{
    if ( ErrorMsg ) {
        Print(L"ERROR: invalid options.\n");
    }
    Print(L"Usage: %s [-D | --debug] [-V | --version]\n", Str);
	Print(L"Example: %s dataToPutInBuffer\n");
}

UINT8
HexDigitToValue(char hex)
{
    UINT8 digit = 0;
    if (hex >= '0' && hex <= '9') {
      digit = hex - '0';
    } else if (hex >= 'a' && hex <= 'f') {
      digit = hex - 'a' + 10;
    } else if (hex >= 'A' && hex <= 'F') {
      digit = hex - 'A' + 10;
    } else {
      digit = -1;
    }
    return digit;
}


INTN
EFIAPI
ShellAppMain( UINTN Argc,
              CHAR16 **Argv )
{
  EFI_STATUS Status = EFI_SUCCESS;
  BOOLEAN debug = FALSE;

  if (Argc == 3 && (!StrCmp(Argv[2], L"-D") || !StrCmp(Argv[2], L"--debug"))) {
    Argc = 2;
    debug = TRUE;
  }

  if (Argc != 2) {
      Usage(Argv[0], TRUE);
      return Status;
  } else if (!StrCmp(Argv[1], L"--version") ||
      !StrCmp(Argv[1], L"-V")) {
      Print(L"Version: %s\n", UTILITY_VERSION);
      return Status;
  } else if (!StrCmp(Argv[1], L"--help") ||
      !StrCmp(Argv[1], L"-h")) {
      Usage(Argv[0], FALSE);
      return Status;
  } else {
      if (debug) {
        Print(L"Argv[1] is %s\n",Argv[1]);
      }
      UINT8 buff[15] = {0};

      UINTN strlen = StrLen(Argv[1]);

      if (strlen % 2 != 0) {
        Print(L"Hexstring must have even length.\n");
        return Status;
      }

      for (UINTN i = 0; i < strlen; i += 2) {
        UINT8 high = HexDigitToValue(Argv[1][i]);
        UINT8 low = HexDigitToValue(Argv[1][i+1]);
        if (high > 15 || low > 15) {
          Print(L"Invalid HexDigit: %c%c.\n", Argv[1][i], Argv[1][i+1]);
          Print(L"Allowed characters: [0-9] [a-f] [A-F].\n");
          return Status;
        }
        buff[i/2] = high * 0x10 + low;
      }

      if (debug) {
        Print(L"Buffer is at: 0x%2X\n", &buff);
      }

      for (UINTN i = 0; i < strlen/2; i++) {
        Print(L"%c",buff[i]);
      }
      Print(L"\n");

      //CopyMem(buff, (UINT8*)Argv[1], strlen);
      //CopyMem (&Buffer, &Argv[2], Xtoi(Argv[1]));
  }
  return EFI_SUCCESS;
}
