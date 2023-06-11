// Tegra-MMC-Controller-Header-Datei einbinden
include "tegra_mmc.h"

// Treiber-Entry-Punkt
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
    UNREFERENCED_PARAMETER(RegistryPath);

    NTSTATUS status;

    // Initialisierung des Treiber-Objekts
    DriverObject->DriverUnload = UnloadDriver;

    // Gerät erstellen
    PDEVICE_OBJECT deviceObject;
    status = IoCreateDevice(DriverObject, 0, NULL, FILE_DEVICE_DISK, FILE_DEVICE_SECURE_OPEN, FALSE, &deviceObject);
    if (!NT_SUCCESS(status))
    {
        return status;
    }

    // Gerät-Flags festlegen
    deviceObject->Flags |= DO_DIRECT_IO;
    deviceObject->Flags &= ~DO_DEVICE_INITIALIZING;

    // Tegra-MMC-Controller initialisieren
    status = TegraMmcInitialize();
    if (!NT_SUCCESS(status))
    {
        IoDeleteDevice(deviceObject);
        return status;
    }

    // Geräte-Verweis speichern
    DriverObject->DeviceObject = deviceObject;

    // Treiber erfolgreich initialisiert
    return STATUS_SUCCESS;
}

// Treiber entladen
VOID UnloadDriver(_In_ PDRIVER_OBJECT DriverObject)
{
    // Tegra-MMC-Controller freigeben
    TegraMmcCleanup();

    // Gerät-Objekt freigeben
    if (DriverObject->DeviceObject != NULL)
    {
        IoDeleteDevice(DriverObject->DeviceObject);
    }
}
