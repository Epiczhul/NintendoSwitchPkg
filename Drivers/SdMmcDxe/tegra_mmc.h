#ifndef _TEGRA_MMC_H_
#define _TEGRA_MMC_H_

// Funktion zur Vorbereitung der Daten
void tegra_mmc_prepare_data(void* data, size_t size);

// Funktion zur Einstellung der Stromversorgung
void tegra_mmc_set_power(int power_level);

// Funktion zur Einstellung des Übertragungsmodus
void tegra_mmc_set_transfer_mode(int mode);

// Funktion zum Warten auf Inhibit-Bit
void tegra_mmc_wait_inhibit(void);

// Funktion zum Senden eines Bounced-Kommandos
void tegra_mmc_send_cmd_bounced(int cmd_index);

// Funktion zum Senden eines Kommandos
void tegra_mmc_send_cmd(int cmd_index);

// Funktion zur Initialisierung der Pad-Konfiguration
void tegra_mmc_pad_init(void);

// Funktion zum Ändern der Taktgeschwindigkeit
void tegra_mmc_change_clock(int clock_rate);

// Funktion zum Einstellen der I/O-Parameter
void tegra_mmc_set_ios(int bus_width, int clock_rate);

#endif // _TEGRA_MMC_H_
