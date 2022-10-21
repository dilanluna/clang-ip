#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define OCTETS 4

union ip_addr {
  uint8_t octs[OCTETS];
  uint32_t decm;
};

uint32_t str_ip_to_decm(char *);

void decm_ip_to_str(uint32_t, char *);

uint32_t net_ip(uint32_t, uint32_t);

uint32_t brdcst_ip(uint32_t, uint32_t);

int main() {
  char str_net[16];
  char str_brdcst[16];
  char str_host[16] = "192.168.1.1";
  char str_mask[16] = "255.255.255.0";
  
  uint32_t decm_host = str_ip_to_decm(str_host);
  uint32_t decm_mask = str_ip_to_decm(str_mask);
  uint32_t decm_net = net_ip(decm_host, decm_mask);
  uint32_t decm_brdcst = brdcst_ip(decm_host, decm_mask);
  
  decm_ip_to_str(decm_net, str_net);
  decm_ip_to_str(decm_brdcst, str_brdcst);
  printf("Network IP: %s\n", str_net);
  printf("Broadcast IP: %s\n", str_brdcst);

  return 0;
}

uint32_t str_ip_to_decm(char *str_ip) {
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

void decm_ip_to_str(uint32_t decm_ip, char *str_ip) {
  union ip_addr ip;

  memset(&ip, 0, sizeof(union ip_addr));

  ip.decm = decm_ip;
  sprintf(str_ip, "%u.%u.%u.%u", ip.octs[3], ip.octs[2], ip.octs[1], ip.octs[0]);
}

uint32_t net_ip(uint32_t decm_host, uint32_t decm_mask) {
  return decm_host & decm_mask;
}

uint32_t brdcst_ip(uint32_t decm_host, uint32_t decm_mask) {
	uint32_t decm_brdcst_mask = ~decm_mask;
	return decm_host | decm_brdcst_mask;
}
