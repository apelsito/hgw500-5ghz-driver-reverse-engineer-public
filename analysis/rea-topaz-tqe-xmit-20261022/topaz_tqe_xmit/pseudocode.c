/* REA/Ghidra decompiler output. Derived representation.
 * Evidence: evidence/rea-topaz-tqe-xmit-20261022/rea.json
 * Subject SHA256: 0aede6d339602939519570f1fc1a796d00af23b52ed334ccff0b16be7b757861
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint topaz_tqe_xmit(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while ((_DAT_ram_e1034038 & 1) != 0) {
    uVar1 = uVar1 + 1;
    if ((0xffff < uVar1) && ((uVar1 & 0xffff) == 0)) {
      (*(code *)&printk)("stuck in topaz_tqe_wait()\n");
    }
  }
  _DAT_ram_e1034020 = *param_1;
  _DAT_ram_e1034024 = param_1[1];
  _DAT_ram_e1034028 = param_1[2];
  _DAT_ram_e103402c = param_1[3];
  _DAT_ram_e1034030 = param_1[4];
  _DAT_ram_e1034034 = param_1[5];
  sync(0);
  _DAT_ram_e1034038 = 1;
  sync(0);
  uVar1 = 0;
  while ((_DAT_ram_e1034038 & 1) != 0) {
    uVar1 = uVar1 + 1;
    if ((0xffff < uVar1) && ((uVar1 & 0xffff) == 0)) {
      (*(code *)&printk)("stuck in topaz_tqe_wait()\n");
    }
  }
  return _DAT_ram_e1034038 >> 0x1d & 2;
}

