#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/ShellLib.h>
#include <Library/ShellCEntryLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Protocol/Ebc.h>
//#include <Protocol/EfiShellInterface.h>
//#include <Protocol/LoadedImage.h>

#include  <stdlib.h>
#include  <string.h>
#include "UseVar.h"

//extern UINT8 STRING_ARRAY_NAME[]; 

  
EFI_STATUS 
OutputVar (void) 
{ 
   EFI_STATUS  Status; 
   EFI_GUID    VarGuid = VAR_GUID; 
   UINTN       BufferSize = 0; 
   VOID        *Buffer = NULL;
  
   // Pass in a zero size buffer to find the required buffer size.  
   Status = gRT->GetVariable (VAR_NAME, 
                             &VarGuid, 
                             NULL, 
                             &BufferSize, 
                             Buffer); 
                      
   if (Status == EFI_BUFFER_TOO_SMALL) { 
      // Allocate the buffer to hold the content of variable      
      Status = gBS->AllocatePool (EfiBootServicesData, 
                                 10, //Mac length can be only 10 characters, what can go wrong? YOLO!
                                 &Buffer); 
      if (EFI_ERROR (Status)) { 
         return Status; 
      } 
 
      // 
      // Read variable into the allocated buffer. 
      //     
      Status = gRT->GetVariable (VAR_NAME, 
                                &VarGuid, 
                                NULL, 
                                &BufferSize, 
                                Buffer); 
      if (EFI_ERROR (Status)) { 
          return Status; 
      }  
   } else if (EFI_NOT_FOUND == Status) { 
      Print(L"Variable 'SampleVar' not found!\n"); 
      return Status; 
   } 
    
   Print (L"The content of variable 'SampleVar' is %s:\n", Buffer); 
   gBS->FreePool (Buffer);   
      
   return Status; 
} 
  
 
EFI_STATUS 
WriteVar (CHAR16          *Str2Write) 
{ 
   EFI_STATUS  Status  = EFI_SUCCESS; 
   EFI_GUID    VarGuid = VAR_GUID; 
   UINTN       VarSize; 
    
   if (NULL == Str2Write) { 
      return EFI_INVALID_PARAMETER; 
   } 
 
   // Calculate the size of the string to write 
   // including the end NULL  
   VarSize = (StrLen (Str2Write) + 1) * sizeof (CHAR16); 
   Status = gRT->SetVariable (VAR_NAME, 
                             &VarGuid, 
                             EFI_VARIABLE_BOOTSERVICE_ACCESS|EFI_VARIABLE_RUNTIME_ACCESS|EFI_VARIABLE_NON_VOLATILE, 
                             VarSize, 
                             Str2Write); 
   if (EFI_ERROR (Status)) { 
       Print (L"Fail to write variable 'SampleVar'.\n"); 
   } 
    
   return Status;
} 
  
  

INTN
EFIAPI
ShellAppMain( UINTN Argc, 
              CHAR16 **Argv )
{ 
   EFI_STATUS     Status  = EFI_SUCCESS; 
   switch (Argc) { 
      case 1: 
         Status = OutputVar (); 
         break; 
    
      case 2: 
         if (!StrCmp(Argv[1], L"-?") ) { 
            Print (L"USEVAR [string | -?]\n\n       string - String will be written in variable\n                named 'SampleVar'.\n       -?     - Display the help information.\n \n Examples:\n  *To write a string into variable 'SampleVar':\n   fs0:\\> usevar \"EFI, One generation ahead!\"\n \n  *To display the content of variable 'SampleVar':\n    fs0:\\> usevar\n    The content of variable 'SampleVar' is:\n    EFI, One generation ahead!\n"); 
            break; 
         } 
         Status = WriteVar (Argv[1]); 
         break; 
      
      default: 
         Print(L"USEVAR [string | -?]\n\n       string - String will be written in variable\n                named 'SampleVar'.\n       -?     - Display the help information.\n \n Examples:\n  *To write a string into variable 'SampleVar':\n   fs0:\\> usevar \"EFI, One generation ahead!\"\n \n  *To display the content of variable 'SampleVar':\n    fs0:\\> usevar\n    The content of variable 'SampleVar' is:\n    EFI, One generation ahead!\n"); 
         break; 
   }     
   return Status; 
} 
 