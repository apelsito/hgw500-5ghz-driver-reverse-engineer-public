/* REA/Ghidra decompiler output. Derived representation.
 * Evidence: evidence/oem-wlan-maxbw-20261022T143000Z-r1/rea.json
 * Subject SHA256: 79fbcbd4634a9fc32fdf8ac0c997f3bd0329131162a1ea4948794e4986c7e40a
 */

byte ieee80211_get_max_system_bw(int param_1)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = *(byte *)(param_1 + 0x4df1);
  if (bVar2 < 0x50) {
    if (bVar2 < 0x28) {
      return bVar2;
    }
  }
  else if ((3 < *(int *)(param_1 + 0x14) - 0xbU) ||
          (iVar1 = ieee80211_swfeat_is_supported(4,1), iVar1 == 0)) {
    bVar2 = 0x28;
  }
  if (*(ushort *)(param_1 + 0x4de) < 9) {
    bVar2 = 0x14;
  }
  return bVar2;
}

