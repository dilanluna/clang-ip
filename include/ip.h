#include <stdint.h>

#ifndef IP_H
#define IP_H

#define OCTETS 4

union ip_addr {
  uint8_t octs[OCTETS];
  uint32_t decm;
};

typedef uint32_t ip_t;

typedef char strip_t[16];

ip_t str_to_ip(strip_t);

void ip_to_str(ip_t, strip_t);

ip_t get_net_ip(ip_t, ip_t);

ip_t get_brdcst_ip(ip_t, ip_t);

#endif

