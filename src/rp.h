#ifndef FIDO_RP_H
#define FIDO_RP_H

#include "types.h"
#include <openssl/ssl.h>

struct fido_data *get_rp_fido_data(SSL *ssl, void *parse_arg);

int process_indication(const u8 *in, size_t in_len, struct fido_data *data);

struct authdata *parse_authdata(const u8 *data, size_t data_len);

int create_auth_request(struct fido_data *data, const u8 **out,
                        size_t *out_len);

int create_pre_reg_request(struct fido_data *data, const u8 **out,
                           size_t *out_len);

int create_reg_request(struct fido_data *data, const u8 **out, size_t *out_len);

int process_reg_indication(struct fido_data *data, struct reg_indication *in);

int process_auth_response(const u8 *in, size_t in_len, struct fido_data *data);

int process_pre_reg_response(const u8 *in, size_t in_len,
                             struct fido_data *data);

int process_reg_response(const u8 *in, size_t in_len, struct fido_data *data);

int verify_authentication_response(struct fido_data *data);

PublicKey *parse_cose_key(const u8 *in, size_t in_len);

#endif // FIDO_RP_H
