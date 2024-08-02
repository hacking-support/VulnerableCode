/** @file
  TODO: Brief Description of UEFI Driver VulnGetVarDriver
  
  TODO: Detailed Description of UEFI Driver VulnGetVarDriver

  TODO: Copyright for UEFI Driver VulnGetVarDriver
  
  TODO: License for UEFI Driver VulnGetVarDriver

**/

#ifndef __EFI_DRIVER_TEMPLATE_H__
#define __EFI_DRIVER_TEMPLATE_H__

#include <Uefi.h>

//
// Libraries
//
#include <Library/UefiBootServicesTableLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/BaseLib.h>
#include <Library/UefiLib.h>
#include <Library/DevicePathLib.h>
#include <Library/DebugLib.h>

//
// UEFI Driver Model Protocols
//
#include <Protocol/DriverBinding.h>

//
// Consumed Protocols
//
#include <Protocol/PciIo.h>

//
// Produced Protocols
//
#include <Protocol/SimpleTextOut.h>

//
// Guids
//

//
// Driver Version
//
#define DRIVER_TEMPLATE_VERSION  0x00000000

//
// Protocol instances
//
extern EFI_DRIVER_BINDING_PROTOCOL  gVulnGetVarDriverDriverBinding;

//
// Include files with function prototypes
//
#include "DriverBinding.h"
#include "SimpleTextOutput.h"

#endif
