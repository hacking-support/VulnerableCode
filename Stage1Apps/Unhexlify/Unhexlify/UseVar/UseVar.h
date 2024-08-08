#define VAR_NAME L"SampleVar" 
 
#define EFI_USEVAR_GUID {0xe35ab40b, 0x1116, 0x43a3, 0x91, 0x41, 0xa3, 0xcd, 0xa8, 0x85, 0x1, 0xb7} 
#define VAR_GUID {0x11299421, 0xa2a5, 0x4206, 0xb1, 0x93, 0x9c, 0xf3, 0xe8, 0x21, 0x29, 0x5c} 
 
 
//
// Initialization Functions
//
#define EFI_SHELL_APP_INIT(ImageHandle, SystemTable) \
  if (EFI_ERROR (LibInitializeShellApplication (ImageHandle, SystemTable)) \
      ) { \
    return EFI_ABORTED; \
  }

#define EFI_SHELL_STR_INIT(HiiHandle, ArrayName, Guid) \
  if (EFI_ERROR (LibInitializeStrings (&(HiiHandle), (ArrayName), &(Guid))) \
      ) { \
    return EFI_ABORTED; \
  }


  