/* REA/Ghidra decompiler output. Derived representation.
 * Evidence: evidence/rea-qdrv-wlan-init-20261022/rea.json
 * Subject SHA256: 9b90c3d18497d3b9ab4ad11ebc8140d2cb80b1fbe4254682a771c930cdbf60b7
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 qdrv_wlan_init(undefined4 *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  undefined1 uVar4;
  ushort uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  undefined2 uVar14;
  byte *pbVar15;
  uint local_74;
  code *local_70;
  int aiStack_6c [4];
  undefined1 auStack_5c [2];
  undefined2 local_5a;
  
  iVar6 = (*(code *)&qtn_platform_dma_device)();
  if (iVar6 == 0) {
    if (1 < _g_dbg_log_level) {
      (*(code *)&printk)("%s: ERROR - %s: OpenMitraStar DMA device unavailable\n","qdrv_wlan_init");
      return 0xffffffed;
    }
    return 0xffffffed;
  }
  if ((((_g_dbg_log_module & 1) != 0) && (9 < _g_dbg_log_level)) && ((_g_dbg_log_func & 1) != 0)) {
    (*(code *)&printk)("%s: -->Enter\n","qdrv_wlan_init");
  }
  uVar7 = get_order(0x7758);
  iVar8 = (*(code *)&kmalloc_order)(0x7758,0xcc0,uVar7);
  if (iVar8 == 0) {
    if (1 < _g_dbg_log_level) {
      (*(code *)&printk)("%s: ERROR - Failed to allocate wlan structure\n","qdrv_wlan_init");
    }
    if ((_g_dbg_log_module & 1) == 0) {
      return 0xfffffff4;
    }
    if (_g_dbg_log_level < 10) {
      return 0xfffffff4;
    }
    if ((_g_dbg_log_func & 1) == 0) {
      return 0xfffffff4;
    }
    pcVar9 = "%s: <--Exit\n";
LAB_ram_00033250:
    (*(code *)&printk)(pcVar9,"qdrv_wlan_init");
    return 0xfffffff4;
  }
  if ((((_g_dbg_log_module & 1) != 0) && (5 < _g_dbg_log_level)) && ((_g_dbg_log_func & 0x200) != 0)
     ) {
    (*(code *)&printk)("%s: qw 0x%08x ic 0x%08x\n","qdrv_wlan_init");
  }
  (*(code *)&memset)(iVar8,0,0x7758);
  param_1[0x85] = iVar8;
  *(uint *)(iVar8 + 0x5a68) = *(uint *)(iVar8 + 0x5a68) | 0x28;
  (*(code *)&reg_congest_queue_stats)(qdrv_update_cgq_stats,iVar8);
  *(undefined4 **)(iVar8 + 0x5a70) = param_1;
  *(undefined4 *)(iVar8 + 0x5874) = *param_1;
  *(undefined2 *)(iVar8 + 0x5a6c) = 0;
  bVar3 = (byte)(param_3 >> 8) & 0xf;
  *(byte *)(iVar8 + 0x5a6e) = bVar3;
  *(byte *)(iVar8 + 0x5a6f) = (byte)(param_3 >> 0xc) & 0xf;
  *(int *)(iVar8 + 0x5b8c) = param_1[0x88] + 0x94;
  *(byte *)(_soc_shared_params + 6) = bVar3;
  iVar10 = (*(code *)&strcmp)("topaz_dbdc_config","qtm710_rgmii_config");
  if (((iVar10 == 0) ||
      (iVar10 = (*(code *)&strcmp)("topaz_dbdc_config","topaz_rgmii_config"), iVar10 == 0)) ||
     (iVar10 = (*(code *)&strcmp)("topaz_dbdc_config","topaz_vzn_config"), iVar10 == 0)) {
    uVar5 = 1;
  }
  else {
    iVar10 = (*(code *)&strcmp)("topaz_dbdc_config","topaz_pcie_config");
    uVar5 = (ushort)(iVar10 == 0);
  }
  *(ushort *)(iVar8 + 0x7712) = uVar5;
  *(undefined2 *)(iVar8 + 0x7714) = 0;
  *(undefined1 *)(iVar8 + 0x7716) = 0;
  iVar10 = (*(code *)&dev_get_by_name)(&init_net,&DAT_ram_0006fd24);
  *(int *)(iVar8 + 0x6a10) = iVar10;
  if ((iVar10 == 0) && (1 < _g_dbg_log_level)) {
    (*(code *)&printk)("%s: ERROR - Could not get bridge device\n","qdrv_wlan_init");
  }
  iVar10 = 0;
  do {
    iVar11 = iVar8 + iVar10 * 0x3c;
    *(undefined4 *)(iVar11 + 0x5888) = 0xffffffe0;
    iVar12 = iVar8 + iVar10 * 0x3c + 0x588c;
    *(int *)iVar12 = iVar12;
    *(int *)(iVar11 + 0x5890) = iVar12;
    *(code **)(iVar11 + 0x5894) = qdrv_wlan_beacon_work;
    *(int *)(iVar11 + 0x5898) = iVar8;
    *(char *)(iVar11 + 0x58bc) = (char)iVar10;
    iVar10 = iVar10 + 1;
    *(undefined4 *)(iVar11 + 0x58c0) = 0;
  } while (iVar10 != 8);
  qdrv_br_create(iVar8 + 0x6a1c);
  *(undefined4 *)(iVar8 + 0x7638) = 6;
  *(undefined4 *)(iVar8 + 0x763c) = 0xc;
  *(undefined4 *)(iVar8 + 0x7630) = 0;
  *(undefined4 *)(iVar8 + 0x7634) = 0;
  *(undefined4 *)(iVar8 + 0x7640) = 5;
  *(undefined1 *)(iVar8 + 0x7644) = 0xff;
  iVar10 = qdrv_sch_shared_data_init(0x400,0x7f);
  if (iVar10 == 0) {
    iVar10 = (*(code *)&panic)("%s: could not allocate tx_sch shared data\n","qdrv_wlan_tx_sch_init"
                              );
  }
  *(int *)(iVar8 + 0x770c) = iVar10;
  iVar10 = _jiffies;
  *(undefined1 *)(iVar8 + 0x7645) = 0xff;
  *(int *)(iVar8 + 0x76dc) = iVar10;
  *(undefined1 *)(iVar8 + 0x7646) = 0xff;
  aiStack_6c[1] = 0;
  local_70 = qdrv_csa_irqhandler;
  aiStack_6c[0] = iVar8;
  iVar10 = qdrv_mac_set_handler(*(undefined4 *)(iVar8 + 0x5a70),10,&local_70);
  if (iVar10 == 0) {
    set_bit(10,*(undefined4 *)(*(int *)(iVar8 + 0x5a70) + 0x134));
  }
  else if (1 < _g_dbg_log_level) {
    (*(code *)&printk)("%s: ERROR - Could not set csa irq handler\n","qdrv_init_csa_irqhandler");
  }
  *(int *)(iVar8 + 0x76bc) = iVar8 + 0x76bc;
  *(undefined4 *)(iVar8 + 0x76b8) = 0xffffffe0;
  *(int *)(iVar8 + 0x76c0) = iVar8 + 0x76bc;
  *(int *)(iVar8 + 0x76e4) = iVar8 + 0x76e4;
  *(undefined4 *)(iVar8 + 0x76e0) = 0xffffffe0;
  *(code **)(iVar8 + 0x76c4) = csa_work;
  *(int *)(iVar8 + 0x76e8) = iVar8 + 0x76e4;
  *(undefined4 *)(iVar8 + 0x76c8) = 0xffffffe0;
  *(int *)(iVar8 + 0x76cc) = iVar8 + 0x76cc;
  *(code **)(iVar8 + 0x76ec) = remain_channel_work;
  *(int *)(iVar8 + 0x76d0) = iVar8 + 0x76cc;
  *(code **)(iVar8 + 0x76d4) = channel_work;
  local_70 = qdrv_cca_irqhandler;
  aiStack_6c[1] = 0;
  aiStack_6c[0] = iVar8;
  iVar10 = qdrv_mac_set_handler(*(undefined4 *)(iVar8 + 0x5a70),0xb,&local_70);
  if (iVar10 == 0) {
    set_bit(0xb,*(undefined4 *)(*(int *)(iVar8 + 0x5a70) + 0x134));
  }
  else if (1 < _g_dbg_log_level) {
    (*(code *)&printk)("%s: ERROR - Could not set cca irq handler\n","qdrv_init_cca_irqhandler");
  }
  *(undefined4 *)(iVar8 + 0x7684) = 0xffffffe0;
  *(int *)(iVar8 + 0x7688) = iVar8 + 0x7688;
  *(int *)(iVar8 + 0x768c) = iVar8 + 0x7688;
  *(code **)(iVar8 + 0x7690) = cca_work;
  local_70 = qdrv_meas_irqhandler;
  aiStack_6c[1] = 0;
  aiStack_6c[0] = iVar8;
  iVar10 = qdrv_mac_set_handler(*(undefined4 *)(iVar8 + 0x5a70),8,&local_70);
  if (iVar10 == 0) {
    set_bit(8,*(undefined4 *)(*(int *)(iVar8 + 0x5a70) + 0x134));
  }
  else if (1 < _g_dbg_log_level) {
    (*(code *)&printk)("%s: ERROR - Could not set measurement irq handler\n",
                       "qdrv_init_meas_irqhandler");
  }
  *(undefined4 *)(iVar8 + 0x7694) = 0xffffffe0;
  *(int *)(iVar8 + 0x7698) = iVar8 + 0x7698;
  *(int *)(iVar8 + 0x769c) = iVar8 + 0x7698;
  *(code **)(iVar8 + 0x76a0) = meas_work;
  local_70 = qdrv_scan_irqhandler;
  aiStack_6c[1] = 0;
  aiStack_6c[0] = iVar8;
  iVar10 = qdrv_mac_set_handler(*(undefined4 *)(iVar8 + 0x5a70),0xc,&local_70);
  if (iVar10 == 0) {
    set_bit(0xc,*(undefined4 *)(*(int *)(iVar8 + 0x5a70) + 0x134));
  }
  else if (1 < _g_dbg_log_level) {
    (*(code *)&printk)("%s: ERROR - BG_SCAN: could not set irq handler\n",
                       "qdrv_init_scan_irqhandler");
  }
  *(undefined4 *)(iVar8 + 0x76a4) = 0xffffffe0;
  *(int *)(iVar8 + 0x76a8) = iVar8 + 0x76a8;
  *(int *)(iVar8 + 0x76ac) = iVar8 + 0x76a8;
  *(code **)(iVar8 + 0x76b0) = scan_work;
  iVar6 = (*(code *)&dma_alloc_attrs)(iVar6,0xf8e8,iVar8 + 0x76f4,0xdc1,0);
  *(int *)(iVar8 + 0x76f0) = iVar6;
  if (iVar6 == 0) {
    if (_g_dbg_log_level < 2) {
      return 0xfffffff4;
    }
    pcVar9 = "%s: ERROR - Failed to allocate per node stats pool";
    goto LAB_ram_00033250;
  }
  *(undefined4 *)(iVar8 + 0x76f8) = 0;
  *(int *)(iVar8 + 0x76fc) = iVar8 + 0x76f8;
  iVar10 = 0;
  do {
    iVar11 = iVar10 * 0x21c;
    iVar10 = iVar10 + 1;
    *(undefined4 *)(iVar6 + iVar11 + 0x214) = 0;
    piVar13 = *(int **)(iVar8 + 0x76fc);
    *(int **)(*(int *)(iVar8 + 0x76f0) + iVar11 + 0x218) = piVar13;
    *piVar13 = *(int *)(iVar8 + 0x76f0) + iVar11;
    iVar6 = *(int *)(iVar8 + 0x76f0);
    *(int *)(iVar8 + 0x76fc) = iVar6 + iVar11 + 0x214;
  } while (iVar10 != 0x76);
  iVar6 = qdrv_tx_init(param_1,param_2,param_4);
  if (iVar6 < 0) {
    if (_g_dbg_log_level < 2) goto LAB_ram_000337d0;
    pcVar9 = "%s: ERROR - Failed to initialize TX\n";
  }
  else {
    iVar6 = qdrv_rx_init(iVar8,param_2);
    if (iVar6 < 0) {
      if (_g_dbg_log_level < 2) goto LAB_ram_000337d0;
      pcVar9 = "%s: ERROR - Failed to initialize RX\n";
    }
    else {
      iVar6 = qdrv_scan_init(iVar8,param_2);
      if (iVar6 < 0) {
        if (_g_dbg_log_level < 2) goto LAB_ram_000337d0;
        pcVar9 = "%s: ERROR - Failed to initialize Scan\n";
      }
      else {
        iVar6 = qdrv_hostlink_init(iVar8,param_2);
        if (iVar6 < 0) {
          if (_g_dbg_log_level < 2) goto LAB_ram_000337d0;
          pcVar9 = "%s: ERROR - Failed to initialize hostlink\n";
        }
        else {
          iVar6 = qdrv_txbf_init(iVar8);
          if (iVar6 < 0) {
            if (_g_dbg_log_level < 2) goto LAB_ram_000337d0;
            pcVar9 = "%s: ERROR - Failed to initialize beamforming\n";
          }
          else {
            iVar6 = qdrv_rx_start(param_1);
            if (iVar6 < 0) {
              if (_g_dbg_log_level < 2) goto LAB_ram_000337d0;
              pcVar9 = "%s: ERROR - Failed to start RX\n";
            }
            else {
              iVar6 = qdrv_tx_start(param_1);
              if (iVar6 < 0) {
                if (_g_dbg_log_level < 2) goto LAB_ram_000337d0;
                pcVar9 = "%s: ERROR - Failed to start TX\n";
              }
              else {
                iVar6 = qdrv_scan_start(param_1);
                if (iVar6 < 0) {
                  if (_g_dbg_log_level < 2) goto LAB_ram_000337d0;
                  pcVar9 = "%s: ERROR - Failed to start Scan\n";
                }
                else {
                  iVar6 = qdrv_hostlink_start(param_1);
                  if (iVar6 < 0) {
                    if (_g_dbg_log_level < 2) goto LAB_ram_000337d0;
                    pcVar9 = "%s: ERROR - Failed to start hostlink\n";
                  }
                  else {
                    iVar6 = set_rates(iVar8,1);
                    if (iVar6 == 0) {
                      iVar6 = set_rates(iVar8,2);
                      if (iVar6 == 0) {
                        iVar6 = set_rates(iVar8,3);
                        if (iVar6 == 0) {
                          iVar6 = set_rates(iVar8,8);
                          if ((iVar6 == 0) && (iVar6 = set_rates(iVar8,9), iVar6 == 0)) {
                            iVar6 = set_rates(iVar8,7);
                            if ((iVar6 == 0) && (iVar6 = set_rates(iVar8,10), iVar6 == 0)) {
                              iVar6 = set_rates(iVar8,0xb);
                              if (iVar6 == 0) {
                                iVar6 = set_rates(iVar8,0xc);
                                if (iVar6 == 0) {
                                  iVar6 = set_rates(iVar8,0xd);
                                  if (iVar6 == 0) {
                                    cVar1 = *(char *)(iVar8 + 0x5a6e);
                                    if (cVar1 == '\0') {
                                      uVar7 = 0xd;
                                    }
                                    else if (cVar1 == '\x01') {
                                      uVar7 = 0x1e;
                                    }
                                    else {
                                      uVar7 = 0x2b;
                                    }
                                    qdrv_wlan_80211_config_channel(iVar8,uVar7);
                                    iVar6 = _soc_shared_params;
                                    *(undefined4 *)(iVar8 + 0x74) = 0x25040059;
                                    uVar14 = 0;
                                    if (iVar6 != 0) {
                                      uVar14 = (undefined2)*(undefined4 *)(iVar6 + 0x38);
                                    }
                                    *(undefined2 *)(iVar8 + 0x78) = uVar14;
                                    *(undefined2 *)(iVar8 + 0x7a) = 0;
                                    *(undefined4 *)(iVar8 + 0x7c) = 0x57fca2f8;
                                    *(code **)(iVar8 + 0x52c8) = qdrv_wlan_80211_config_channel;
                                    *(char *)(iVar8 + 0xa00) = cVar1;
                                    *(code **)(iVar8 + 0x5134) = qdrv_wlan_80211_newassoc;
                                    *(code **)(iVar8 + 0x5138) = qdrv_wlan_80211_disassoc;
                                    *(code **)(iVar8 + 0x513c) = qdrv_wlan_80211_node_update;
                                    *(code **)(iVar8 + 0x5130) = qdrv_wlan_80211_updateslot;
                                    *(code **)(iVar8 + 0x5128) = qdrv_wlan_80211_reset;
                                    *(code **)(iVar8 + 0x5124) = qdrv_wlan_80211_start;
                                    *(code **)(iVar8 + 0x512c) = qdrv_wlan_80211_resetmaxqueue;
                                    *(code **)(iVar8 + 0x5120) = qdrv_wlan_80211_send;
                                    *(code **)(iVar8 + 0x5200) = qdrv_wlan_80211_stats;
                                    *(code **)(iVar8 + 0x51d8) = qdrv_wlan_80211_join_bss;
                                    *(code **)(iVar8 + 0x51dc) = qdrv_wlan_80211_beacon_update;
                                    *(code **)(iVar8 + 0x51e0) = qdrv_wlan_80211_beacon_stop;
                                    *(code **)(iVar8 + 0x51ec) = qdrv_wlan_set_l2_ext_filter;
                                    *(code **)(iVar8 + 0x51f0) = qdrv_wlan_set_l2_ext_filter_port;
                                    *(code **)(iVar8 + 0x51f4) = qdrv_wlan_get_l2_ext_filter_port;
                                    *(code **)(iVar8 + 0x51f8) = qdrv_send_to_l2_ext_filter;
                                    *(code **)(iVar8 + 0x51fc) = qdrv_mac_reserved;
                                    *(code **)(iVar8 + 0x51b8) = qdrv_wlan_80211_setparam;
                                    *(code **)(iVar8 + 0x51bc) = qdrv_wlan_80211_getparam;
                                    *(code **)(iVar8 + 0x51c0) = qdrv_wlan_register_node;
                                    *(code **)(iVar8 + 0x51c4) = qdrv_wlan_unregister_node;
                                    *(code **)(iVar8 + 0x51c8) = qdrv_wlan_80211_get_phy_stats;
                                    *(code **)(iVar8 + 0x51d0) = qdrv_wlan_80211_process_addba;
                                    *(code **)(iVar8 + 0x51d4) = qdrv_wlan_80211_process_delba;
                                    *(code **)(iVar8 + 0x51e4) = qdrv_wlan_80211_setkey;
                                    *(code **)(iVar8 + 0x51e8) = qdrv_wlan_80211_delkey;
                                    *(code **)(iVar8 + 0x5204) = qdrv_wlan_80211_smps;
                                    *(code **)(iVar8 + 0x5294) = qdrv_wlan_auth_state_change;
                                    *(undefined2 *)(iVar8 + 0x4e1c) = 0x101;
                                    *(code **)(iVar8 + 0x5298) = qdrv_wlan_new_assoc;
                                    *(code **)(iVar8 + 0x5250) = qdrv_wlan_update_wmm_params;
                                    *(code **)(iVar8 + 0x5254) = qdrv_wlan_update_chan_power_table;
                                    *(code **)(iVar8 + 0x529c) = qdrv_wlan_80211_power_save;
                                    *(code **)(iVar8 + 0x52a0) = qdrv_remain_on_channel;
                                    *(code **)(iVar8 + 0x5258) = qdrv_wlan_80211_tdls_set_params;
                                    *(code **)(iVar8 + 0x525c) = qdrv_wlan_80211_tdls_get_params;
                                    *(undefined1 *)(iVar8 + 0x9f8) = 2;
                                    *(undefined1 *)(iVar8 + 0x9fb) = 1;
                                    *(undefined4 *)(iVar8 + 0x57b8) = 0x4b;
                                    *(undefined4 *)(iVar8 + 0x1c) = 1;
                                    *(undefined4 *)(iVar8 + 0x4f30) = 0;
                                    *(undefined1 *)(iVar8 + 0x9fe) = 0;
                                    *(undefined4 *)(iVar8 + 0x90) = 0xe581ed10;
                                    *(undefined4 *)(iVar8 + 0x50ec) = 200;
                                    *(undefined2 *)(iVar8 + 0x50e8) = 0x400;
                                    *(undefined1 *)(iVar8 + 0x5102) = 0;
                                    *(undefined4 *)(iVar8 + 0x94) = 2;
                                    *(undefined2 *)(iVar8 + 0x9e8) = 0xffff;
                                    *(undefined1 *)(iVar8 + 0x5105) = 0;
                                    *(undefined1 *)(iVar8 + 0x5106) = 0;
                                    qdrv_wlan_80211_set_11ac_mode(iVar8,1);
                                    iVar6 = _soc_shared_params;
                                    *(ushort *)(iVar8 + 0x4e8) = *(ushort *)(iVar8 + 0x4e8) | 0x9e2;
                                    *(undefined2 *)(iVar8 + 0x4ee) = 0xeff;
                                    *(undefined1 *)(iVar8 + 0x4eb) = 2;
                                    *(undefined1 *)(iVar8 + 0x4ec) = 3;
                                    iVar10 = (*(code *)&board_slow_ethernet)();
                                    uVar2 = _g_dbg_log_module;
                                    if (iVar10 == 0) {
                                      *(undefined2 *)(iVar8 + 0x4f0) = 3;
                                    }
                                    else {
                                      *(undefined2 *)(iVar8 + 0x4f0) = 0;
                                      if ((((uVar2 & 1) != 0) && (9 < _g_dbg_log_level)) &&
                                         ((_g_dbg_log_func & 1) != 0)) {
                                        (*(code *)&printk)(
                                                  "%s: Slow Ethernet WAR: RXAMPDU %d bytes\n",
                                                  "qdrv_wlan_80211_cfg_ht",0);
                                      }
                                    }
                                    if (*(ushort *)(iVar6 + 4) < 0x40) {
                                      uVar4 = 6;
                                    }
                                    else {
                                      uVar4 = 5;
                                    }
                                    *(undefined1 *)(iVar8 + 0x4ed) = uVar4;
                                    *(undefined2 *)(iVar8 + 0x4fc) = 0;
                                    *(undefined1 *)(iVar8 + 0x501) = 0x18;
                                    *(undefined1 *)(iVar8 + 0x502) = 0xe6;
                                    pbVar15 = (byte *)(iVar8 + 0x503);
                                    *pbVar15 = *pbVar15 | 7;
                                    iVar6 = (*(code *)&ieee80211_swfeat_is_supported)(5,0);
                                    if (iVar6 == 0) {
                                      iVar6 = (*(code *)&ieee80211_swfeat_is_supported)(7,0);
                                      if (iVar6 == 0) {
                                        *(undefined4 *)(iVar8 + 0x98) = 4;
                                        *pbVar15 = *pbVar15 | 0xe0;
                                        bVar3 = *(byte *)(iVar8 + 0x504) | 0x19;
                                      }
                                      else {
                                        *(undefined4 *)(iVar8 + 0x98) = 3;
                                        *pbVar15 = *pbVar15 & 0x1f | 0x40;
                                        bVar3 = *(byte *)(iVar8 + 0x504) & 0xe7 | 0x11;
                                      }
                                    }
                                    else {
                                      *(undefined4 *)(iVar8 + 0x98) = 2;
                                      *pbVar15 = *pbVar15 & 0x9f | 0xa0;
                                      bVar3 = *(byte *)(iVar8 + 0x504) & 0xe6 | 8;
                                    }
                                    *(byte *)(iVar8 + 0x504) = bVar3;
                                    qdrv_wlan_80211_set_mcsset(iVar8);
                                    qdrv_wlan_80211_set_mcsparams(iVar8);
                                    *(undefined1 *)(iVar8 + 0x516) = 0;
                                    *(undefined1 *)(iVar8 + 0x519) = 0;
                                    *(undefined1 *)(iVar8 + 0x51a) = 0;
                                    iVar6 = qdrv_wlan_80211_cfg_vht
                                                      (iVar8 + 0x54f,iVar8 + 0x572,iVar8 + 0x9c,0,
                                                       *(undefined4 *)(iVar8 + 0x1c),
                                                       *(undefined1 *)(iVar8 + 0x5102));
                                    if ((iVar6 == 0) &&
                                       (iVar6 = qdrv_wlan_80211_cfg_vht
                                                          (iVar8 + 0x524,iVar8 + 0x547,iVar8 + 0xa0,
                                                           1,*(undefined4 *)(iVar8 + 0x1c),0),
                                       iVar6 == 0)) {
                                      (*(code *)&memcpy)(iVar8 + 0x38,(int)param_1 + 0x45,6);
                                      (*(code *)&ieee80211_ifattach)(iVar8);
                                      *(code **)(iVar8 + 0x5140) = qdrv_node_alloc;
                                      *(code **)(iVar8 + 0x5148) = qdrv_node_free;
                                      *(code **)(iVar8 + 0x5164) = qtn_scan_start;
                                      *(code **)(iVar8 + 0x5168) = qtn_scan_end;
                                      *(code **)(iVar8 + 0x516c) = qdrv_check_channel;
                                      *(code **)(iVar8 + 0x5170) = qdrv_set_channel;
                                      *(code **)(iVar8 + 0x5178) = hal_get_tsf;
                                      *(code **)(iVar8 + 0x5194) = qdrv_set_channel_deferred;
                                      *(code **)(iVar8 + 0x5198) = qtn_async_cca_read;
                                      *(code **)(iVar8 + 0x519c) = qtn_do_measurement;
                                      *(undefined1 **)(iVar8 + 0x51a0) =
                                           &ieee80211_action_finish_measurement;
                                      *(code **)(iVar8 + 0x51a4) = qdrv_wlan_send_csa_frame;
                                      *(undefined1 **)(iVar8 + 4) = &findchannel;
                                      *(undefined1 *)(iVar8 + 0x50b4) = 0x50;
                                      *(code **)(iVar8 + 0x51b0) = qtn_set_coverageclass;
                                      *(code **)(iVar8 + 0x51b4) = qtn_mhz2ieee;
                                      *(code **)(iVar8 + 0x510c) = qtn_vap_create;
                                      *(code **)(iVar8 + 0x5110) = qtn_vap_delete;
                                      *(code **)(iVar8 + 0x5114) = qdrv_get_vap_idx;
                                      *(code **)(iVar8 + 0x520c) = qdrv_radar_detected;
                                      *(code **)(iVar8 + 0x5210) = qdrv_radar_select_newchan;
                                      *(code **)(iVar8 + 0x5214) = qdrv_dfs_action_scan_done;
                                      *(code **)(iVar8 + 0x5218) = qdrv_dfs_is_eu_region;
                                      *(code **)(iVar8 + 0x52a4) = qdrv_wlan_80211_mark_dfs;
                                      *(code **)(iVar8 + 0x52a8) =
                                           qdrv_wlan_80211_mark_weather_radar;
                                      *(code **)(iVar8 + 0x528c) = qdrv_radar_test_mode_enabled;
                                      *(code **)(iVar8 + 0x52ac) = qdrv_use_rts_cts;
                                      *(code **)(iVar8 + 0x52b4) = qdrv_sta_set_xmit;
                                      *(code **)(iVar8 + 0x52b8) = qdrv_set_radar;
                                      *(code **)(iVar8 + 0x52bc) = qdrv_sta_dfs_enable;
                                      *(code **)(iVar8 + 0x52c0) = qdrv_radar_detections_num;
                                      *(code **)(iVar8 + 0x52c4) = qdrv_cac_instant_completed;
                                      *(undefined2 *)(iVar8 + 0x4e28) = 0x66;
                                      iVar6 = 0;
                                      do {
                                        iVar10 = iVar6 * 6;
                                        iVar6 = iVar6 + 1;
                                        iVar10 = iVar8 + iVar10;
                                        *(undefined2 *)(iVar10 + 0x4e34) = 0x66;
                                        *(undefined2 *)(iVar10 + 0x4e36) = 0;
                                        *(undefined2 *)(iVar10 + 0x4e38) = 0;
                                      } while (iVar6 != 0x20);
                                      *(undefined1 *)(iVar8 + 0x9fc) = 1;
                                      *(code **)(iVar8 + 0x517c) = qdrv_bmps_set_frame;
                                      *(code **)(iVar8 + 0x5180) = qdrv_bmps_release_frame;
                                      *(code **)(iVar8 + 0x5184) = qdrv_scs_update_scan_stats;
                                      *(code **)(iVar8 + 0x5188) = qdrv_sample_channel;
                                      *(code **)(iVar8 + 0x521c) =
                                           qdrv_mark_channel_availability_status;
                                      *(code **)(iVar8 + 0x5220) =
                                           qdrv_set_chan_availability_status_by_chan_num;
                                      *(code **)(iVar8 + 0x5224) =
                                           qdrv_get_chan_availability_status_by_chan_num;
                                      *(code **)(iVar8 + 0x5228) = qdrv_mark_channel_dfs_cac_status;
                                      *(code **)(iVar8 + 0x5230) = qdrv_ap_next_cac;
                                      *(code **)(iVar8 + 0x522c) =
                                           qdrv_dump_ic_chan_availability_status;
                                      *(code **)(iVar8 + 0x5234) = qdrv_dfs_chans_available_for_cac;
                                      *(code **)(iVar8 + 0x5238) = qdrv_get_init_cac_duration;
                                      *(code **)(iVar8 + 0x523c) = qdrv_set_init_cac_duration;
                                      *(code **)(iVar8 + 0x5240) = qdrv_start_icac_procedure;
                                      *(code **)(iVar8 + 0x5244) = qdrv_stop_icac_procedure;
                                      *(code **)(iVar8 + 0x5248) = qdrv_chan_compare_equality;
                                      *(undefined4 *)(iVar8 + 0x57c) = 10;
                                      *(undefined4 *)(iVar8 + 0x584) = 0x10;
                                      *(undefined4 *)(iVar8 + 0x588) = 200;
                                      *(undefined4 *)(iVar8 + 0x590) = 0x3c;
                                      *(undefined4 *)(iVar8 + 0x5cc) = 0x1e;
                                      *(undefined4 *)(iVar8 + 0x5d0) = 0x14;
                                      *(undefined4 *)(iVar8 + 0x580) = 5;
                                      *(undefined4 *)(iVar8 + 0x58c) = 5;
                                      *(undefined4 *)(iVar8 + 0x5c4) = 0x28;
                                      *(undefined4 *)(iVar8 + 0x5c8) = 0x32;
                                      *(undefined4 *)(iVar8 + 0x5d8) = 300;
                                      *(undefined4 *)(iVar8 + 0x5d4) = 0;
                                      *(undefined4 *)(iVar8 + 0x5dc) = 2;
                                      *(undefined4 *)(iVar8 + 0x5e0) = 0x194b5a4b;
                                      *(undefined2 *)(iVar8 + 0x5e4) = 0x190f;
                                      *(undefined1 *)(iVar8 + 0x5e6) = 5;
                                      *(undefined4 *)(iVar8 + 0x60c) = 0x28;
                                      *(undefined4 *)(iVar8 + 0x610) = 0x42;
                                      *(undefined4 *)(iVar8 + 0x618) = 0x28;
                                      *(undefined4 *)(iVar8 + 0x598) = 0x28;
                                      *(undefined4 *)(iVar8 + 0x620) = 100;
                                      *(undefined4 *)(iVar8 + 0x59c) = 0x14;
                                      *(undefined4 *)(iVar8 + 0x5a0) = 0x168;
                                      *(undefined4 *)(iVar8 + 0x5a4) = 5;
                                      *(undefined4 *)(iVar8 + 0x604) = 0xffff0000;
                                      *(undefined4 *)(iVar8 + 0x614) = 5000;
                                      *(undefined4 *)(iVar8 + 0x61c) = 0;
                                      *(undefined4 *)(iVar8 + 0x5a8) = 0;
                                      *(undefined2 *)(iVar8 + 0x5ac) = 0;
                                      *(undefined1 *)(iVar8 + 0x5ae) = 0;
                                      *(undefined2 *)(iVar8 + 0x646) = 0x32;
                                      *(undefined4 *)(iVar8 + 0x634) = 0x420042;
                                      *(undefined4 *)(iVar8 + 0x638) = 0x1e0042;
                                      *(undefined4 *)(iVar8 + 0x63c) = 0x3c0032;
                                      *(undefined4 *)(iVar8 + 0x640) = 0x320032;
                                      *(undefined2 *)(iVar8 + 0x724) = 0;
                                      *(undefined2 *)(iVar8 + 0x720) = 0;
                                      *(undefined1 *)(iVar8 + 0x722) = 0;
                                      (*(code *)&strncpy)(iVar8 + 0x728,&DAT_ram_00070134,4);
                                      *(undefined4 *)(iVar8 + 0x73c) = 0x780;
                                      *(undefined2 *)(iVar8 + 0x726) = 2;
                                      *(undefined4 *)(iVar8 + 0x72c) = 0x170001;
                                      *(undefined4 *)(iVar8 + 0x730) = 0x2d00028;
                                      *(undefined4 *)(iVar8 + 0x734) = 0x1400f0;
                                      *(undefined4 *)(iVar8 + 0x738) = 0x2d00;
                                      *(undefined4 *)(iVar8 + 0x740) = 0x1e005a;
                                      *(undefined4 *)(iVar8 + 0x744) = 0x14000a;
                                      *(undefined **)(iVar8 + 0x748) = &DAT_ram_0005000a;
                                      *(undefined4 *)(iVar8 + 0x74c) = 0x640002;
                                      *(undefined4 *)(iVar8 + 0x7e0) = 0;
                                      *(code **)(iVar8 + 0x51a8) = qdrv_set_ocac;
                                      *(code **)(iVar8 + 0x5260) = qdrv_muc_stats_rxtx_phy_rate;
                                      *(code **)(iVar8 + 0x5264) = qdrv_muc_stats_rssi;
                                      *(code **)(iVar8 + 0x5268) = qdrv_muc_stats_smoothed_rssi;
                                      *(code **)(iVar8 + 0x526c) = qdrv_muc_stats_snr;
                                      *(code **)(iVar8 + 0x5270) = qdrv_muc_stats_hw_noise;
                                      *(code **)(iVar8 + 0x5274) = qdrv_muc_stats_max_queue;
                                      *(code **)(iVar8 + 0x527c) = qdrv_muc_stats_mcs_to_phyrate;
                                      *(code **)(iVar8 + 0x5278) = qdrv_muc_stats_tx_failed;
                                      *(code **)(iVar8 + 0x5280) = qdrv_channel_switch_record;
                                      *(code **)(iVar8 + 0x5284) = qdrv_channel_switch_reason_record
                                      ;
                                      *(code **)(iVar8 + 0x5288) = dfs_reentry_chan_switch_notify;
                                      *(code **)(iVar8 + 0x52cc) = qdrv_wlan_set_11g_erp;
                                      *(undefined2 *)(iVar8 + 0x57f8) = 1;
                                      *(undefined2 *)(iVar8 + 0x5808) = 0x19;
                                      *(undefined4 *)(iVar8 + 0x57fc) = 0xa0014;
                                      *(undefined4 *)(iVar8 + 0x5800) = 0xc800c8;
                                      *(undefined **)(iVar8 + 0x5804) = &DAT_ram_00050014;
                                      *(code **)(iVar8 + 0x580c) = qdrv_wlan_coex_stats_update;
                                      *(undefined4 *)(iVar8 + 0x582c) = 0xffffffff;
                                      *(undefined2 *)(iVar8 + 0x5830) = 0xf03;
                                      *(code **)(iVar8 + 0x518c) = qdrv_bgscan_start;
                                      *(code **)(iVar8 + 0x5190) = qdrv_bgscan_channel;
                                      *(undefined1 *)(iVar8 + 0x4e1) = 0;
                                      (*(code *)&memset)(iVar8 + 0x3e08,0,0x248);
                                      (*(code *)&memset)(iVar8 + 0x4050,0,0x800);
                                      *(undefined1 **)(iVar8 + 0x52b0) =
                                           &ieee80211_send_notify_chan_width_action;
                                      *(undefined1 **)(iVar8 + 0x57dc) =
                                           &ieee80211_send_vht_grp_id_mgmt_action;
                                      (*(code *)&memcpy)(iVar8 + 0x531c,defaults_10,0x58);
                                      *(code **)(iVar8 + 0x55dc) = qdrv_get_local_tx_power;
                                      *(code **)(iVar8 + 0x55e0) = qdrv_get_local_link_margin;
                                      *(code **)(iVar8 + 0x560c) = qdrv_wlan_get_shared_vap_stats;
                                      *(code **)(iVar8 + 0x5610) = qdrv_wlan_reset_shared_vap_stats;
                                      *(code **)(iVar8 + 0x5614) = qdrv_wlan_get_shared_node_stats;
                                      *(code **)(iVar8 + 0x5618) = qdrv_wlan_reset_shared_node_stats
                                      ;
                                      *(code **)(iVar8 + 0x561c) = qdrv_wlan_get_dscp2ac_map;
                                      *(code **)(iVar8 + 0x5620) = qdrv_wlan_set_dscp2ac_map;
                                      *(code **)(iVar8 + 0x5628) = qdrv_sch_get_dscp2tid_map;
                                      *(code **)(iVar8 + 0x5624) = qdrv_sch_set_dscp2tid_map;
                                      *(undefined1 *)(iVar8 + 0x5060) = 0;
                                      *(undefined4 *)(iVar8 + 0x507c) = 0;
                                      *(undefined1 *)(iVar8 + 0x5080) = 0xff;
                                      *(undefined4 *)(iVar8 + 0x50f4) = 2;
                                      *(undefined4 *)(iVar8 + 0x50f8) = 2;
                                      *(code **)(iVar8 + 0x5640) =
                                           ieee80211_get_cca_adjusting_status;
                                      *(uint *)(iVar8 + 0x8c) = *(uint *)(iVar8 + 0x8c) | 0x2000;
                                      *(uint *)(iVar8 + 0x88) = *(uint *)(iVar8 + 0x88) | 0x10;
                                      *(undefined1 *)(iVar8 + 0x5794) = 0;
                                      *(undefined1 *)(iVar8 + 0x9ff) = 3;
                                      (*(code *)&memset)(&local_70,0,0x20);
                                      local_74 = 0;
                                      *(undefined4 *)(iVar8 + 0x5810) = 0;
                                      iVar6 = (*(code *)&bootcfg_get_var)
                                                        ("dm_txpower_factor",&local_70);
                                      if (((iVar6 != 0) &&
                                          (iVar6 = (*(code *)&sscanf)(iVar6,&DAT_ram_00062eac,
                                                                      &local_74), iVar6 == 1)) &&
                                         (local_74 < 9)) {
                                        *(uint *)(iVar8 + 0x5814) = local_74;
                                        *(uint *)(iVar8 + 0x5810) = *(uint *)(iVar8 + 0x5810) | 1;
                                      }
                                      iVar6 = (*(code *)&bootcfg_get_var)("dm_aci_factor",&local_70)
                                      ;
                                      if (((iVar6 != 0) &&
                                          (iVar6 = (*(code *)&sscanf)(iVar6,&DAT_ram_00062eac,
                                                                      &local_74), iVar6 == 1)) &&
                                         (local_74 + 4 < 5)) {
                                        *(uint *)(iVar8 + 0x5818) = local_74;
                                        *(uint *)(iVar8 + 0x5810) = *(uint *)(iVar8 + 0x5810) | 2;
                                      }
                                      iVar6 = (*(code *)&bootcfg_get_var)("dm_cci_factor",&local_70)
                                      ;
                                      if (((iVar6 != 0) &&
                                          (iVar6 = (*(code *)&sscanf)(iVar6,&DAT_ram_00062eac,
                                                                      &local_74), iVar6 == 1)) &&
                                         (local_74 + 4 < 5)) {
                                        *(uint *)(iVar8 + 0x581c) = local_74;
                                        *(uint *)(iVar8 + 0x5810) = *(uint *)(iVar8 + 0x5810) | 4;
                                      }
                                      iVar6 = (*(code *)&bootcfg_get_var)("dm_dfs_factor",&local_70)
                                      ;
                                      if (((iVar6 != 0) &&
                                          (iVar6 = (*(code *)&sscanf)(iVar6,&DAT_ram_00062eac,
                                                                      &local_74), iVar6 == 1)) &&
                                         (local_74 < 0x21)) {
                                        *(uint *)(iVar8 + 0x5820) = local_74;
                                        *(uint *)(iVar8 + 0x5810) = *(uint *)(iVar8 + 0x5810) | 8;
                                      }
                                      iVar6 = (*(code *)&bootcfg_get_var)
                                                        ("dm_beacon_factor",&local_70);
                                      if (((iVar6 != 0) &&
                                          (iVar6 = (*(code *)&sscanf)(iVar6,&DAT_ram_00062eac,
                                                                      &local_74), iVar6 == 1)) &&
                                         (local_74 + 4 < 5)) {
                                        *(uint *)(iVar8 + 0x5824) = local_74;
                                        *(uint *)(iVar8 + 0x5810) = *(uint *)(iVar8 + 0x5810) | 0x10
                                        ;
                                      }
                                      *(undefined1 *)(iVar8 + 0x5864) = 0;
                                      *(undefined4 *)(iVar8 + 0x586c) = 1000;
                                      *(undefined1 *)(iVar8 + 0x5872) = 0;
                                      *(int *)(iVar8 + 0x5bec) = iVar8 + 0x5bc0;
                                      *(undefined4 *)(iVar8 + 0x5bf0) = 8;
                                      *(code **)(iVar8 + 0x5834) = qdrv_muc_stats_tx_airtime;
                                      *(code **)(iVar8 + 0x5838) = qdrv_muc_stats_tx_accum_airtime;
                                      *(code **)(iVar8 + 0x583c) = qdrv_tx_airtime_control;
                                      *(code **)(iVar8 + 0x5840) = qdrv_muc_stats_rx_airtime;
                                      *(code **)(iVar8 + 0x5844) = qdrv_muc_stats_rx_accum_airtime;
                                      *(code **)(iVar8 + 0x5848) = qdrv_mu_grp_update;
                                      *(undefined4 *)(iVar8 + 0x5868) = 0;
                                      *(undefined2 *)(iVar8 + 0x5870) = 0;
                                      (*(code *)&memset)(auStack_5c,0,0x24);
                                      local_70 = (code *)0x35396573;
                                      (*(code *)&memset)(aiStack_6c,0,0x10);
                                      local_5a = 0x49;
                                      local_74 = 0;
                                      iVar6 = (*(code *)&i2c_get_adapter)(0);
                                      if (iVar6 == 0) {
                                        if (1 < _g_dbg_log_level) {
                                          (*(code *)&printk)(
                                                  "%s: ERROR - Failed to get temperature sensor I2C adapter\n"
                                                  ,"qdrv_init_tsensor");
                                        }
                                      }
                                      else {
                                        uVar7 = (*(code *)&i2c_new_client_device)(iVar6,&local_70);
                                        *(undefined4 *)(iVar8 + 0x7718) = uVar7;
                                        (*(code *)&i2c_put_adapter)(iVar6);
                                        if (*(uint *)(iVar8 + 0x7718) < 0xfffff001) {
                                          iVar6 = (*(code *)&qtn_tsensor_get_temperature)
                                                            (*(uint *)(iVar8 + 0x7718),&local_74);
                                          if (iVar6 < 0) {
                                            (*(code *)&i2c_unregister_device)
                                                      (*(undefined4 *)(iVar8 + 0x7718));
                                            *(undefined4 *)(iVar8 + 0x7718) = 0;
                                            (*(code *)&printk)(
                                                  "QDRV: no external temperature sensor found\n");
                                          }
                                        }
                                        else {
                                          if (1 < _g_dbg_log_level) {
                                            (*(code *)&printk)(
                                                  "%s: ERROR - Failed to instantiate temperature sensor device\n"
                                                  ,"qdrv_init_tsensor");
                                          }
                                          *(undefined4 *)(iVar8 + 0x7718) = 0;
                                        }
                                      }
                                      qdrv_txpow_cal_init(iVar8);
                                      qdrv_radar_init(param_1);
                                      qdrv_pktlogger_init(iVar8);
                                      iVar6 = (*(code *)&of_machine_is_compatible)
                                                        ("mitrastar,hgw-500bna-qcv2");
                                      if (iVar6 == 0) {
                                        (*(code *)&init_timer_key)
                                                  (iVar8 + 0x7648,qdrv_wlan_enable_hr,0,0,0);
                                        (*(code *)&mod_timer)(iVar8 + 0x7648,_jiffies + 300);
                                      }
                                      else {
                                        (*(code *)&printk)(&DAT_ram_00070270);
                                      }
                                      *(code **)(iVar8 + 0x7700) = qdrv_pm_notify;
                                      (*(code *)&pm_qos_add_notifier)(4);
                                      (*(code *)&arc_set_sram_safe_area)
                                                (&DAT_ram_8803e7c0,0x8803f7c0);
                                      (*(code *)&arc_set_troubleshoot_start_hook)
                                                (qdrv_troubleshoot_start_cb,iVar8);
                                      *(int *)(iVar8 + 0x7754) = _soc_shared_params;
                                      if ((_g_dbg_log_module & 1) == 0) {
                                        return 0;
                                      }
                                      if (_g_dbg_log_level < 10) {
                                        return 0;
                                      }
                                      if ((_g_dbg_log_func & 1) != 0) {
                                        (*(code *)&printk)("%s: <--Exit\n","qdrv_wlan_init");
                                        return 0;
                                      }
                                      return 0;
                                    }
                                    if (_g_dbg_log_level < 2) goto LAB_ram_000337d0;
                                    pcVar9 = 
                                    "%s: ERROR - Failed to initialize 802.11 (ieee80211com)\n";
                                  }
                                  else {
                                    if (_g_dbg_log_level < 2) goto LAB_ram_000337d0;
                                    pcVar9 = "%s: ERROR - Failed to set AC rates VHT80\n";
                                  }
                                }
                                else {
                                  if (_g_dbg_log_level < 2) goto LAB_ram_000337d0;
                                  pcVar9 = "%s: ERROR - Failed to set AC rates VHT40\n";
                                }
                              }
                              else {
                                if (_g_dbg_log_level < 2) goto LAB_ram_000337d0;
                                pcVar9 = "%s: ERROR - Failed to set AC rates VHT20\n";
                              }
                            }
                            else {
                              if (_g_dbg_log_level < 2) goto LAB_ram_000337d0;
                              pcVar9 = "%s: ERROR - Failed to set NA rates\n";
                            }
                          }
                          else {
                            if (_g_dbg_log_level < 2) goto LAB_ram_000337d0;
                            pcVar9 = "%s: ERROR - Failed to set NG rates\n";
                          }
                        }
                        else {
                          if (_g_dbg_log_level < 2) goto LAB_ram_000337d0;
                          pcVar9 = "%s: ERROR - Failed to set G rates\n";
                        }
                      }
                      else {
                        if (_g_dbg_log_level < 2) goto LAB_ram_000337d0;
                        pcVar9 = "%s: ERROR - Failed to set B rates\n";
                      }
                    }
                    else {
                      if (_g_dbg_log_level < 2) goto LAB_ram_000337d0;
                      pcVar9 = "%s: ERROR - Failed to set A rates\n";
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  (*(code *)&printk)(pcVar9,"qdrv_wlan_init");
LAB_ram_000337d0:
  if ((((_g_dbg_log_module & 1) != 0) && (9 < _g_dbg_log_level)) && ((_g_dbg_log_func & 1) != 0)) {
    (*(code *)&printk)("%s: <--Exit\n","qdrv_wlan_init");
  }
  return 0xffffffff;
}

