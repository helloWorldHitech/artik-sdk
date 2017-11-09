/*
 *
 * Copyright 2017 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 */

#ifndef INCLUDE_ARTIK_SSL_H_
#define INCLUDE_ARTIK_SSL_H_

#include "artik_security.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \file artik_ssl.h
 *
 *  \brief SSL/TLS related definitions
 *
 *  Definitions for passing SSL/TLS parameters
 *  to various connectivity modules.
 *
 */

/*!
 *  \brief SSL verification strategy
 *
 *  Type for specifying the SSL server certificate
 *  verification strategy
 */
typedef enum {
	ARTIK_SSL_VERIFY_NONE,
	ARTIK_SSL_VERIFY_OPTIONAL,
	ARTIK_SSL_VERIFY_REQUIRED
} artik_ssl_verify_t;

/*!
 *  \brief SSL certificate structure
 *
 *  Structure containing a SSL certificate
 */
typedef struct {
	/*!
	 *  \brief Pointer to the certificate's data
	 */
	char *data;
	/*!
	 *  \brief Length in bytes of the certificate's data
	 */
	unsigned int len;
} artik_ssl_certificate;

/*!
 *  \brief SSL key structure
 *
 *  Structure containing a public or private key
 */
typedef struct {
	/*!
	 *  \brief Pointer to the key's data
	 */
	char *data;
	/*!
	 *  \brief Length in bytes of the key's data
	 */
	unsigned int len;
} artik_ssl_key;


/*!
 * \brief Secure Element configuration
 *
 * Structure containing the Secure Element configuration.
 */
typedef struct {
	/*!
	 *  \brief If true, use certificate and key stored in the Secure
	 *         Element for SSL handshake.
	 */
	bool use_se;

	/*!
	 *  \brief The selected certificate for the SSL handshake.
	 */
	artik_security_certificate_id certificate_id;
} artik_ssl_se_config;

/*!
 *  \brief SSL configuration structure
 *
 *  Structure containing SSL configuration
 *  for secure requests
 */
typedef struct {
	/*!
	 *  \brief Secure Element configuration
	 */
	artik_ssl_se_config se_config;
	/*!
	 *  \brief If certificate's data is non-null, use it as trusted root CA
	 *         for verifying the server's certificate
	 */
	artik_ssl_certificate ca_cert;
	/*!
	 *  \brief If certificate's data is non-null, use it as the client
	 *         certificate to send to the server during SSL
	 *         handshake
	 */
	artik_ssl_certificate client_cert;
	/*!
	 *  \brief If key's data is non-null, use it as the client
	 *         private key to send to the server during SSL
	 *         handshake
	 */
	artik_ssl_key client_key;
	/*!
	 *  \brief Select the level of verification of the server certificate
	 *         authenticity via trusted root CA.
	 */
	artik_ssl_verify_t verify_cert;
} artik_ssl_config;

#ifdef __cplusplus
}
#endif
#endif				/* INCLUDE_ARTIK_SSL_H_ */
