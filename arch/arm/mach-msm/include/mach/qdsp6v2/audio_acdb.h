/* Copyright (c) 2010-2011, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef _AUDIO_ACDB_H
#define _AUDIO_ACDB_H

#include <linux/msm_audio_acdb.h>
#include <sound/q6adm.h>

#define NUM_AUDPROC_BUFFERS	6

struct acdb_cal_block {
	uint32_t		cal_size;
	uint32_t		cal_kvaddr;
	uint32_t		cal_paddr;
};

struct acdb_cal_data {
	uint32_t		num_cal_blocks;
	struct acdb_cal_block	*cal_blocks;
};

struct audproc_buffer_data {
	uint32_t	buf_size[NUM_AUDPROC_BUFFERS];
	uint32_t	phys_addr[NUM_AUDPROC_BUFFERS];
};


uint32_t get_voice_rx_topology(void);
uint32_t get_voice_tx_topology(void);
uint32_t get_adm_topology(void);
uint32_t get_asm_topology(void);
void get_all_voice_cal(struct acdb_cal_block *cal_block);
void get_all_cvp_cal(struct acdb_cal_block *cal_block);
void get_all_vocproc_cal(struct acdb_cal_block *cal_block);
void get_all_vocstrm_cal(struct acdb_cal_block *cal_block);
void get_all_vocvol_cal(struct acdb_cal_block *cal_block);
void get_anc_cal(struct acdb_cal_block *cal_block);
void get_audproc_buffer_data(struct audproc_buffer_data *cal_buffers);
void get_audproc_cal(int32_t path, struct acdb_cal_block *cal_block);
void get_audstrm_cal(int32_t path, struct acdb_cal_block *cal_block);
void get_audvol_cal(int32_t path, struct acdb_cal_block *cal_block);
void get_vocproc_cal(struct acdb_cal_data *cal_data);
void get_vocstrm_cal(struct acdb_cal_data *cal_data);
void get_vocvol_cal(struct acdb_cal_data *cal_data);
void get_sidetone_cal(struct sidetone_cal *cal_data);

#endif