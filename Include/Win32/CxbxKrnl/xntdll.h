// ******************************************************************
// *
// *    .,-:::::    .,::      .::::::::.    .,::      .:
// *  ,;;;'````'    `;;;,  .,;;  ;;;'';;'   `;;;,  .,;; 
// *  [[[             '[[,,[['   [[[__[[\.    '[[,,[['  
// *  $$$              Y$$$P     $$""""Y$$     Y$$$P    
// *  `88bo,__,o,    oP"``"Yo,  _88o,,od8P   oP"``"Yo,  
// *    "YUMMMMMP",m"       "Mm,""YUMMMP" ,m"       "Mm,
// *
// *   Cxbx->Win32->CxbxKrnl->xntdll.h
// *
// *  This file is part of the Cxbx project.
// *
// *  Cxbx and Cxbe are free software; you can redistribute them
// *  and/or modify them under the terms of the GNU General Public
// *  License as published by the Free Software Foundation; either
// *  version 2 of the license, or (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// *  GNU General Public License for more details.
// *
// *  You should have recieved a copy of the GNU General Public License
// *  along with this program; see the file COPYING.
// *  If not, write to the Free Software Foundation, Inc.,
// *  59 Temple Place - Suite 330, Bostom, MA 02111-1307, USA.
// *
// *  (c) 2002-2003 Aaron Robinson <caustik@caustik.com>
// *
// *  All rights reserved
// *
// ******************************************************************
#ifndef XNTDLL_H
#define XNTDLL_H

#if defined(__cplusplus)
extern "C"
{
#endif

#include <ctype.h>  // winnt ntndis

// ******************************************************************
// * fixes some compiler errors and warnings
// ******************************************************************
#ifdef VOID
#undef VOID
#endif

// ******************************************************************
// * dll import/export
// ******************************************************************
#define DECLSPEC_IMPORT __declspec(dllimport)
#define DECLSPEC_EXPORT __declspec(dllexport)

// ******************************************************************
// * cxbx_krnl exports, others import
// ******************************************************************
#define NTSYSAPI     DECLSPEC_IMPORT

// ******************************************************************
// * CONST
// ******************************************************************
#define CONST               const

// ******************************************************************
// * Basic types
// ******************************************************************
typedef char                CHAR, CCHAR;
typedef short               SHORT;
typedef long                LONG;
typedef unsigned char       UCHAR;
typedef unsigned char       BYTE;
typedef unsigned char       BOOLEAN;
typedef unsigned short      USHORT;
typedef	unsigned short		WORD;
typedef unsigned long       ULONG;
typedef	unsigned long       DWORD;
typedef unsigned long       SIZE_T, *PSIZE_T;
typedef unsigned long       ACCESS_MASK;
typedef unsigned long       PHYSICAL_ADDRESS;
typedef long                INT_PTR;
typedef int                 BOOL;

// ******************************************************************
// * Pointer types
// ******************************************************************
typedef CHAR               *PCHAR;
typedef CHAR               *PCSZ;
typedef BYTE               *PBYTE;
typedef BOOLEAN            *PBOOLEAN;
typedef UCHAR              *PUCHAR;
typedef USHORT             *PUSHORT;
typedef ULONG              *PULONG;
typedef ULONG              *ULONG_PTR;
typedef ACCESS_MASK        *PACCESS_MASK;
typedef LONG               *LONG_PTR;
typedef INT_PTR            *PINT_PTR;
typedef void                VOID;
typedef VOID               *PVOID;
typedef void               *HANDLE;
typedef HANDLE             *PHANDLE;
typedef wchar_t             WCHAR, *PWCHAR;
typedef WCHAR              *LPWCH, *PWCH;
typedef CONST WCHAR        *LPCWCH, *PCWCH;
typedef WCHAR              *NWPSTR;
typedef WCHAR              *LPWSTR, *PWSTR;
typedef CONST WCHAR        *LPCWSTR, *PCWSTR;

// ******************************************************************
// * NTSTATUS
// ******************************************************************
typedef long                            NTSTATUS;
typedef unsigned __int64                ULONGLONG;

#define NT_SUCCESS(Status)              ((NTSTATUS) (Status) >= 0)

// ******************************************************************
// * calling conventions
// ******************************************************************
#define NTAPI               __stdcall
#ifndef CDECL
#define CDECL               __cdecl
#endif
#define INLINE              __inline
#define DECLSPEC_NORETURN   __declspec(noreturn)

// ******************************************************************
// * documentation purposes only
// ******************************************************************
#define EXPORTNUM(a)
#define UNALIGNED
#define OPTIONAL
#define IN
#define OUT

// ******************************************************************
// * KPROCESSOR_MODE
// ******************************************************************
typedef CCHAR KPROCESSOR_MODE;

// ******************************************************************
// * MODE
// ******************************************************************
typedef enum _MODE
{
    KernelMode,
    UserMode,
    MaximumMode
}
MODE;

// ******************************************************************
// * LARGE_INTEGER
// ******************************************************************
typedef struct _LARGE_INTEGER
{
    DWORD   LowPart;
    LONG    HighPart;
}
LARGE_INTEGER, *PLARGE_INTEGER;

// ******************************************************************
// * LDT_ENTRY
// ******************************************************************
typedef struct _LDT_ENTRY
{
    WORD    LimitLow;
    WORD    BaseLow;

    union
    {
        struct
        {
            BYTE    BaseMid;
            BYTE    Flags1;     // Declare as bytes to avoid alignment
            BYTE    Flags2;     // Problems.
            BYTE    BaseHi;
        }
        Bytes;

        struct
        {
            DWORD   BaseMid : 8;
            DWORD   Type : 5;
            DWORD   Dpl : 2;
            DWORD   Pres : 1;
            DWORD   LimitHi : 4;
            DWORD   Sys : 1;
            DWORD   Reserved_0 : 1;
            DWORD   Default_Big : 1;
            DWORD   Granularity : 1;
            DWORD   BaseHi : 8;
        }
        Bits;

    }
    HighWord;
}
LDT_ENTRY, *PLDT_ENTRY;

// ******************************************************************
// * STRING
// ******************************************************************
typedef struct _STRING
{
    USHORT  Length;
    USHORT  MaximumLength;
    PCHAR   Buffer;
}
STRING, ANSI_STRING, *PSTRING, *PANSI_STRING;

// ******************************************************************
// * RTL_HEAP_DEFINITION
// ******************************************************************
typedef struct _RTL_HEAP_DEFINITION
{
    ULONG   Length;
    ULONG   Unknown1;
    ULONG   Unknown2;
    ULONG   Unknown3;
    ULONG   Unknown4;
    ULONG   Unknown5;
    ULONG   Unknown6;
    ULONG   Unknown7;
    ULONG   Unknown8;
    ULONG   Unknown9;
    ULONG   Unknown10;
    ULONG   Unknown11;
    ULONG   Unknown12;
}
RTL_HEAP_DEFINITION, *PRTL_HEAP_DEFINITION;

// ******************************************************************
// * RTL_CRITICAL_SECTION
// ******************************************************************
typedef struct _RTL_CRITICAL_SECTION
{
    DWORD               Unknown[4];                                     // 0x00
	LONG                LockCount;                                      // 0x10
    LONG                RecursionCount;                                 // 0x14
    HANDLE              OwningThread;                                   // 0x18
    HANDLE              LockSemaphore;
    DWORD               Reserved;
}
RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION;

// ******************************************************************
// * Valid values for the Attributes field
// ******************************************************************
#define OBJ_INHERIT             0x00000002L
#define OBJ_PERMANENT           0x00000010L
#define OBJ_EXCLUSIVE           0x00000020L
#define OBJ_CASE_INSENSITIVE    0x00000040L
#define OBJ_OPENIF              0x00000080L
#define OBJ_OPENLINK            0x00000100L
#define OBJ_KERNEL_HANDLE       0x00000200L
#define OBJ_VALID_ATTRIBUTES    0x000003F2L

// ******************************************************************
// * UNICODE_STRING
// ******************************************************************
typedef struct _UNICODE_STRING
{
    USHORT Length;
    USHORT MaximumLength;
#ifdef MIDL_PASS
    [size_is(MaximumLength / 2), length_is((Length) / 2) ] USHORT * Buffer;
#else // MIDL_PASS
    PWSTR  Buffer;
#endif // MIDL_PASS
}
UNICODE_STRING, *PUNICODE_STRING;

typedef const UNICODE_STRING *PCUNICODE_STRING;

#define UNICODE_NULL ((WCHAR)0) // winnt

// ******************************************************************
// * OBJECT_ATTRIBUTES
// ******************************************************************
typedef struct _OBJECT_ATTRIBUTES
{
    ULONG           Length;
    HANDLE          RootDirectory;
    PUNICODE_STRING ObjectName;
    ULONG           Attributes;
    PVOID           SecurityDescriptor;        // Points to type SECURITY_DESCRIPTOR
    PVOID           SecurityQualityOfService;  // Points to type SECURITY_QUALITY_OF_SERVICE
}
OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;

// ******************************************************************
// * InitializeObjectAttributes
// * 
// * VOID
// * InitializeObjectAttributes(
// *     OUT POBJECT_ATTRIBUTES p,
// *     IN PUNICODE_STRING n,
// *     IN ULONG a,
// *     IN HANDLE r,
// *     IN PSECURITY_DESCRIPTOR s
// *     )
// * 
// ******************************************************************
#define InitializeObjectAttributes( p, n, a, r, s )     \
{                                                       \
    (p)->Length = sizeof( xntdll::OBJECT_ATTRIBUTES );  \
    (p)->RootDirectory = r;                             \
    (p)->Attributes = a;                                \
    (p)->ObjectName = n;                                \
    (p)->SecurityDescriptor = s;                        \
    (p)->SecurityQualityOfService = NULL;               \
}

// ******************************************************************
// * IO_STATUS_BLOCK
// ******************************************************************
typedef struct _IO_STATUS_BLOCK
{
    union
    {
        NTSTATUS Status;
        PVOID    Pointer;
    };

    ULONG_PTR Information;
}
IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;

// ******************************************************************
// * EVENT_TYPE
// ******************************************************************
typedef enum _EVENT_TYPE
{
    NotificationEvent = 0,
    SynchronizationEvent
}
EVENT_TYPE;

// ******************************************************************
// * CREATE_FILE_TYPE
// ******************************************************************
typedef enum _CREATE_FILE_TYPE
{
	CreateFileTypeNone,
	CreateFileTypeNamedPipe,
	CreateFileTypeMailslot
}
CREATE_FILE_TYPE;

// ******************************************************************
// * FILE_FS_SIZE_INFORMATION
// ******************************************************************
typedef struct _FILE_FS_SIZE_INFORMATION
{
    LARGE_INTEGER	TotalAllocationUnits;
    LARGE_INTEGER	AvailableAllocationUnits;
    ULONG		    SectorsPerAllocationUnit;
    ULONG		    BytesPerSector;
}
FILE_FS_SIZE_INFORMATION, *PFILE_FS_SIZE_INFORMATION;

// ******************************************************************
// * FILE_INFORMATION_CLASS
// ******************************************************************
typedef enum _FILE_INFORMATION_CLASS
{
    FileDirectoryInformation=1,
    FileFullDirectoryInformation,
    FileBothDirectoryInformation,
    FileBasicInformation,
    FileStandardInformation,
    FileInternalInformation,
    FileEaInformation,
    FileAccessInformation,
    FileNameInformation,
    FileRenameInformation,
    FileLinkInformation,
    FileNamesInformation,
    FileDispositionInformation,
    FilePositionInformation,
    FileFullEaInformation,
    FileModeInformation,
    FileAlignmentInformation,
    FileAllInformation,
    FileAllocationInformation,
    FileEndOfFileInformation,
    FileAlternateNameInformation,
    FileStreamInformation,
    FilePipeInformation,
    FilePipeLocalInformation,
    FilePipeRemoteInformation,
    FileMailslotQueryInformation,
    FileMailslotSetInformation,
    FileCompressionInformation,
    FileCopyOnWriteInformation,
    FileCompletionInformation,
    FileMoveClusterInformation,
    FileQuotaInformation,
    FileReparsePointInformation,
    FileNetworkOpenInformation,
    FileObjectIdInformation,
    FileTrackingInformation,
    FileOleDirectoryInformation,
    FileContentIndexInformation,
    FileInheritContentIndexInformation,
    FileOleInformation,
    FileMaximumInformation
}
FILE_INFORMATION_CLASS, *PFILE_INFORMATION_CLASS;

// ******************************************************************
// * FS_INFORMATION_CLASS
// ******************************************************************
typedef enum _FS_INFORMATION_CLASS
{
    FileFsVolumeInformation       = 1,
    FileFsLabelInformation,      // 2
    FileFsSizeInformation,       // 3
    FileFsDeviceInformation,     // 4
    FileFsAttributeInformation,  // 5
    FileFsControlInformation,    // 6
    FileFsFullSizeInformation,   // 7
    FileFsObjectIdInformation,   // 8
    FileFsMaximumInformation
}
FS_INFORMATION_CLASS, *PFS_INFORMATION_CLASS;

// ******************************************************************
// * KeDelayExecutionThread
// ******************************************************************
typedef NTSTATUS (NTAPI *KeDelayExecutionThread)
(
    IN KPROCESSOR_MODE  WaitMode,
    IN BOOLEAN          Alertable,
    IN PLARGE_INTEGER   Interval
);

// ******************************************************************
// * KeQuerySystemTime
// ******************************************************************
typedef VOID (NTAPI *FPTR_KeQuerySystemTime)
(
    PLARGE_INTEGER CurrentTime
);

// ******************************************************************
// * RtlCreateHeap
// ******************************************************************
typedef PVOID (NTAPI *FPTR_RtlCreateHeap)
(
    IN ULONG   Flags,
    IN PVOID   Base OPTIONAL,
    IN ULONG   Reserve OPTIONAL,
    IN ULONG   Commit,
    IN BOOLEAN Lock OPTIONAL,
    IN PVOID   RtlHeapParams OPTIONAL
);

// ******************************************************************
// * RtlAllocateHeap
// ******************************************************************
typedef PVOID (NTAPI *FPTR_RtlAllocateHeap)
(
    IN HANDLE hHeap,
    IN DWORD  dwFlags,
    IN SIZE_T dwBytes
);

// ******************************************************************
// * RtlFreeHeap
// ******************************************************************
typedef BOOL (NTAPI *FPTR_RtlFreeHeap)
(
    IN HANDLE hHeap,
    IN DWORD  dwFlags,
    IN PVOID  lpMem
);

// ******************************************************************
// * RtlNtStatusToDosError
// ******************************************************************
typedef ULONG (NTAPI *FPTR_RtlNtStatusToDosError)(NTSTATUS Status);

// ******************************************************************
// * RtlInitAnsiString
// ******************************************************************
typedef VOID (NTAPI *FPTR_RtlInitAnsiString)
(
  IN OUT PANSI_STRING   DestinationString,
  IN     PCSZ           SourceString
);

// ******************************************************************
// * RtlInitUnicodeString
// ******************************************************************
typedef VOID (NTAPI *FPTR_RtlInitUnicodeString)
(
  IN OUT PUNICODE_STRING DestinationString,
  IN     PCWSTR          SourceString
);

// ******************************************************************
// * NtDelayExecution
// ******************************************************************
typedef NTSTATUS (NTAPI *FPTR_NtDelayExecution)
(
    IN BOOLEAN          Alertable,
    IN PLARGE_INTEGER   DelayInterval
);

// ******************************************************************
// * NtSetLdtEntries
// ******************************************************************
typedef NTSTATUS (NTAPI *FPTR_NtSetLdtEntries)
(
    IN USHORT       Selector1,
    IN LDT_ENTRY    Descriptor1,
    IN USHORT       Selector2,
    IN LDT_ENTRY    Descriptor2
);

// ******************************************************************
// * NtAllocateVirtualMemory
// ******************************************************************
typedef NTSTATUS (NTAPI *FPTR_NtAllocateVirtualMemory)
(
  IN HANDLE               ProcessHandle,
  IN OUT PVOID            *BaseAddress,
  IN ULONG                ZeroBits,
  IN OUT PULONG           RegionSize,
  IN ULONG                AllocationType,
  IN ULONG                Protect
);

// ******************************************************************
// * RtlInitializeCriticalSection
// ******************************************************************
typedef VOID (NTAPI *FPTR_RtlInitializeCriticalSection)
(
  IN PRTL_CRITICAL_SECTION CriticalSection
);

// ******************************************************************
// * RtlEnterCriticalSection
// ******************************************************************
typedef VOID (NTAPI *FPTR_RtlEnterCriticalSection)
(
  IN PRTL_CRITICAL_SECTION CriticalSection
);

// ******************************************************************
// * RtlLeaveCriticalSection
// ******************************************************************
typedef VOID (NTAPI *FPTR_RtlLeaveCriticalSection)
(
  IN PRTL_CRITICAL_SECTION CriticalSection
);

// ******************************************************************
// * NtCreateEvent
// ******************************************************************
typedef NTSTATUS (NTAPI *FPTR_NtCreateEvent)
(
    OUT PHANDLE             EventHandle,
    IN  ACCESS_MASK         DesiredAccess,
    IN  POBJECT_ATTRIBUTES  ObjectAttributes OPTIONAL,
    IN  EVENT_TYPE          EventType,
    IN  BOOLEAN             InitialState
);

// ******************************************************************
// * NtCreateFile
// ******************************************************************
typedef NTSTATUS (NTAPI *FPTR_NtCreateFile)
(
	OUT PHANDLE				FileHandle,
	IN  ACCESS_MASK			DesiredAccess,
	IN  POBJECT_ATTRIBUTES	ObjectAttributes,
	OUT PIO_STATUS_BLOCK	IoStatusBlock,
	IN  PLARGE_INTEGER		AllocationSize OPTIONAL,
    IN  ULONG				FileAttributes,
    IN  ULONG				ShareAccess,
    IN  ULONG				CreateDisposition,
    IN  ULONG				CreateOptions,
	IN  PVOID				EaBuffer OPTIONAL,
	IN  ULONG				EaLength
);

// ******************************************************************
// * NtClose
// ******************************************************************
typedef NTSTATUS (NTAPI *FPTR_NtClose)
(
  IN HANDLE               Handle
);

// ******************************************************************
// * NtOpenFile
// ******************************************************************
typedef NTSTATUS (NTAPI *FPTR_NtOpenFile)
(
    OUT PHANDLE             FileHandle,
    IN  ACCESS_MASK         DesiredAccess,
    IN  POBJECT_ATTRIBUTES  ObjectAttributes,
    OUT PIO_STATUS_BLOCK    IoStatusBlock,
    IN  ULONG               ShareAccess,
    IN  ULONG               OpenOptions
);

// ******************************************************************
// * NtReadFile
// ******************************************************************
typedef NTSTATUS (NTAPI *FPTR_NtReadFile)
(
	IN  HANDLE          FileHandle,            // TODO: correct paramters
	IN  HANDLE          Event OPTIONAL,
	IN  PVOID           ApcRoutine OPTIONAL,
	IN  PVOID           ApcContext,
	OUT PVOID           IoStatusBlock,
	OUT PVOID           Buffer,
	IN  ULONG           Length,
	IN  PLARGE_INTEGER  ByteOffset OPTIONAL,
    IN  PULONG          Key OPTIONAL
);

// ******************************************************************
// * NtWriteFile
// ******************************************************************
typedef NTSTATUS (NTAPI *FPTR_NtWriteFile)
(
	IN  HANDLE          FileHandle,            // TODO: correct paramters
	IN  HANDLE          Event OPTIONAL,
	IN  PVOID           ApcRoutine OPTIONAL,
	IN  PVOID           ApcContext,
	OUT PVOID           IoStatusBlock,
	OUT PVOID           Buffer,
	IN  ULONG           Length,
	IN  PLARGE_INTEGER  ByteOffset OPTIONAL,
    IN  PULONG          Key OPTIONAL
);

// ******************************************************************
// * NtSetInformationFile
// ******************************************************************
typedef NTSTATUS (NTAPI *FPTR_NtSetInformationFile)
(	
	IN  HANDLE  FileHandle,            // TODO: correct paramters
	OUT	PVOID	IoStatusBlock,
	IN	PVOID	FileInformation,
	IN	ULONG	Length,
	IN	ULONG	FileInformationClass
);

// ******************************************************************
// * NtQueryInformationFile
// ******************************************************************
typedef NTSTATUS (NTAPI *FPTR_NtQueryInformationFile)
(
	IN  HANDLE                      FileHandle,
	OUT PIO_STATUS_BLOCK            IoStatusBlock,
	OUT PFILE_FS_SIZE_INFORMATION   FileInformation, 
	IN  ULONG                       Length, 
	IN  FILE_INFORMATION_CLASS      FileInfo
);

// ******************************************************************
// * NtQueryVolumeInformationFile
// ******************************************************************
typedef NTSTATUS (NTAPI *FPTR_NtQueryVolumeInformationFile)
(
    IN  HANDLE                      FileHandle,
    OUT PIO_STATUS_BLOCK            IoStatusBlock,
    OUT PFILE_FS_SIZE_INFORMATION   FileInformation,
    IN  ULONG                       Length,
    IN  FS_INFORMATION_CLASS        FsInformationClass
);

// ******************************************************************
// * IoCreateFile
// ******************************************************************
typedef NTSTATUS (NTAPI *FPTR_IoCreateFile)
(
	OUT PHANDLE				FileHandle,
	IN  ACCESS_MASK			DesiredAccess,
	IN  POBJECT_ATTRIBUTES	ObjectAttributes,
	OUT PIO_STATUS_BLOCK	IoStatusBlock,
	IN  PLARGE_INTEGER		AllocationSize OPTIONAL,
    IN  ULONG				FileAttributes,
    IN  ULONG				ShareAccess,
    IN  ULONG				Disposition,
    IN  ULONG				CreateOptions,
    IN  PVOID				EaBuffer OPTIONAL,
    IN  ULONG				EaLength,
    IN  CREATE_FILE_TYPE	CreateFileType,
    IN  PVOID				ExtraCreateParameters OPTIONAL,
    IN  ULONG				Options
);

#if defined(__cplusplus)
}
#endif

#endif
