/* -*- Mode: C; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 * -*- */

/* coap_list.c -- CoAP list structures
 *
 * Copyright (C) 2010,2011,2015 Olaf Bergmann <bergmann@tzi.org>
 *
 * This file is part of the CoAP library libcoap. Please see README for terms of
 * use.
 */

/* #include "coap_config.h" */

#include <stdio.h>
#include <string.h>

#include <coap/libcoap.h>
#include <coap/debug.h>
#include <coap/mem.h>
#include "coap_list.h"

#include <artik_log.h>

int coap_insert(coap_list_t **head, coap_list_t *node)
{
	if (!node)
		log_dbg("cannot create option\n");
	else
		LL_APPEND((*head), node);

	return node != NULL;
}

int coap_delete(coap_list_t *node)
{
	if (node)
		coap_free(node);
	return 1;
}

void coap_delete_list(coap_list_t *queue)
{
	coap_list_t *elt, *tmp;

	if (!queue)
		return;

	LL_FOREACH_SAFE(queue, elt, tmp) {
		coap_delete(elt);
	}
}

