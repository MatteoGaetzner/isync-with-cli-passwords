/*
 * mbsync - mailbox synchronizer
 * Copyright (C) 2000-2002 Michael R. Elkins <me@mutt.org>
 * Copyright (C) 2002-2006,2010-2012 Oswald Buddenhagen <ossi@users.sf.net>
 * Copyright (C) 2022-2022 Matteo Gätzner <m.gaetzner@gmx.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, mbsync may be linked with the OpenSSL library,
 * despite that library's more restrictive license.
 */

#ifndef CONFIG_H
#define CONFIG_H

#include "common.h"

typedef struct {
    const char* file;
    FILE* fp;
    char* buf;
    int bufl;
    int line;
    int err;
    int ms_warn;
    char *cmd, *val, *rest;
} conffile_t;

#define ARG_OPTIONAL 0
#define ARG_REQUIRED 1

extern unsigned int n_stdin_creds;

#define MAX_EMAIL_LEN 254
#define MAX_PW_LEN 128
#define MAX_LINE_LEN (MAX_EMAIL_LEN + 1 + MAX_PW_LEN)
#define MAX_N_CREDENTIALS 1024

typedef struct _credentials {
    char email[MAX_EMAIL_LEN];
    char password[MAX_PW_LEN];
} credentials;

extern credentials creds[MAX_N_CREDENTIALS];

char* get_arg(conffile_t* cfile, int required, int* comment);

char parse_bool(conffile_t* cfile);
int parse_int(conffile_t* cfile);
uint parse_size(conffile_t* cfile);
int getcline(conffile_t* cfile);
int merge_ops(int cops, int ops[]);
int load_config(const char* filename);

#endif
