"""Materialize preserved Quantenna source and readable REA evidence locally."""

import argparse
import hashlib
import json
from pathlib import Path
import re
import shutil


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path, required=True)
    args = parser.parse_args()
    source = args.source.resolve()
    destination = Path(__file__).resolve().parents[1]
    selections = [
        "vendor/legacy-gpl", "vendor/port-context", "src/qdrv", "src/wlan",
        "src/platform", "src/compat", "LICENSES", "docs/PROVENANCE.md",
        "docs/OEM-OPERATIONS.md", "docs/PORTABLE_BUILD.md",
        "manifests/build-qdrv.json", "manifests/build-wlan.json",
        "manifests/build-switch_tqe.json", "tools/build_driver.py",
        "tools/recover_hgw5g_driver_ops.py", "tools/elf_compare.py",
    ]
    evidence_names = [
        p.name for p in sorted((source / "evidence").iterdir())
        if p.is_dir() and p.name.startswith(("oem-", "ops-", "rea-"))
    ]
    evidence_names += [
        "qdrv-f370-qualification-20261021", "tqe-baseline-20261022",
        "wlan-baseline-20261022", "portable-qdrv-20261022-r1",
        "portable-tqe-20261022-r5", "portable-wlan-20261022-r3",
    ]
    selections += ["evidence/" + name for name in evidence_names]
    copied = []
    for selection in selections:
        current = source / selection
        if not current.exists():
            raise FileNotFoundError(current)
        paths = sorted(current.rglob("*")) if current.is_dir() else [current]
        for path in paths:
            if not path.is_file():
                continue
            if path.suffix.lower() in {".elf", ".ko", ".o", ".key", ".pem", ".p12"}:
                continue
            relative = path.relative_to(source)
            target = destination / relative
            target.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(path, target)
            copied.append({"path": relative.as_posix(), "bytes": path.stat().st_size,
                           "sha256": digest(path), "source_path": relative.as_posix()})
    functions = []
    for path in sorted((destination / "evidence").rglob("*.json")):
        try:
            envelope = json.loads(path.read_text(encoding="utf-8"))
        except (UnicodeError, ValueError):
            continue
        data = envelope.get("data", {}) if isinstance(envelope, dict) else {}
        raw_result = data.get("raw_result", {})
        value = raw_result.get("value", {}) if isinstance(raw_result, dict) else {}
        if not isinstance(value, dict) or not isinstance(value.get("pseudocode"), str):
            continue
        procedure = value.get("procedure", {})
        name = procedure.get("name", "unnamed")
        safe_name = re.sub(r"[^A-Za-z0-9_.-]", "_", name)
        relative_evidence = path.relative_to(destination).as_posix()
        directory = destination / "analysis" / path.parent.name / safe_name
        directory.mkdir(parents=True, exist_ok=True)
        (directory / "pseudocode.c").write_text(
            "/* REA/Ghidra decompiler output. Derived representation.\n"
            " * Evidence: " + relative_evidence + "\n"
            " * Subject SHA256: " + data.get("subject", {}).get("digest", {}).get("sha256", "unknown")
            + "\n */\n" + value["pseudocode"], encoding="utf-8")
        assembly = value.get("assembly", [])
        if isinstance(assembly, list):
            (directory / "assembly.asm").write_text("\n".join(map(str, assembly)) + "\n", encoding="utf-8")
        metadata = {
            "name": name, "procedure": procedure, "source_evidence": relative_evidence,
            "subject": data.get("subject"), "provider": data.get("provider"),
            "operation": data.get("operation"), "instruction_count": len(assembly),
            "limitations": data.get("limitations", []) + value.get("limitations", []),
            "relationship_coverage": data.get("relationship_coverage"),
        }
        (directory / "metadata.json").write_text(json.dumps(metadata, indent=2) + "\n", encoding="utf-8")
        functions.append({"name": name, "path": directory.relative_to(destination).as_posix(),
                          "instructions": len(assembly), "evidence": relative_evidence})
    (destination / "analysis/index.json").write_text(json.dumps(functions, indent=2) + "\n", encoding="utf-8")
    manifest = {"schema": "openmitrastar.component-export/v1", "source_repository":
                "https://github.com/apelsito/openmitrastar-hgw500-quantenna-5ghz-driver-public",
                "source_commit": "40ec2e98b63377282acb1613b57353547f9923d1",
                "date": "2026-11-03", "hardware_accessed": False,
                "copied_files": copied, "derived_functions": functions}
    (destination / "SOURCE_MANIFEST.json").write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"copied_files": len(copied), "derived_functions": len(functions),
                      "copied_bytes": sum(row["bytes"] for row in copied)}))


if __name__ == "__main__":
    main()
