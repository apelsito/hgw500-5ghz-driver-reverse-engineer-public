# Preserved component notes

Editorial copy of the previous README. Workstation paths are normalized; original source and immutable evidence are not modified. Earlier status claims belong to their named checkpoints, not the live device. Start with the current [README](../README.md).

# HGW500 5 GHz driver reverse engineering

This private repository contains the recovered Quantenna Topaz/QMAC ARC700
driver sources and the preserved REA evidence used to investigate the OEM
Linux 2.6.35.12 driver lineage. The owner selected this component layout on
3 November 2026.

The source snapshot comes from commit
`40ec2e98b63377282acb1613b57353547f9923d1` of
`apelsito/openmitrastar-hgw500-quantenna-5ghz-driver`.
`SOURCE_MANIFEST.json` binds every copied file by SHA-256 and byte count.

| Folder | Material |
| --- | --- |
| `vendor/legacy-gpl/` | Preserved vendor GPL radio code and comments, byte for byte |
| `vendor/port-context/` | Shared headers adapted for the recovered driver |
| `src/qdrv/`, `src/wlan/`, `src/platform/`, `src/compat/` | Recovered Linux 5.10 reference source, including QDRV, WLAN and TQE |
| `analysis/` | Eight readable REA function dossiers, each with `pseudocode.c`, `assembly.asm` and provenance metadata |
| `analysis/index.json` | Function names, instruction counts and source evidence |
| `evidence/` | OEM operation inventory, retained REA JSON and baseline/portable build receipts |
| `manifests/build-*.json` | Executed ARC build flags and external dependency contracts |
| `tools/` | Import, integrity verification, operation inventory and portable rebuild helpers |
| `LICENSES/` | Preserved vendor and component licence texts |

The readable REA dossiers cover OEM QDRV getparam, QDRV init and setparam,
WLAN getparam/setparam, maximum system bandwidth, a linked QDRV init reference
and `topaz_tqe_xmit`. Each dossier identifies its original analysis subject.
Several subjects have synthetic addresses introduced for static analysis.
The assembly and C-like output retain the provider's observed representation.

The available GPL release is v37.4.0.62.1. The OEM binary lineage is
v37.4.0.89. The retained GPL therefore has explicit extension gaps.
Decompiler output is a derived representation with incomplete types and
indirect-call resolution. `metadata.json` retains the relevant limitations.

Historical offline receipts establish full operational static baseline
equivalence for QDRV and WLAN, with the declared `srcversion` metadata
difference, and byte-identical TQE reconstruction. These receipts concern
the Linux 5.10 reference. Physical 5 GHz client traffic, persistence and
release acceptance remain pending in the integration project.

Run the integrity check from this checkout with Python 3.

```powershell
python tools/verify_export.py
```

To regenerate this snapshot and readable dossiers from the preserved driver
checkout, use an explicit source path.

```powershell
python tools/import_existing_analysis.py --source ${WORKSPACE}/openmitrastar-hgw500-quantenna-5ghz-driver
```

The portable reference build accepts explicit kernel, generated ABI context,
toolchain and baseline-module paths. See `docs/PORTABLE_BUILD.md` and
`python tools/build_driver.py --help`. Those external inputs are required to
repeat the historical module comparison.

The maintained Linux 7.3 port lives in the sibling
`openmitrastar-hgw500-quantenna-5ghz-driver` repository. The three radio
coprocessor binary analyses live in `hgw500-5ghz-firmwares`.

## Arquitectura de procesamiento del HGW500

El [esquema y sus evidencias](../docs/HARDWARE_ARCHITECTURE.md), conservados el
3 de noviembre de 2026, identifican una CPU LHost ARC750 a 500 MHz y cuatro
coprocesadores: MuC, AuC, DSP y la MCU 8051 del RTL8192EE. Incluyen el inventario
SPI NOR de 16 MiB y el perfil DDR3 OEM de 128 MiB, con fuentes y límites.

![Arquitectura de procesamiento del HGW500](../docs/hardware/hgw500-processing-architecture.png)

El diagrama es una vista conceptual. La etiqueta qdrv describe el papel del
host; la integración física de 5 GHz en Core Boot R1 sigue pendiente.
