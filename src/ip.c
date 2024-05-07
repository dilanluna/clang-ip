#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/ip.h"

ip_t str_to_ip(strip_t str_ip) {
  char *token;
  union ip_addr ip;
  int oct = OCTETS;

  memset(&ip, 0, sizeof(union ip_addr));

  token = strtok(str_ip, ".");
  ip.octs[--oct] = atoi(token);

  while (oct > 0) {
    token = strtok(NULL, ".");
    ip.octs[--oct] = atoi(token);
  }

  return ip.decm;
}

void ip_to_str(ip_t trg_ip, strip_t str_ip) {
  union ip_addr ip;

  memset(&ip, 0, sizeof(union ip_addr));

  ip.decm = trg_ip;
  sprintf(str_ip, "%u.%u.%u.%u", ip.octs[3], ip.octs[2], ip.octs[1], ip.octs[0]);
}

ip_t get_net_ip(ip_t host_ip, ip_t mask_ip) {
  return host_ip & mask_ip;
}

ip_t get_brdcst_ip(ip_t host_ip, ip_t mask_ip) {
	ip_t brdcst_mask_ip = ~mask_ip;
	return host_ip | brdcst_mask_ip;
}

