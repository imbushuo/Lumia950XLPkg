#ifndef _DEVICE_MEMORY_MAP_H_
#define _DEVICE_MEMORY_MAP_H_

#include <Library/ArmLib.h>

#define MAX_ARM_MEMORY_REGION_DESCRIPTOR_COUNT 64

typedef enum {
    NoHob,
    AddMem,
    AddDev,
    AddReserved,
    MaxMem
} DeviceMemoryAddHob;

typedef struct {
  EFI_PHYSICAL_ADDRESS          PhysicalBase;
  EFI_VIRTUAL_ADDRESS           VirtualBase;
  UINT64                        Length;
  ARM_MEMORY_REGION_ATTRIBUTES  Attributes;
  DeviceMemoryAddHob            HobOption;
} ARM_MEMORY_REGION_DESCRIPTOR_EXTENDED, *PARM_MEMORY_REGION_DESCRIPTOR_EXTENDED;

static ARM_MEMORY_REGION_DESCRIPTOR_EXTENDED gDeviceMemoryDescriptor[] = 
{
    /* PhysicalBase, VirtualBase, Length, Attribute, HobOption */
    { 0x00010000, 0x00010000, 0x00014000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, NoHob },
    { 0x00024000, 0x00024000, 0x00002000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, NoHob },
    { 0x00100000, 0x00100000, 0x00100000, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem },
    { 0x00200000, 0x00200000, 0x00100000, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem },
    { 0x00300000, 0x00300000, 0x00080000, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem },
    { 0x00380000, 0x00380000, 0x00001000, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem },
    { 0x00381000, 0x00381000, 0x00004000, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem },
    { 0x00385000, 0x00385000, 0x00001000, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem },
    { 0x00386000, 0x00386000, 0x00003000, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem },
    { 0x00389000, 0x00389000, 0x00001000, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem },
    { 0x0038A000, 0x0038A000, 0x00004000, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem },
    { 0x0038E000, 0x0038E000, 0x00072000, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem },
    { 0x00400000, 0x00400000, 0x00800000, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_THROUGH, AddReserved },
    { 0x00C00000, 0x00C00000, 0x00040000, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem },
    { 0x00C40000, 0x00C40000, 0x00010000, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem },
    { 0x00D00000, 0x00D00000, 0x03300000, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem },
    { 0x04000000, 0x04000000, 0x02500000, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem },
    { 0x06500000, 0x06500000, 0x00500000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddReserved },
    { 0x06A00000, 0x06A00000, 0x00200000, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddReserved },
    { 0x06C00000, 0x06C00000, 0x00100000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddReserved },
    { 0x06D00000, 0x06D00000, 0x00160000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddReserved },
    { 0x06E60000, 0x06E60000, 0x00020000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddReserved },
    { 0x06E80000, 0x06E80000, 0x00180000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddReserved },
    { 0x07000000, 0x07000000, 0x07F00000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddReserved },
    { 0x0EF00000, 0x0EF00000, 0x00300000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddReserved },
    /* OS Memory Region */
    { 0x0F200000, 0x0F200000, 0x10E00000, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem },
    { 0x20000000, 0x20000000, 0xA0000000, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem },
    /* Register & Other Memory Regions */
    { 0xFE805000, 0xFE805000, 0x00001000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, NoHob },
    { 0xFE87F000, 0xFE87F000, 0x00001000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xF9000000, 0xF9000000, 0x00113000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xFC400000, 0xFC400000, 0x00002000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xFC428000, 0xFC428000, 0x00008000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xFD800000, 0xFD800000, 0x001DC000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xFC4A0000, 0xFC4A0000, 0x0000C000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xFC4C0000, 0xFC4C0000, 0x00010000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xFC404000, 0xFC404000, 0x0001C000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xFC444000, 0xFC444000, 0x0001C000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xFD3C4000, 0xFD3C4000, 0x0001C000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xFC4B8000, 0xFC4B8000, 0x00007000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xF9800000, 0xF9800000, 0x000E7000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xF9900000, 0xF9900000, 0x00069000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xF9A40000, 0xF9A40000, 0x00016000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xF9B30000, 0xF9B30000, 0x00008000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xF9200000, 0xF9200000, 0x0010D000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xF9BFF000, 0xF9BFF000, 0x00001000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xFD510000, 0xFD510000, 0x00004000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xFD480000, 0xFD480000, 0x00002000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xFD4A0000, 0xFD4A0000, 0x00010000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xF8800000, 0xF8800000, 0x00800000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { 0xFC528000, 0xFC528000, 0x00008000, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddDev },
    { }
};

#endif
