> Public export: availability below describes the source base. Check `PUBLICATION.json` for excluded native databases and private authoring files.

# Published checkout availability

The table below is derived from the remote base tree used for this documentation
update. It makes newer maintainer-local source selections visible without claiming
that they are already in this clone. A documentation commit does not change
firmware sources, original binaries, toolchain pins or selected submodule commits.

| Entry point | Available in remote base |
| --- | --- |
| `SOURCE_MANIFEST.json` | Yes |
| `vendor/legacy-gpl/` | Yes |
| `vendor/port-context/` | Yes |
| `src/qdrv/` | Yes |
| `src/wlan/` | Yes |
| `src/platform/` | Yes |
| `src/compat/` | Yes |
| `analysis/index.json` | Yes |
| `manifests/` | Yes |
| `LICENSES/` | Yes |

## Submodule handoffs

Source and analysis submodule revisions stay pinned. Use the direct child
repository links in [the repository map](REPOSITORY_MAP.md) to read newer handoff
documentation; a parent clone intentionally retains the selected child revision.

## Integrity manifests

Where an artifact manifest includes README/documentation bytes, this update
refreshes only those members and aggregate counts. Existing non-document source
and evidence rows remain unchanged. Historical reports are not rewritten to
pretend that new builds or physical checks were run.
