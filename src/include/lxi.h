/*
 * Copyright (c) 2016-2017, Martin Lund
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holders nor contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT
 * HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef LXI_H
#define LXI_H

#ifdef __cplusplus
extern "C" {
#endif

#define LXI_OK     0
#define LXI_ERROR -1

typedef struct
{
    void (*broadcast)(char *address, char *interface);
    void (*device)(char *address, char *id);
    void (*service)(char *address, char *id, char *service, int port);
} lxi_info_t;

typedef enum
{
    VXI11,
    RAW,
    HISLIP
} lxi_protocol_t;

typedef enum
{
    DISCOVER_VXI11,
    DISCOVER_MDNS
} lxi_discover_t;

int lxi_init(void);
int lxi_discover(lxi_info_t *info, int timeout, lxi_discover_t type);
int lxi_connect(char *address, int port, char *name, int timeout, lxi_protocol_t protocol);
int lxi_send(int device, char *message, int length, int timeout);
int lxi_receive(int device, char *message, int length, int timeout);
int lxi_disconnect(int device);

#ifdef __cplusplus
}
#endif

#endif
