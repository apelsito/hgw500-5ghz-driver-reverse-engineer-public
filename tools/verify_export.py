"""Verify source provenance and readable exports against preserved REA evidence."""

import hashlib
import json
from pathlib import Path


def main():
    root = Path(__file__).resolve().parents[1]
    manifest = json.loads((root / "SOURCE_MANIFEST.json").read_text())
    errors = []
    for row in manifest["copied_files"]:
        path = root / row["path"]
        if not path.is_file():
            errors.append("missing " + row["path"])
            continue
        content = path.read_bytes()
        if len(content) != row["bytes"] or hashlib.sha256(content).hexdigest() != row["sha256"]:
            errors.append("source mismatch " + row["path"])
    for row in manifest["derived_functions"]:
        evidence = json.loads((root / row["evidence"]).read_text())
        value = evidence["data"]["raw_result"]["value"]
        directory = root / row["path"]
        pseudo = (directory / "pseudocode.c").read_text()
        if not pseudo.endswith(value["pseudocode"]):
            errors.append("pseudocode mismatch " + row["path"])
        assembly = (directory / "assembly.asm").read_text()
        if assembly != "\n".join(map(str, value["assembly"])) + "\n":
            errors.append("assembly mismatch " + row["path"])
        metadata = json.loads((directory / "metadata.json").read_text())
        if metadata["subject"] != evidence["data"]["subject"]:
            errors.append("subject mismatch " + row["path"])
    print(json.dumps({"status": "PASS" if not errors else "FAIL",
                      "copied_files": len(manifest["copied_files"]),
                      "readable_functions": len(manifest["derived_functions"]),
                      "errors": errors, "hardware_accessed": False}, indent=2))
    return int(bool(errors))


if __name__ == "__main__":
    raise SystemExit(main())
