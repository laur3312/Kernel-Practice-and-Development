#include <ntddk.h>

void SampleUnload(_In_ PDRIVER_OBJECT DriverObject) {
    UNREFERENCED_PARAMETER(DriverObject);
    KdPrint(("Sample driver Unloaded successfully\n"));
}

extern "C"
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath) {
    UNREFERENCED_PARAMETER(RegistryPath);

    DriverObject->DriverUnload = SampleUnload;

    RTL_OSVERSIONINFOW os;
    os.dwOSVersionInfoSize = sizeof(RTL_OSVERSIONINFOW);

    RtlGetVersion(&os);

    KdPrint(("OS: %d.%d (Build %d)\n", os.dwMajorVersion, os.dwMinorVersion, os.dwBuildNumber));

    return STATUS_SUCCESS;