#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
  strip_t str_net;
  strip_t str_brdcst;
  strip_t str_host = "192.168.1.1";
  strip_t str_mask = "255.255.255.0";
  
  ip_t host_ip = str_to_ip(str_host);
  ip_t mask_ip = str_to_ip(str_mask);
  ip_t net_ip = get_net_ip(host_ip, mask_ip);
  ip_t brdcst_ip = get_brdcst_ip(host_ip, mask_ip);
  
  ip_to_str(net_ip, str_net);
  ip_to_str(brdcst_ip, str_brdcst);
  printf("Network IP: %s\n", str_net);
  printf("Broadcast IP: %s\n", str_brdcst);

  return 0;
}

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
